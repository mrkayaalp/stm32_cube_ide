#include "bno055_lib.h"

bno055_vector euler_deg;
uint8_t buffer[6];

// pg 29
const uint8_t GyroPowerMode = NormalG;
const uint8_t GyroRange = GFS_1000DPS;
const uint8_t GyroBandwith = GBW_523Hz;

// pg 28
const uint8_t AccelRange = AFS_8G;
const uint8_t AccelMode = NormalA;
const uint8_t AccelBandwith = ABW_1000Hz;

// pg21
const uint8_t PWRMode = Normalpwr;
const uint8_t OPRMode = IMU;

void _setPage(uint8_t page)
{
    bno055_i2c_write_data(BNO055_PAGE_ID, page);
    HAL_Delay(30);
}

void read_bno055_data(uint8_t reg)
{
    HAL_I2C_Mem_Read(&hi2c1, BNO055_I2C_ADDR_LO << 1, reg, 1, &buffer, 6, 100);
    euler_deg.yaw = (int16_t)(buffer[1] << 8 | buffer[0]) / 16.0;
    euler_deg.roll = (int16_t)(buffer[3] << 8 | buffer[2]) / 16.0;
    euler_deg.pitch = (int16_t)(buffer[5] << 8 | buffer[4]) / 16.0;
}

void bno055_i2c_write_data(uint8_t reg, uint8_t data)
{
    HAL_I2C_Mem_Write(&hi2c1, BNO055_I2C_ADDR_LO << 1, reg, 1, &data, 1, 100);
}

void bno055_i2c_read_data(uint8_t reg, uint8_t *data)
{
    HAL_I2C_Mem_Read(&hi2c1, BNO055_I2C_ADDR_LO << 1, reg, 1, data, 1, 100);
}

void bno055_config(void)
{
    _setPage(1);

    uint8_t accel_config = (AccelRange << 0) | (AccelBandwith << 2) | (AccelMode << 5);
    bno055_i2c_write_data(BNO055_ACC_CONFIG, accel_config);
    HAL_Delay(30);

    uint8_t gyro_config = (GyroRange << 0) | (GyroBandwith << 3);
    bno055_i2c_write_data(BNO055_GYRO_CONFIG_0, gyro_config);
    HAL_Delay(30);

    uint8_t gyro_config2 = (GyroPowerMode << 0);
    bno055_i2c_write_data(BNO055_GYRO_CONFIG_1, gyro_config2);
    HAL_Delay(30);

    _setPage(0);
}