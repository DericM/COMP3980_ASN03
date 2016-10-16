
#include <iostream>
#include <libgpsmm.h>
#include "gps-utils.h"
#include "gpsprint.h"

using namespace std;

void read(gpsmm& gps_rec){
	
	for (;;) {
        struct gps_data_t* newdata;

        if (!gps_rec.waiting(50000000))
          continue;

        if ((newdata = gps_rec.read()) == NULL) {
            cerr << "Read error.\n";
            return;
        } else {
			printData(newdata);
        }
    }
}