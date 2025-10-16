#include "max30102.h"
#include <math.h>

// Private function prototypes for the algorithm
static void max30102_write_reg(max30102_t *max, uint8_t reg, uint8_t value);
static void max30102_read_regs(max30102_t *max, uint8_t reg, uint8_t *buffer, uint8_t count);
static void maxim_heart_rate_and_oxygen_saturation(uint32_t *pun_ir_buffer, int32_t n_ir_buffer_length, uint32_t *pun_red_buffer, float *pn_spo2, int8_t *pch_spo2_valid, int32_t *pn_heart_rate, int8_t *pch_hr_valid);


void max30102_init(max30102_t *max, I2C_HandleTypeDef *i2c_handle) {
    max->i2c_handle = i2c_handle;
    max->buffer_head = 0;
    max->buffer_tail = 0;
    max->pulse_detected = 0;

    max30102_write_reg(max, 0x09, 0x0F); // FiFo configuration
    max30102_write_reg(max, 0x0C, 0x27); // LED Pulse Amplitude
    max30102_write_reg(max, 0x0A, 0x27); // SpO2 configuration
    max30102_write_reg(max, 0x08, 0x03); // Mode configuration
}

void max30102_read_fifo(max30102_t *max) {
    uint8_t buffer[6];
    max30102_read_regs(max, 0x07, buffer, 6);
    uint32_t ir_sample = ((uint32_t)buffer[0] << 16) | ((uint32_t)buffer[1] << 8) | buffer[2];
    uint32_t red_sample = ((uint32_t)buffer[3] << 16) | ((uint32_t)buffer[4] << 8) | buffer[5];

    max->ir_buffer[max->buffer_head] = ir_sample;
    max->red_buffer[max->buffer_head] = red_sample;
    max->buffer_head = (max->buffer_head + 1) % 500;
}

void max30102_update(max30102_t *max) {
    int32_t heart_rate;
    float spo2;
    int8_t hr_valid, spo2_valid;

    // A simple implementation: Process the last 100 samples
    maxim_heart_rate_and_oxygen_saturation(max->ir_buffer, 100, max->red_buffer, &spo2, &spo2_valid, &heart_rate, &hr_valid);

    if(hr_valid) {
        max->heart_rate = heart_rate;
        max->pulse_detected = 1;
    }
    if(spo2_valid) {
        max->spO2 = spo2;
    }
}

// Helper functions for I2C communication
static void max30102_write_reg(max30102_t *max, uint8_t reg, uint8_t value) {
    uint8_t data[2] = {reg, value};
    HAL_I2C_Master_Transmit(max->i2c_handle, MAX30102_ADDRESS, data, 2, HAL_MAX_DELAY);
}

static void max30102_read_regs(max30102_t *max, uint8_t reg, uint8_t *buffer, uint8_t count) {
    HAL_I2C_Master_Transmit(max->i2c_handle, MAX30102_ADDRESS, &reg, 1, HAL_MAX_DELAY);
    HAL_I2C_Master_Receive(max->i2c_handle, MAX30102_ADDRESS, buffer, count, HAL_MAX_DELAY);
}

// Placeholder for the complex algorithm from the library
void maxim_heart_rate_and_oxygen_saturation(uint32_t *pun_ir_buffer, int32_t n_ir_buffer_length, uint32_t *pun_red_buffer, float *pn_spo2, int8_t *pch_spo2_valid, int32_t *pn_heart_rate, int8_t *pch_hr_valid)
{
    // Dummy implementation for compilation.
    // The full algorithm is very large and complex.
    // For a real application, you would include the full algorithm source.
    *pn_heart_rate = 80 + (rand() % 10);
    *pn_spo2 = 97.0 + (rand() % 2);
    *pch_hr_valid = 1;
    *pch_spo2_valid = 1;
}
