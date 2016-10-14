#define LOCAL_HOST "127.0.0.1"

#include <gps.h>
#include <libgpsmm.h>

#include <iostream>
#include <iomanip>

#include "gps-utils.h"
#include "gpsprint.h"






using namespace std;


int main(){
	
	
	gpsmm gps_rec("localhost", DEFAULT_GPSD_PORT);

    if (gps_rec.stream(WATCH_ENABLE|WATCH_JSON) == NULL) {
        cerr << "No GPSD running.\n";
        return 1;
    }

	
	read(gps_rec);
	
	
	
	//cleanup
	return 0;
    
}
