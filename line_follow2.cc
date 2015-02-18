//thm35
#include "header.h"
#include "line_follow.h"

robot_link rlink;

void line_follow2(int port1_0, int port1_1, int port1_2, int port1_3){

	int centredec = port1_1*2 + port1_2 * 4; //turns the 3 binary inputs of a port into a decimal
	
	if (port1_0 + port1_3 == 0){	//if the junction detectors are both low
		switch(centredec){
			case 0: //central or lost line
				drive(FAST_RAMP, RMAX, LMAX);
				break;
			case 2: //left
				drive(FAST_RAMP, RMAX - SMADJ, LMAX);
				break;
			case 4: //right
				drive(FAST_RAMP, RMAX, LMAX - SMADJ);
				break;
			case 6: //junction right
	}
	else{
		while(centredec != 6){	//puts motors to half speed untill the centre detectors are both high
			drive(FAST_RAMP, RMAX/2, LMAX/2);
		}
		stop(); //stops when centre detectors are both high
		junction = 1;
	}
	}
}
