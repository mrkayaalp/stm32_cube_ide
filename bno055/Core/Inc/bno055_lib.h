#ifndef __BNO055_H_
#define __BNO055_H_
#include "main.h"
#include "stdint.h"
#include "i2c.h"

#define BNO055_ACC_CONFIG       0x08
#define BNO055_MAG_CONFIG       0x09
#define BNO055_GYRO_CONFIG_0    0x0A
#define BNO055_GYRO_CONFIG_1    0x0B
#define BNO055_PAGE_ID          0x07

#define EUL_REG 0x1A
#define BNO055_I2C_ADDR_LO 0x28

// Accelometer Config pg27
enum AccelScale
{ // ACC Range
    AFS_2G = 0,
    AFS_4G,
    AFS_8G,
    AFS_16G
};
enum AccelBandwidth
{ // ACC Bandwidth
    ABW_7_81Hz = 0,
    ABW_15_63Hz,
    ABW_31_25Hz,
    ABW_62_5Hz,
    ABW_125Hz,
    ABW_250Hz,
    ABW_500Hz,
    ABW_1000Hz, // 0x07
};
enum AccelPwrMode
{ // ACC Pwr Mode
    NormalA = 0,
    SuspendA,
    LowPower1A,
    StandbyA,
    LowPower2A,
    DeepSuspendA
};

// GYRO Config pg28
enum GyroRange
{ // gyro range
    GFS_2000DPS = 0,
    GFS_1000DPS,
    GFS_500DPS,
    GFS_250DPS,
    GFS_125DPS // 0x04
};
enum GyroMode
{ // GYR Pwr Mode
    NormalG = 0,
    FastPowerUpG,
    DeepSuspendedG,
    SuspendG,
    AdvancedPowerSaveG
};
enum GyroBandwith
{ // gyro bandwidth
    GBW_523Hz = 0,
    GBW_230Hz,
    GBW_116Hz,
    GBW_47Hz,
    GBW_23Hz,
    GBW_12Hz,
    GBW_64Hz,
    GBW_32Hz
};

enum OPRMode
{ // Oprayon modu
    CONFIGMODE = 0x00,
    // Sensor Mode
    ACCONLY,
    MAGONLY,
    GYROONLY,
    ACCMAG,
    ACCGYRO,
    MAGGYRO,
    AMG, // 0x07
         // Fusion Mode - Modlarin ve Sensorleri Otomatik ayarlandigi
    IMU,
    COMPASS,
    M4G,
    NDOF_FMC_OFF,
    NDOF // 0x0C
};

enum PowerMode
{
    Normalpwr = 0,
    Lowpower,
    Suspendpwr
};

// pg29
enum MagnnetometerOutputRate
{ // magnetometer output data rate
    MODR_2Hz = 0,
    MODR_6Hz,
    MODR_8Hz,
    MODR_10Hz,
    MODR_15Hz,
    MODR_20Hz,
    MODR_25Hz,
    MODR_30Hz
};

enum MagnetometerOperMode
{ // MAG Op Mode
    LowPower = 0,
    Regular,
    EnhancedRegular,
    HighAccuracy
};

enum MagnetometerPowerMode
{ // MAG power mode
    Normal = 0,
    Sleep,
    Suspend,
    ForceMode
};

typedef struct
{
    double roll;
    double pitch;
    double yaw;
} bno055_vector;

void bno055_i2c_write_data(uint8_t reg, uint8_t data);

void bno055_i2c_read_data(uint8_t reg, uint8_t *data);

void read_bno055_data(uint8_t reg);

void bno055_config(void);

#endif /* __BNO055_H_ */