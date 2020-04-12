/**********************************************************************
* Filename    : Blink.c
* Description : Make an led blinking.
* auther      : www.freenove.com
* modification: 2016/06/07
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define  ledPin    0

int main(void)
{
	//when initialize wiring failed,print message to screen
	if (wiringPiSetup() == -1)
	{
		printf("setup wiringPi failed !");
		return 1;
	}

	//when initialize wiring successfully,print message to screen	
	printf("wiringPi initialize successfully, GPIO %d(wiringPi pin)\n", ledPin);

	pinMode(ledPin, OUTPUT);//Set the pin mode

	for(int i = 0; i < 10; i++)
	{
		digitalWrite(ledPin, HIGH);  //led on
		printf("led on...\n");
		delay(1000);
		digitalWrite(ledPin, LOW);  //led off
		printf("...led off\n");
		delay(1000);
	}

	digitalWrite(ledPin, LOW);  //led off

	return 0;
}

