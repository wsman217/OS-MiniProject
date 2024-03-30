# makefile for scheduling program
#

# make fcfs - for FCFS scheduling


CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs
	


fcfs: driver.o queue.o cpu.o schedule_fcfs.o
	$(CC) $(CFLAGS) -o fcfs driver.o schedule_fcfs.o queue.o cpu.o


schedule_fcfs.o: schedule_fcfs.c
	$(CC) $(CFLAGS) -c schedule_fcfs.c

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

cpu.o: cpu.c cpu.h
	$(CC) $(CFLAGS) -c cpu.c
