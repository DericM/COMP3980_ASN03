/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: gps-utils.cpp - An application that will continuously check
-- the GPSD port for data and print it to the console while checking for errors.
--
-- PROGRAM: GPS Listener 
--
-- FUNCTIONS:
-- void handle_error(int error_no)
-- void read(gpsmm& gps_rec)
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
-- An application that will continuously check
-- the GPSD port for data and print it to the console while checking for errors.
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <libgpsmm.h>
#include <stdlib.h>
#include <errno.h>
#include "gps-utils.h"
#include "gpsprint.h"

#define WAIT_GPS_TIMEOUT 50000000

using namespace std;



/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: handle_error
--
-- DATE: October 18, 2016
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Deric Mccadden, Jamie Lee
--
-- PROGRAMMER: Deric Mccadden, Jamie Lee
--
-- INTERFACE: handle_error()
--
-- RETURNS: void.
--
-- NOTES:
-- This handles the various errors of the program and then safely exits.
----------------------------------------------------------------------------------------------------------------------*/
#define CGPS_QUIT	0	/* voluntary yterminastion */
#define GPS_GONE	-1	/* GPS device went away */
#define GPS_ERROR	-2	/* low-level failure in GPS read */
#define GPS_TIMEOUT	-3	/* low-level failure in GPS waiting */
void handle_error(int error_no){
	switch (error_no) {
		case CGPS_QUIT:
			break;
		case GPS_GONE:
			cerr << "GPS hung up." << endl;
			break;
		case GPS_ERROR:
			cerr << "GPS read returned error" << endl;
			break;
		case GPS_TIMEOUT:
			cerr << "GPS timeout" << endl;
			break;
		default:
			break;
    }
    exit(1);
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: handle_error
--
-- DATE: October 18, 2016
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Deric Mccadden, Jamie Lee
--
-- PROGRAMMER: Deric Mccadden, Jamie Lee
--
-- INTERFACE: handle_error()
--
-- RETURNS: void.
--
-- NOTES:
-- This is a loop that will constantly try to read data from the GPSD port
-- successful reads will print the data and errors will exit the program.
----------------------------------------------------------------------------------------------------------------------*/
void read(gpsmm* gps_rec){
	
	for (;;) {
        struct gps_data_t* newdata;

        if (!gps_rec->waiting(WAIT_GPS_TIMEOUT))
          handle_error(GPS_TIMEOUT);

		errno = 0;
        if ((newdata = gps_rec->read()) == NULL) {
			handle_error(errno==0 ? GPS_GONE:GPS_ERROR);
        } else {
			printData(newdata);
        }
    }
}




