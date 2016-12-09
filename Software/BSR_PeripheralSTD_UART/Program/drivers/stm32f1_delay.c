/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f1_system.h"
#include "stm32f1_delay.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
static __IO uint32_t uwTick;
/*=====================================================================================================*/
/*=====================================================================================================*/
void HAL_InitTick( void )
{
  NVIC_InitTypeDef NVIC_InitStruct;

  if(SysTick_Config(SystemCoreClock / 1000))
    while(1);

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
  NVIC_InitStruct.NVIC_IRQChannel = (uint8_t)SysTick_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x000F;
  NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct);
}
void HAL_IncTick( void )
{
  uwTick++;
}
uint32_t HAL_GetTick( void )
{
  return uwTick;
}
void HAL_Delay( __IO uint32_t Delay )
{
  uint32_t tickstart = 0;
  tickstart = HAL_GetTick();
  while((HAL_GetTick() - tickstart) < Delay)
  {
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : delay_us
**功能 : Delay us
**輸入 : vCnt_us
**輸出 : None
**使用 : delay_us(times);
**=====================================================================================================*/
/*=====================================================================================================*/
void delay_us( __IO uint32_t vCnt_us )
{
  __IO uint32_t vCnt;
  while(vCnt_us--)
    for(vCnt = 7; vCnt != 0; vCnt--);
}
/*=====================================================================================================*/
/*=====================================================================================================*/