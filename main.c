#include "msp.h"
#include "init.h"


/**
 * main.c
 */
void main(void)
{
    /* System initializing code */
	StopWatchdogTimer();
	ConfigureButtonsAsInput();
	EnablePinsAsOutputs();
	DivideSMCLK();

}
