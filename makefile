# Example Makefile

CC=g++ -Wall
CLIB=-lgps

dcgps: clean dcgps.o gps-utils.o gpsprint.o
	$(CC) -o dcgps dcgps.o gps-utils.o gpsprint.o $(CLIB)

clean:
	rm -f *.o core.* dcgps
dcgps.o:
	rm -f dcgps.o
	$(CC) -c dcgps.cpp
gps-utils.o:
	rm -f gps-utils.o
	$(CC) -c gps-utils.cpp
gpsprint.o:
	rm -f gpsprint.o
	$(CC) -c gpsprint.cpp
