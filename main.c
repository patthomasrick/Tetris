/*
 * Professional MultiSwimmers
 * ECE 4440
 * 
 * main.c
 * 
 * Author: Arjun, Nick, Daniel, Patrick
 */

#include "debounce.h"
#include "init.h"
#include "msp.h"
#include "tetris.h"
#include "timer.h"

/**
 * tetris contains all of the game logic and game state for the Tetris game.
 */
static Tetris tetris;

/**
 * main.c
 */
void main(void)
{
    /* System initializing code */
    StopWatchdogTimer();
    ConfigureButtonsAsInput();
    EnablePinsAsOutput();
    DivideSMCLK();

    /* Initialize Timer */
    ConfigureTimer(0xffff);

    /* Initialize game logic */
    tetris_init(&tetris);
    tetris_spawn_piece(&tetris);

    /* Enable global interrupts */
    __enable_irq();
    StartTimer();

    while (1)
    {
        __no_operation();
    }
}

/*Timer A0 ISR*/
void TA0_0_IRQHandler(void)
{
    if (!tetris.end_game)
    {
        tetris_visualize(&tetris);
    }
}

/*PORT 6 (buttons) ISR  */
void PORT6_IRQHandler(void)
{
    // Read all of Port 6.
    next_state(P6OUT, false);
}

/*Timer A1 ISR*/
void TA1_0_IRQHandler(void)
{
    // TODO: Configure timer for TA1 for debounce.
    unsigned char buttons = get_debounced_buttons();

    if (buttons & ROTATE_MASK)
    {
        piece_rotate(tetris_queue_get(&tetris), &tetris);
    }
    else if (buttons & DOWN_MASK)
    {
        // TODO: Does this need to be in a while loop?
        // while (tetris_shift_down(&tetris));
        tetris_shift_down(&tetris);
    }
    else if (buttons & LEFT_MASK)
    {
        tetris_move_left(&tetris);
    }
    else if (buttons & RIGHT_MASK)
    {
        tetris_move_right(&tetris);
    }
}
