default: sqlite3.o main.c person.h
	#gcc main.c sqlite3.o -lpthread -ldl && clear && ./a.out
	gcc main.c sqlite3.o -lpthread -ldl && ./a.out

sqlite3.o: sqlite3.c sqlite3.h
	gcc sqlite3.c  -c

clear:
	rm *.o a.out
