#define MAXCHANNELS 72
#include <iostream>
#include <libgpsmm.h>
#include "gpsprint.h"

using namespace std;

void printData(struct gps_data_t *gpsdata){
	
	
	//cout << "entered print function" << endl;
	
	
	bool used_flag[MAXCHANNELS];
	
	for(int i = 0; i< MAXCHANNELS; i++){
		if(i < gpsdata->satellites_visible){
			
			used_flag[i] = false;
			cout << "PRN: "       << gpsdata->PRN[i]           << " ";
			cout << "Elevation: " << gpsdata->elevation[i]     << " ";
			cout << "Azimuth: "   << gpsdata->azimuth[i]       << " ";
			cout << "ss: "        << gpsdata->ss[i]            << endl;
			
			for(j = 0; j < gpsdata->satellites_used; j++){
				if(gpsdata->used[j] == gpsdata->PRN[i]){}
					used_flag[i] = true;
			}
			if(used_flag[i]) ? cout << "Yes": cout << "No";
	
		}
	}
	
	
	cout << "Timestamp: " << gpsdata->fix.time      << " ";
	cout << "Latitude: "  << gpsdata->fix.latitude  << " ";
	cout << "Longitude: " << gpsdata->fix.longitude << endl;

	
	
	cout << "Uesed: ";
	
	
	<< gpsdata->ss << endl;
	
	//cout << "Satalites: " << gpsdata->satellites_used << endl;
	
	
	
	
}