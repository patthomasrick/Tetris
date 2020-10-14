#include "msp.h"
/*
 * init.h
 *
 *  Created on: Oct 13, 2020
 *      Author: Arjun
 */

#ifndef INIT_H_
#define INIT_H_

// Macros to turn various outputs on or off
#define TurnOn(port,pin)  port |= pin
#define TurnOff(port,pin) port &= ~pin

#define R1    TurnOn(P5OUT,0)
#define B1    TurnOn(P5OUT,1)
#define G1    TurnOn(P5OUT,2)
#define R2    TurnOn(P5OUT,4)
#define B2    TurnOn(P5OUT,5)
#define G2    TurnOn(P5OUT,7)

#define A     TurnOn(P4OUT,0)
#define B     TurnOn(P4OUT,1)
#define C     TurnOn(P4OUT,2)
#define D     TurnOn(P4OUT,3)

#define OE     TurnOn(P5OUT,6)
#define CLK    TurnOn(P2OUT,7)
#define Latch  TurnOn(P1OUT,6)

#define NotR1    TurnOff(P5OUT,0)
#define NotB1    TurnOff(P5OUT,1)
#define NotG1    TurnOff(P5OUT,2)
#define NotR2    TurnOff(P5OUT,4)
#define NotB2    TurnOff(P5OUT,5)
#define NotG2    TurnOff(P5OUT,7)

#define NotA     TurnOff(P4OUT,0)
#define NotB     TurnOff(P4OUT,1)
#define NotC     TurnOff(P4OUT,2)
#define NotD     TurnOff(P4OUT,3)

#define NotOE     TurnOff(P5OUT,6)
#define NotCLK    TurnOff(P2OUT,7)
#define NotLatch  TurnOff(P1OUT,6)

// Prototypes
void StopWatchdogTimer();
void ConfigureButtonsAsInput();
void EnablePinsAsOutput();
void DivideSMCLK();


#endif /* INIT_H_ */
