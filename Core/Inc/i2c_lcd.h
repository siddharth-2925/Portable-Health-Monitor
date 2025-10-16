#ifndef I2C_LCD_H
#define I2C_LCD_H

#include "stm32f4xx_hal.h" // <<<--- Crucial include for HAL types

void lcd_init(void);
void lcd_send_cmd(char cmd);
void lcd_send_data(char data);
void lcd_send_string(char *str);
void lcd_put_cur(int row, int col);
void lcd_clear(void);

#endif /* I2C_LCD_H */
