#include "fsm_automatic.h"

int time_red = 5;
int time_yellow = 2; // red = green + yellow
int time_green = 3;

int status1 =INIT;
int status2 =INIT;
int count1 =0;
int count2 =0;


//timer 0 blink led
//timer 1 Dem den

void run_automatic(){
	switch(status1){
				case INIT:{
						ResetLight1();
						setTimer(1,time_red *1000);
						status1 = RED_LED_AUTO;
						count1 = time_red;
						timer_flag[0]=1; //counter 1s
						timer_flag[4]=1; //counter seg7
						break;
					}
				case RED_LED_AUTO:{
						RedLight1();
						if (timer_flag[1]==1){
							setTimer(1,time_green *1000);
							status1 = GREEN_LED_AUTO;
							count1 = time_green;
						}
						if (isButtonPressed(modify_button)==1){
							status1 = RED_GREEN_MAN;
							status2 = RED_LED_SET;
							setTimer(1, 10000); //10 giây không nhấn
							count1 = 10;
						}
						if (isButtonPressed(mode_button)==1){
							setTimer(1, 1000);
							status1 = RED_LED_SET;
							status2 = RED_LED_SET;
							count1 = 2; //Mode
							count2 = time_red; //Value
							ResetLight1();
							ResetLight2();
						}
						break;
					}
				case YELLOW_LED_AUTO:{
						YellowLight1();
						if (timer_flag[1]==1){
							setTimer(1,time_red *1000);
							status1 = RED_LED_AUTO;
							count1 = time_red;
						}
						break;
					}
				case GREEN_LED_AUTO:{
						GreenLight1();
						if (timer_flag[1]==1)	{
							setTimer(1,time_yellow *1000);
							status1 = YELLOW_LED_AUTO;
							count1 = time_yellow;
						}
						break;
					}
				default:
						break;
			}

		switch(status2){
					case INIT:{
							ResetLight2();
							status2 = GREEN_LED_AUTO;
							count2 = time_green;
							setTimer(2,time_green *1000);
							break;
						}
					case RED_LED_AUTO:{
							RedLight2();
							if (timer_flag[2]==1){
								setTimer(2,time_green *1000);
								status2 = GREEN_LED_AUTO;
								count2 = time_green;
							}
							break;
						}
					case YELLOW_LED_AUTO:{
							YellowLight2();
							if (timer_flag[2]==1){
								setTimer(2,time_red *1000);
								status2 = RED_LED_AUTO;
								count2 = time_red;
							}
							break;
						}
					case GREEN_LED_AUTO:{
							GreenLight2();
							if (timer_flag[2]==1)	{
								setTimer(2,time_yellow *1000);
								status2 = YELLOW_LED_AUTO;
								count2 = time_yellow;
							}
							break;
						}
					default:
							break;
				}

	if(timer_flag[0]==1){
		setTimer(0, 1000);
		HAL_GPIO_TogglePin(GPIOA, LED_PINK);
		if((status1/30)!=1)count1--;
		if((status2/30)!=1)count2--;

		led_buffer[0]=count1/10;
		led_buffer[1]=count1%10;
		led_buffer[2]=count2/10;
		led_buffer[3]=count2%10;
	}

	if(timer_flag[4]==1){
		setTimer(4,125);
		update7SEG (index_led++);
		if(index_led == MAX_LED){index_led=0;}
	}
}

