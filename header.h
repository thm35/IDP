//thm35
#include <iostream>
#include <fstream>
#include <robot_instr.h>
#include <robot_link.h>
#include <delay.h>
#include <cmath>
#include <ctime>
#include <stopwatch.h>
#include <string>
// #include <stdio.h>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

#define ROBOT_NUM 7
#define RMAX 126
#define LMAX 255
#define SLOW_RAMP 255
#define MEDIUM_RAMP 127
#define FAST_RAMP 0
#define TURN90DELAY	100		//requires testing to determine
#define TURN180DELAY 200	//probably 2 TURN90DELAY
#define SLOWTURN 60			//how much slower than max to turn by


extern robot_link rlink;
extern int junction = 0;
extern int numjunction = 0;

void drive(int ramp, int m1, int m2);
void left_turn();
void right_turn();
void turn_around();
void stop();
