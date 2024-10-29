#include "fsm_setting.h"

void run_setting(){
	switch (status1){
	case RED_LED_SET:{
		if(timer_flag[1]==1){
			setTimer(1, 1000);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_1);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_2);
		}
		if(isButtonPressed(mode_button)==1){
			status1 = YELLOW_LED_SET;
			count1 = 3;
			count2 = time_yellow;
			ResetLight1();
			ResetLight2();
		}
		if(isButtonPressed(modify_button)==1){
			count2++;
			if(count2 > 99)count2 =1;
		}
		if(isButtonPressed(choose_button)==1){
			time_red = count2;
		}
		break;
	}
	case YELLOW_LED_SET:{
		if(timer_flag[1]==1){
			setTimer(1, 1000);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_1);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_2);
		}
		if(isButtonPressed(mode_button)==1){
			status1 = GREEN_LED_SET;
			count1 = 4;
			count2 = time_green;
			ResetLight1();
			ResetLight2();
		}
		if(isButtonPressed(modify_button)==1){
			count2++;
			if(count2 > 99)count2 =1;
		}
		if(isButtonPressed(choose_button)==1){
			time_yellow = count2;
		}
		break;
	}
	case GREEN_LED_SET:{
		if(timer_flag[1]==1){
			setTimer(1, 1000);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_1);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_2);
		}
		if(isButtonPressed(mode_button)==1){
			status1 = INIT;
			status2 = INIT;
			count1 = 0;
			count2 = 0;
		}
		if(isButtonPressed(modify_button)==1 ){
			count2++;
			if(count2 > 99)count2 =1;
		}
		if(isButtonPressed(choose_button)==1){
			time_green = count2;
		}
		break;
	}
	}
}
