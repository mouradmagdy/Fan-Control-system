/*
 * fan_control_system.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Mourad
 */

#include"std_types.h"
#include"lcd.h"
#include"dc_motor.h"
#include"adc.h"
#include"lm35_sensor.h"
#include<avr/io.h>


int main(void){
	ADC_ConfigType adc={Internal_REF,F_CPU_8};
	SREG|=(1<<7);
	ADC_init(&adc);

	LCD_init();

	DcMotor_init();
	LCD_displayString("  Fan is  ");
	LCD_displayStringRowColumn(1,2,"Temp =    C");

	uint8 temperature_value=0;

	while(1){
		temperature_value=LM35_getTemperature();

		if(temperature_value<30){
			LCD_displayStringRowColumn(0,10,"OFF");
			LCD_moveCursor(1,8);
			LCD_intgerToString(temperature_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(STOP,0);
		}
		else if(temperature_value>=30&&temperature_value<60){
			LCD_displayStringRowColumn(0,10,"ON");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,8);
			LCD_intgerToString(temperature_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,25);
		}
		else if(temperature_value>=60&&temperature_value<90){
			LCD_displayStringRowColumn(0,10,"ON");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,8);
			LCD_intgerToString(temperature_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,50);
		}
		else if(temperature_value>=90&&temperature_value<120){
			LCD_displayStringRowColumn(0,10,"ON");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,8);
			LCD_intgerToString(temperature_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);
		}
		else if(temperature_value>=120){
			LCD_displayStringRowColumn(0,10,"ON");
			LCD_displayCharacter(' ');

			LCD_moveCursor(1,8);
			LCD_intgerToString(temperature_value);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,100);
		}
	}

}
