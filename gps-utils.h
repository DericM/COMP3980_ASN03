/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: gps-utils.h - An application that will continuously check
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
#ifndef GPSUTIL_H
#define GPSUTIL_H

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
void handle_error(int error_no);

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
void read(gpsmm* gps_rec);

#endif