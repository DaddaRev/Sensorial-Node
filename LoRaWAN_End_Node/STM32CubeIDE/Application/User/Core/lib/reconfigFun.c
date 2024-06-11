
#include "reconfigFun.h"
#include "gpio.h"


/*
 * Funzione che in base al valore del parametro sceglie se impostare il GPIO come input o come output
 */
void Reconfigure_GPIO_Pins(int isOutput)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    GPIO_InitStruct.Pin = GPIO_PIN_5;

    if (isOutput)
    {
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    }
    else
    {
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        //GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;  Useless(?)
    }

    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}
