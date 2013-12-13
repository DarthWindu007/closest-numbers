CC = g++ -std=c++0x -w
CFLAGS = -g -O3
RM = /bin/rm -f 
all: main 
main: main.o
	$(CC) $(CFLAGS) -o run main.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
clean: 
	$(RM) *.o *.exe run
