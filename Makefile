# makefile for scheduling program
#

# make build - for scheduling


CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs
	


build: driver.o queue.o cpu.o scheduler.o
	$(CC) $(CFLAGS) -o scheduler driver.o schedule.o queue.o cpu.o


scheduler.o: scheduler.c
	$(CC) $(CFLAGS) -c scheduler.c

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

cpu.o: cpu.c cpu.h
	$(CC) $(CFLAGS) -c cpu.c
