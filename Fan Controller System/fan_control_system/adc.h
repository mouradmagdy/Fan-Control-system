/*
 * adc.h
 *
 *  Created on: Feb 24, 2024
 *      Author: Mourad
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"

/* to be used in the sensor driver not ADC driver*/
#define ADC_MAXIMUM_VALUE 1024
#define ADC_REF_VOLT_VALUE 5

typedef enum{
	AREF, /* Internal Vref turned off*/
	AVCC, /*with external capacitor at AREF pin*/
	RESERVED,
	Internal_REF, /* 2.56V Voltage Reference with external capacitor at AREF pin*/
}ADC_ReferenceVoltage;

typedef enum{
	F_CPU_2 = 1,
	F_CPU_4,
	F_CPU_8,
	F_CPU_16,
	F_CPU_32,
	F_CPU_64,
	F_CPU_128,

}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType*config_ptr);

uint16 ADC_readChannel(uint8 channel_num);



#endif /* ADC_H_ */
