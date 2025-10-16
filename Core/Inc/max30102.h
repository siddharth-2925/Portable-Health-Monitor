#ifndef MAX30102_H_
#define MAX30102_H_

#include "main.h"

// I2C address of the sensor
#define MAX30102_ADDRESS 0xAE

// Struct to hold sensor data and configuration
typedef struct {
    I2C_HandleTypeDef *i2c_handle;
    uint32_t ir_buffer[500];
    uint32_t red_buffer[500];
    uint8_t buffer_head;
    uint8_t buffer_tail;
    uint8_t samples_recorded;
    float heart_rate;
    float spO2;
    uint8_t pulse_detected;
} max30102_t;

// Public function prototypes
void max30102_init(max30102_t *max, I2C_HandleTypeDef *i2c_handle);
void max30102_read_fifo(max30102_t *max);
void max30102_update(max30102_t *max);

#endif /* MAX30102_H_ */
