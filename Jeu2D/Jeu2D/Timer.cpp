#include <iostream>

bool Wait(float& timer, int secondsToWait,float dt) {
	if (timer < secondsToWait) 
		timer += dt;
	
	return timer >= secondsToWait;
}