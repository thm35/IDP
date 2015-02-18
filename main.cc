//thm35
#include "header.h"

int main(){

	int connected = startrobot(); //connect to robot
	while (connected != 0) {
		cout << "Retrying Connection..." << endl;
		connected = start_robot();
	}

	while (junction == 0){
		line_follow2();
	}

}




//controls motors to drive the wheels
void drive (int ramp, int m1, int m2){		//ramp time, right wheel speed, left wheel speed
	rlink.command (RAMP_TIME, ramp);
	rlink.command(MOTOR_1_GO, m1); 			
	rlink.command(MOTOR_2_GO, m2); 			

//stops sharply
void stop(){
	rlink.command(RAMP_TIME, 0);
	rlink.command(MOTOR_1_GO, 0); 			
	rlink.command(MOTOR_2_GO, 0);
}


//turns left by 90 degrees
void left_turn(){
	drive(FAST_RAMP, RMAX - SLOWTURN , RMAX - SLOWTURN);  //may be different for our robot, could be too fast
	delay(TURN90DELAY);
	stop();
}

//turns right by 90 degrees
void right_turn(){
	drive(FAST_RAMP, LMAX - SLOWTURN, LMAX - SLOWTURN);
	delay(TURN90DELAY);
	stop();
}

//turns right by 180 degrees
void turn_around(){
	drive(FAST_RAMP, LMAX - SLOWTURN, LMAX - SLOWTURN);
	delay(TURN180DELAY);
	stop();
}
