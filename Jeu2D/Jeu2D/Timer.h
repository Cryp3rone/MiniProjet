#pragma once

struct Timer {
	float timerSeconds;
	int secondsToWait;
	float deltaTime;
};

Timer* InitTimer(int,float);
bool Wait(Timer&);