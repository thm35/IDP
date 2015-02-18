//thm35
#include "header.h"

int startrobot() { // Connect via wireless link	
	int val;
	#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {  // Setup for local hardware
	#else
   if (!rlink.initialise (ROBOT_NUM)) { // Setup the link over Wi-Fi
	#endif                   
		cout << "Cannot initialise link" << endl;
		rlink.print_errs("  ");
		return -1;	
	}
	val = rlink.request (TEST_INSTRUCTION); // Send test instruction
	if (val == TEST_INSTRUCTION_RESULT) {   // Check result
	  cout << "Robot is online" << endl;
	   return 0;                          // All OK, finish
	}
	else if (val == REQUEST_ERROR) {
	  cout << "Fatal errors on link:" << endl;
	  rlink.print_errs();
	  return -1;
	}
	else {
	  cout << "Test failed" << endl;
	    return -1;                      // Error, finish
		}		
}
