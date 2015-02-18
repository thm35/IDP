//thm35
//line following code to run for three sensors
#include "header.h"
#include "line_follow.h"

robot_link rlink;

void line_follow(int port1_0, int port1_1, int port1_2){

	int portdec = port1_0 + port1_1 * 2 + port1_2 * 4; //turns the 3 binary inputs of a port into a decimal
	
	switch(portdec){
		case 0: //lost line
			cout << "error: lost line" << endl;
			break;
		case 1: //far right
			drive(FAST_RAMP, RMAX, LMAX - BMADJ);
			break;
		case 2: //central
			drive(FAST_RAMP, RMAX, LMAX);
			break;
		case 3: //right
			drive(FAST_RAMP, RMAX, LMAX - SMADJ);
			break;
		case 4: //far left
			drive(FAST_RAMP, RMAX - BMADJ, LMAX);
			break;
		case 5: //error
			cout << "error: left and right are high" << endl;
			break;
		case 6: //left
			drive(FAST_RAMP, RMAX - SMADJ, LMAX);
			break;
		case 7: //junction
			junction = 1;
			break;
		default:
			cout << "error: linefollow default" << endl;
	}
}
