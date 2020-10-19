/*
 * debounce.h
 *
 *  Created on: Oct 19, 2020
 *      Author: thomas
 */

#ifndef DEBOUNCE_H_
#define DEBOUNCE_H_

#include "types.h"

#define DEBOUNCE_DURATION 20 // milliseconds

typedef enum
{
    LOW,
    LOW_HIGH_TRANSITION,
    HIGH,
    HIGH_LOW_TRANSITION
} DebounceStates;

typedef struct debounceFSM
{
    DebounceStates state;
    unsigned char current;
    unsigned char prev;
} DebounceFSM;

void next_state(unsigned char buttons, bool source_is_timer);
unsigned char get_debounced_buttons();

#endif /* DEBOUNCE_H_ */
