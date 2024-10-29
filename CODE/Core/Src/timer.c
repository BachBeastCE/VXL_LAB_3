#include "timer.h"

int timer_flag[5]={0,0,0,0,0};
int timer_counter[5]={0,0,0,0,0};
int TIMER_CYCLE = 10; //=counter period

void setTimer(int index, int counter){
	timer_flag[index]=0;
	timer_counter[index] = counter/TIMER_CYCLE;
}
void timer_run(){
	for(int i=0;i<5;i++){
		if(timer_counter[i]>0){
			timer_counter[i]--;
			if(timer_counter[i]<=0){
				 timer_flag[i]=1;
			}
		}
	}
}

