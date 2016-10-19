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
#include <chrono>
#include <cmath>
#include <iomanip>
#include "gpsprint.h"

#define PI 3.14159265358979323846
#define DIST_FACTOR 1.1515

using namespace std;

char moveChar[4] = {'\\', '|', '/', '-'};
int moveIndex = 0;
double preLat = -1.0;
double preLng = -1.0;
double totalTime = 0.0;
chrono::high_resolution_clock::time_point startTime;
chrono::high_resolution_clock::time_point endTime;




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
	
	for(int i = 0; i< MAXCHANNELS; i++){
		if(i < gpsdata->satellites_visible){
			bool used_flag = false;
			for(int j = 0; j < gpsdata->satellites_used; j++){
				if(gpsdata->used[j] == gpsdata->PRN[i]){}
					used_flag = true;
			}
			string used = (used_flag) ?  "Y":"N";
			
			cout << "PRN: "       << setfill(' ') << setw(4) << gpsdata->PRN[i]       << " | ";
			cout << "Elevation: " << setfill(' ') << setw(4) << gpsdata->elevation[i] << " | ";
			cout << "Azimuth: "   << setfill(' ') << setw(4) << gpsdata->azimuth[i]   << " | ";
			cout << "SNR: "       << setfill(' ') << setw(4) << gpsdata->ss[i]        << " | ";
			cout << "Used: "      << setfill(' ') << setw(2) << used                  << "";
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
	cout << setprecision(4) << fixed << "LAT:" << gpsdata->fix.latitude << " " << "LNG:" << gpsdata->fix.longitude << endl;

	endTime = chrono::high_resolution_clock::now();
	auto dur = endTime - startTime;
    auto ms = chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	startTime = endTime;
	//cout << seconds << endl;

	double dist = 0.0;
	if (preLat != -1.0 && preLng != -1.0)
	{
		dist = calculateDistance(gpsdata->fix.latitude, gpsdata->fix.longitude,
			preLat, preLng);
	}

	//cout << dist << endl;
	cout << setprecision(2) << fixed << dist/ms << "m/s" << endl;

	cout << moveChar[moveIndex % 4] << endl;
	totalTime += ms;
	if (totalTime >= 2000.0)
	{
		moveIndex++;
		totalTime = 0.0;
	}

	preLat = gpsdata->fix.latitude;
	preLng = gpsdata->fix.longitude;
}


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
double toRad(double degree) {
    return degree/180 * PI;
}


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
double calculateDistance(double lat1, double long1, double lat2, double long2) {
    double dist;
    dist = sin(toRad(lat1)) * sin(toRad(lat2)) + cos(toRad(lat1)) * cos(toRad(lat2)) * cos(toRad(long1 - long2));
    dist = acos(dist);
    dist = dist * 60 * DIST_FACTOR;
    return dist;
}