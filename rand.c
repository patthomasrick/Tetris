/*
 * Professional MultiSwimmers
 * ECE 4440
 * 
 * rand.c
 * 
 * Author: Patrick Thomas
 */

#include "rand.h"

extern unsigned int __seed;

unsigned int rand()
{
    __seed = 12345 + 1103515245 * __seed;
    return __seed;
}

void srand(unsigned int seed)
{
    __seed = seed;
}
