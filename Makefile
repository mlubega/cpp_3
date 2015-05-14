runMain: main.o SortedList.o Student.o
	g++ -g main.o SortedList.o Student.o -o runMain

runDB: studentDB.o SortedList.o Student.o
	g++ -g studentDB.o SortedList.o Student.o -o runDB

Student.o: Student.cpp Student.h
	g++ -g -c Student.cpp

SortedList.o: SortedList.cpp SortedList.h Student.h
	g++ -g -c SortedList.cpp

studentDB.o: studentDB.cpp SortedList.h Student.h
	g++ -g -c studentDB.cpp

valgrind: runMain
	valgrind --leak-check=full runMain

clean:
	rm *.o
