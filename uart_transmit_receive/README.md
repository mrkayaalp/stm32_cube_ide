In interrupt mode, Reception takes place in non-blocking mode or in the background.

So, the rest of the processes works as they should and when the data Reception is complete, a Rx Complete Callback is called.

In order to enable the Interrupt in CubeMX, we just need to modify our previous setup.

All we need to do is enable the interrupt in the Interrupt TAB under the UART.

In the code, HAL_UART_RxCpltCallback will be called when the data reception is complete.

This will result in continuous reception of data and the rate of blinking will also remain constant as the data transfer takes place in non-blocking mode or in the background.
