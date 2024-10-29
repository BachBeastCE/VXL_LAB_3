#include "fsm_manual.h"

void run_manual(){
	switch (status1){
	case RED_GREEN_MAN:{
		RedLight1();
		GreenLight2();
		if(timer_flag[1]==1){
			count1 = time_red;
			count2 = time_green;
			status1 = RED_LED_AUTO;
			status2 = GREEN_LED_AUTO;
			timer_flag[0]=1; //counter 1s
			setTimer(1, time_red*1000);
			setTimer(2, time_green*1000);
		}
		if(isButtonPressed(0)==1){
			status1= RED_YELLOW_MAN;
			count1 = 10;
			count2 = 1;
			setTimer(1, 10000); // 10 giây không nhấn
		}
		break;
	}
	case RED_YELLOW_MAN:{
		RedLight1();
		YellowLight2();
		if(timer_flag[1]==1){
			count1 = time_red;
			count2 = time_yellow;
			status1 = RED_LED_AUTO;
			status2 = YELLOW_LED_AUTO;
			timer_flag[0]=1; //counter 1s
			setTimer(1, time_red*1000);
			setTimer(2, time_yellow*1000);
		}
		if(isButtonPressed(0)==1){
			status1= GREEN_RED_MAN;
			count1 = 10;
			count2 = 1;
			setTimer(1, 10000); // 10 giây không nhấn
		}
		break;
	}
	case GREEN_RED_MAN:{
		GreenLight1();
		RedLight2();
		if(timer_flag[1]==1){
			count1 = time_green;
			count2 = time_red;
			status1 = GREEN_LED_AUTO;
			status2 = RED_LED_AUTO;
			timer_flag[0]=1; //counter 1s
			setTimer(1, time_green*1000);
			setTimer(2, time_red*1000);
		}
		if(isButtonPressed(0)==1){
			status1= YELLOW_RED_MAN;
			count1 = 10;
			count2 = 1;
			setTimer(1, 10000); // 10 giây không nhấn
		}
		break;
	}
	case YELLOW_RED_MAN:{
			YellowLight1();
			RedLight2();
			if(timer_flag[1]==1){
				count1 = time_yellow;
				count2 = time_red;
				status1 = YELLOW_LED_AUTO;
				status2 = RED_LED_AUTO;
				timer_flag[0]=1; //counter 1s
				setTimer(1, time_yellow*1000);
				setTimer(2, time_red*1000);
			}
			if(isButtonPressed(0)==1){
				status1= RED_GREEN_MAN;
				count1 = 10;
				count2 = 1;
				setTimer(1, 10000); // 10 giây không nhấn
			}
			break;

	}
	default:
		break;
	}
}
