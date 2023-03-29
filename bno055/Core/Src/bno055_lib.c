#include "bno055_lib.h"

bno055_vector euler_deg;
uint8_t buffer[6];

void read_bno055_data(uint8_t reg)
{
    HAL_I2C_Mem_Read(&hi2c1, BNO055_I2C_ADDR_LO << 1, reg, 1, &buffer, 6, 100);
    euler_deg.yaw = (int16_t)(buffer[1] << 8 | buffer[0]) / 16.0;
    euler_deg.roll = (int16_t)(buffer[3] << 8 | buffer[2]) / 16.0;
    euler_deg.pitch = (int16_t)(buffer[5] << 8 | buffer[4]) / 16.0;
}
