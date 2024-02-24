/*
 * adc.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Mourad
 */

#include"adc.h"
#include"common_macros.h"
#include<avr/io.h>

/*description :initialize the ADC:
 * 1.choose the mood of vref
 * 2. initially choose channel 0 (pin0)
 * 3.ADC enable
 * 4.disable the interrupt as we are working with powlling
 * 5.set the prescaler of the clk */

void ADC_init(const ADC_ConfigType*config_ptr){
	ADMUX=(ADMUX&0x3F)|(config_ptr->ref_volt);
	ADMUX&=0XE0;     /* channel 0 */
	SET_BIT(ADCSRA,ADEN); /* ADC Enable */
	CLEAR_BIT(ADCSRA,ADIE); /* Disable interrupts */
	ADCSRA=(ADCSRA&0xF8)|(config_ptr->prescaler); /* set prescaler */
}


uint16 ADC_readChannel(uint8 channel_num){
	/* insert the channel, input channel must be from 0 to 7*/
	ADMUX=(ADMUX&0xE0)|(channel_num&0x07);

	/* start conversion */
	SET_BIT(ADCSRA,ADSC);

	/* polling until conversion is complete */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	return ADC;

}

