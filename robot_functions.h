#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iterator>
#include <map>
#include <math.h>

// ------------------------------------------------------------------------ //
//																			//
//																			//
//				Functions for robot operations								//
//																			//
//																			//
// ------------------------------------------------------------------------ //

char get_block(void);
void print_slots(char[]);
unsigned int put_block(char, unsigned int, char[]);
unsigned int remove_block(unsigned int, char[]);
unsigned int shift_right(unsigned int);
unsigned int shift_left(unsigned int);
bool robot_ltoreq_slot(char, char);
char switch_blocks(char, unsigned int, char[]);
bool test_empty(unsigned int, char[]);
char get_block_testcase(unsigned int, unsigned int);
char get_block_testone(void);
char get_block_testtwo(void);
char get_block_testthree(void);
char get_block_testfour(void);
char get_block_testfive(void);