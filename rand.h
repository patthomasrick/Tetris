/*
 * Professional MultiSwimmers
 * ECE 4440
 * 
 * rand.h
 * 
 * Author: Patrick Thomas
 */

#ifndef RAND_H_
#define RAND_H_

static unsigned int __seed = 0;

unsigned int rand();
void srand(unsigned int seed);

#endif
