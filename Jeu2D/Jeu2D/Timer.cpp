#include <iostream>
#include "Timer.h";

Timer* InitTimer(int secondsToWait, float dt) {
	Timer* timer = new Timer;
	timer->timerSeconds = 0;
	timer->secondsToWait = secondsToWait;
	timer->deltaTime = dt;

	return timer;
}

bool Wait(Timer& timer) {
	if (timer.timerSeconds < timer.secondsToWait) 
		timer.timerSeconds += timer.deltaTime;
	
	return timer.timerSeconds >= timer.secondsToWait;
}