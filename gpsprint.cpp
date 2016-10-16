#include <iostream>
#include <iomanip>
#include <libgpsmm.h>
#include "gpsprint.h"

using namespace std;

void printData(struct gps_data_t *gpsdata){
	
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
	struct tm *tm = localtime(&t);
	char charDateTime[20];
	strftime(charDateTime, sizeof(charDateTime), "%Y-%m-%d %H:%M:%S", tm);
	string dateTime(charDateTime);
	
	cout << "Timestamp: " << dateTime               << " | ";
	cout << "Latitude: "  << gpsdata->fix.latitude  << "N | ";
	cout << "Longitude: " << gpsdata->fix.longitude << "W";
	cout << endl << endl;
	
}