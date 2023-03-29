#ifndef __BNO055_H_
#define __BNO055_H_
#include "main.h"
#include "stdint.h"
#include "i2c.h"

#define EUL_REG 0x1A
#define BNO055_I2C_ADDR_LO 0x28


typedef struct
{
    double roll;
    double pitch;
    double yaw;
} bno055_vector;

void read_bno055_data(uint8_t reg);

#endif /* __BNO055_H_ */