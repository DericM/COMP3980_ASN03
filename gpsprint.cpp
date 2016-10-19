/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: gpsprint.cpp - An application that print out the GPS data
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
#include <iostream>
#include <iomanip>
#include <libgpsmm.h>
#include <stdlib.h>
#include "gpsprint.h"

using namespace std;




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
void printData(struct gps_data_t *gpsdata){
	
	system("clear");
	//cout << string(70, '*') << endl;
	
	for(int i = 0; i< MAXCHANNELS; i++){
		if(i < gpsdata->satellites_visible){
			bool used_flag = false;
			for(int j = 0; j < gpsdata->satellites_used; j++){
				if(gpsdata->used[j] == gpsdata->PRN[i]){}
					used_flag = true;
			}
			string used = (used_flag) ?  "Y":"N";
			
			cout << setfill(' ');
			cout << "PRN: "       << setw(4) << gpsdata->PRN[i]       << " | ";
			cout << "Elevation: " << setw(4) << gpsdata->elevation[i] << " | ";
			cout << "Azimuth: "   << setw(4) << gpsdata->azimuth[i]   << " | ";
			cout << "SNR: "       << setw(4) << gpsdata->ss[i]        << " | ";
			cout << "Used: "      << setw(2) << used                  << "";
			cout << endl;
	
		}
	}
	
	time_t t = gpsdata->fix.time;
	struct tm *tm = gmtime(&t);
	char charDateTime[20];
	strftime(charDateTime, sizeof(charDateTime), "%Y-%m-%d %H:%M:%S", tm);
	string dateTime(charDateTime);
	cout << "Timestamp: " << dateTime               << " | ";
	
	cout << "Latitude: "  << gpsdata->fix.latitude  << "N | ";
	cout << "Longitude: " << gpsdata->fix.longitude << "W";
	cout << endl << endl;
	
}