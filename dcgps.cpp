/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: dcgps.cpp - An application that will collect satalite GPS information
-- using the GPSD library and display it to the console.
--
-- PROGRAM: GPS Listener 
--
-- FUNCTIONS:
-- int main()
--
--
-- DATE: October 18, 2016
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Deric Mccadden, Jamie Lee
--
-- PROGRAMMER: Deric Mccadden, Jamie Lee
--
-- NOTES:
-- An application that will collect satalite GPS information
-- using the GPSD library and display it to the console.
----------------------------------------------------------------------------------------------------------------------*/
#include <gps.h>
#include <libgpsmm.h>
#include <iostream>
#include <iomanip>
#include <thread>

#include "gps-utils.h"
#include "gpsprint.h"

using namespace std;


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: main
--
-- DATE: October 18, 2016
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Deric Mccadden, Jamie Lee
--
-- PROGRAMMER: Deric Mccadden, Jamie Lee
--
-- INTERFACE: main()
--
-- RETURNS: int.
--
-- NOTES:
-- This is the entry point to the program, it attempts to open the
-- GPSD port and then enters the read loop.
----------------------------------------------------------------------------------------------------------------------*/
#define LOCAL_HOST "127.0.0.1"
int main(){
	gpsmm gps_rec(LOCAL_HOST, DEFAULT_GPSD_PORT);

    if (gps_rec.stream(WATCH_ENABLE|WATCH_JSON) == NULL) {
        cerr << "No GPSD running.\n";
        return 1;
    }
	
	thread readThrd(read, &gps_rec);
    readThrd.join();
	
	return 0;
}


