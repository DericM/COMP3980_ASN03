/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: gpsprint.h - An application that print out the GPS data
-- supplied by the gps_data_t structure to the console, and apply formatting.
--
-- PROGRAM: GPS Listener 
--
-- FUNCTIONS:
-- void printData(struct gps_data_t *gpsdata)
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
-- An application that print out the GPS data supplied by the gps_data_t 
-- structure to the console, and apply formatting.
----------------------------------------------------------------------------------------------------------------------*/
#ifndef GPSPRINT_H
#define GPSPRINT_H

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: printData
--
-- DATE: October 18, 2016
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Deric Mccadden, Jamie Lee
--
-- PROGRAMMER: Deric Mccadden, Jamie Lee
--
-- INTERFACE: printData()
--
-- RETURNS: void.
--
-- NOTES:
-- This function prints data from the gps_data_t structure to the console 
-- and applies formatting.
----------------------------------------------------------------------------------------------------------------------*/
void printData(struct gps_data_t *gpsdata);

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: toRad()
--
-- DATE: October 18, 2016
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Deric Mccadden, Jamie Lee
--
-- PROGRAMMER: Deric Mccadden, Jamie Lee
--
-- INTERFACE: toRad()
--
-- RETURNS: double.
--
-- NOTES:
-- This function converts from degrees to radians.
----------------------------------------------------------------------------------------------------------------------*/
double toRad(double degree);

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: calculateDistance()
--
-- DATE: October 18, 2016
--
-- REVISIONS: (Date and Description)
--
-- DESIGNER: Deric Mccadden, Jamie Lee
--
-- PROGRAMMER: Deric Mccadden, Jamie Lee
--
-- INTERFACE: calculateDistance()
--
-- RETURNS: double.
--
-- NOTES:
-- This function calculates the distance
----------------------------------------------------------------------------------------------------------------------*/
double calculateDistance(double lat1, double long1, double lat2, double long2);


#endif