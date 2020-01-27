#include "Arduino.h"

PinDescription g_APinDescription[] = {
  // D0 - D7
  PH_15,  NULL, NULL,     // D0
  PK_1, NULL, NULL,     // D1
  PJ_11, NULL, NULL,     // D2
  PG_7, NULL, NULL,     // D3
  PC_7, NULL, NULL,     // D4
  PC_6, NULL, NULL,     // D5
  PA_8, NULL, NULL,     // D6
  PI_0,  NULL, NULL,     // D7

  // D8 - D14
  PC_3, NULL, NULL,     // D8
  PI_2, NULL, NULL,     // D9
  PC_2,  NULL, NULL,     // D10
  PH_8,  NULL, NULL,     // D11
  PH_7,  NULL, NULL,     // D12
  PA_10, NULL, NULL,     // D13
  PA_9, NULL, NULL,     // D14

  // A0 - A7
  PA_0_C_ALT2,  NULL, NULL,    // A0       ADC2_INP0
  PA_1_C_ALT0,  NULL, NULL,    // A1       ADC2_INP1
  PC_2_C_ALT0, NULL, NULL,     // A2       ADC3_INP0
  PC_3_C, NULL, NULL,       // A3            ADC3_INP1        
  PC_2_ALT0, NULL, NULL,          // A4    ADC1_INP12
  PC_3_ALT2,  NULL, NULL,         // A5         ADC2_INP13
  PA_4, NULL, NULL,          // A6         ADC1_INP18
};

extern "C" {
  unsigned int PINCOUNT_fn() {
    return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
  }
}

void initVariant() {
  // configure analog mux to split Pxy and Pxy_C
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PA0, SYSCFG_SWITCH_PA0_OPEN);
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PA1, SYSCFG_SWITCH_PA1_OPEN);
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PC2, SYSCFG_SWITCH_PC2_OPEN);
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PC3, SYSCFG_SWITCH_PC3_OPEN);
}