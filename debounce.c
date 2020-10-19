/*
 * debounce.c
 *
 *  Created on: Oct 19, 2020
 *      Author: thomas
 */

#include "debounce.h"
#include "msp.h"
#include "types.h"

static DebounceFSM fsm = {LOW, 0x00, 0x00};

void next_state(unsigned char buttons, bool source_is_timer)
{
    switch (fsm.state)
    {
    case LOW:
        fsm.state = LOW_HIGH_TRANSITION;
        break;
    case LOW_HIGH_TRANSITION:
        if (source_is_timer)
        {
            fsm.state = HIGH;
            fsm.prev = fsm.current;
            fsm.current = buttons;
        }
        break;
    case HIGH:
        fsm.state = HIGH_LOW_TRANSITION;
        break;
    case HIGH_LOW_TRANSITION:
        if (source_is_timer)
        {
            fsm.state = LOW;
            fsm.prev = fsm.current;
            fsm.current = buttons;
        }
        break;
    default:
        break;
    }
}

unsigned char get_debounced_buttons()
{
    return fsm.current;
}
