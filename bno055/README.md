# STM32 BNO055

- This repository contains STM32 code for reading Euler angle data from a BNO055 sensor. The code reads the BNO055's quaternion data and uses it to calculate the roll, pitch, and yaw Euler angles.

- To get started with this code, you will need an STM32 microcontroller and a BNO055 sensor. You will also need a development environment such as STM32CubeIDE.

- At first, just polling and read the data of the chip id. We read the decimal equivalent of 0xA0 hexadecimal value 160 in the live expression, and then we read the Euler angle.

- Additionally, we create our own bno055_lib .h and.c files so that we're able to manually read values.

- Finally we create our own basic BNO055 library
