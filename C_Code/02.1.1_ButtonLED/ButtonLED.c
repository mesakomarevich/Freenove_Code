/**********************************************************************
* Filename    : ButtonLED.c
* Description : Controlling an led by button.
* Author      : freenove
* modification: 2016/06/12
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define ledPin    0  	//define the ledPin
#define buttonPin 1		//define the buttonPin

int main(void)
{
	//when initialize wiring failed,print messageto screen
	if (wiringPiSetup() == -1)
	{ 
		printf("setup wiringPi failed !");
		return 1;
	}

	pinMode(ledPin, OUTPUT); //Set ledPin output
	pinMode(buttonPin, INPUT);//Set buttonPin input

	pullUpDnControl(buttonPin, PUD_UP);  //pull up to high level

	while (1)
	{
		//button has pressed down
		if (digitalRead(buttonPin) == LOW)
		{ 
			digitalWrite(ledPin, HIGH);   //led on
			printf("led on...\n");
		}
		//button has released
		else
		{				 
			digitalWrite(ledPin, LOW);   //led off
			printf("...led off\n");
		}
	}

	return 0;
}

