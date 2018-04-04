all: release debug

CC = gcc

release: main.o getUinfo.o findSfile.o printFinfo.o changePerm.o
	$(CC) -o release main.o getUinfo.o findSfile.o printFinfo.o changePerm.o

debug: main.od getUinfo.od findSfile.od printFinfo.od changePerm.od
	$(CC) -o debug main.od getUinfo.od findSfile.od printFinfo.od changePerm.od

main.o: main.c
	$(CC) -o main.o -O main.c -c
getUinfo.o: getUinfo.c
	$(CC) -o getUinfo.o -O getUinfo.c -c
findSfile.o: findSfile.c
	$(CC) -o findSfile.o -O findSfile.c -c
printFinfo.o: printFinfo.c
	$(CC) -o printFinfo.o -O printFinfo.c -c
changePerm.o: changePerm.c
	$(CC) -o changePerm.o -O changePerm.c -c


main.od: main.c
	$(CC) -o main.od -DDEBUF -g main.c -c
getUinfo.od: getUinfo.c
	$(CC) -o getUinfo.od -DDEBUG -g getUinfo.c -c
findSfile.od: findSfile.c
	$(CC) -o findSfile.od -DDEBUG -g findSfile.c -c
printFinfo.od: printFinfo.c
	$(CC) -o printFinfo.od -DDEBUG -g printFinfo.c -c
changePerm.od: changePerm.c
	$(CC) -o changePerm.od -DDEBUG -g changePerm.c -c

clean:
	rm -f *.o release debug
