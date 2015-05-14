//////////////////////////////////////////////////////////////////
//Program 3
//Title: main.cpp 
//Semester: Fall 2013
//Author: Maimuna Lubega
//Email: lubega@wisc.edu
//Login: maimuna
//
//Author: Austin Cain
//Email: ascain@wisc.edu
//Login: acain
//
//The differences between the Student and SortedList files is
//that in the SortedList, in order to copy or delete a list,
//the list has to be iterated over each node.  In addition, each 
//node must be allocated a new student or when deleting, each
//student must be deleted individually before deleting the entire
//node.  On the other hand, the Student class is much simpler. 
//It does not contain any pointers to heap allocated memory.
//No special delete must be implemented. 
////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Student.h"
#include "SortedList.h"

using namespace std;


int
main(int argc, char* argv[]){

	//Constructors Sorted List-Stack Allocated
	SortedList L1;
	SortedList L2;

	//Constructors Sorted List -Heap Allocated
	SortedList* L4 = new SortedList();
	SortedList* L5 = new SortedList();	
	//Constructors Student - Heap Allocated
	Student* s1 = new Student(100000, 30, 4.0);
	Student* s2 = new Student(200000, 30, 3.0);
	Student* s3 = new Student(300000, 30, 2.0);
	Student* s4 = new Student(400000, 30, 1.0);
	Student* s5 = new Student(500000, 20, 4.0);
	Student* s6 = new Student(600000, 20, 3.0);
	Student* s7 = new Student(700000, 20, 2.0);
	Student* s8 = new Student(800000, 20, 1.0);
	Student* s9 = new Student(900000, 10, 4.0);
	Student* s10 = new Student(101000, 10, 4.0);

	L1.insert(s1);
	L1.insert(s2);
	L1.insert(s3);
	L1.insert(s4);
	L1.insert(s5);
	cout<< "printing L1: " << endl;
	L1.print();
	cout << endl;

	L2.insert(s6);
	L2.insert(s7);
	L2.insert(s8);
	L2.insert(s9);
	L2.insert(s10);

	cout<< "printing L2: " << endl;
	L2.print();
	cout << endl;

	L4->insert(new Student(*s6));
	L4->insert(new Student(*s7));
	L4->insert(new Student(*s8));
	L4->insert(new Student(*s9));
	L4->insert(new Student(*s10));
	cout << "printing L4: " << endl;
	L4->print();
	cout << endl;

	L5->insert(new Student(*s1));
	L5->insert(new Student(*s2));
	L5->insert(new Student(*s3));
	L5->insert(new Student(*s4));
	L5->insert(new Student(*s5));
	cout<< "printing L5: " << endl;
	L5->print();
	cout << endl;

	//Copy Assignment-Heap Allocated Sorted List
	*L4 = *L5;

	cout << "printing L4: " << endl;
	L4->print();
	cout << endl;
	
	//Copy Constructor-Heap Allocated SortedList
	SortedList *L6 = new SortedList(*L4);
	cout << "printing L6: " << endl;
	L6->print();
	cout << endl;


	//Copy Constructor-Stack Allocated SortedList
	SortedList L3 (L1);

	cout<< "printing L3: " << endl;
	L3.print();
	cout << endl;
	//Copy Assignment Constructor- Stack Allocated SortedList
	L2 = L1;

	cout<< "printing L2: " << endl;
	L2.print();
	cout << endl;
	//Copy Assignment Constructor - Stack Allocated SortedList
	L1 = L2;

	cout<< "printing L1: " << endl;
	L1.print();
	cout << endl;
	//Constructor Student-Heap Allocated
	Student* s11 = new Student(990000, 10, 4.0);
	Student* s12 = new Student(666000, 10, 4.0);
	L1.insert(s11);
	L1.insert(s12);

	cout<< "printing L1: " << endl;
	L1.print();
	cout << endl;

	//Destructor Called
	L1.remove(990000);
	L1.remove(666000);
	cout<< "printing L1: " << endl;
	L1.print();
	cout << endl;

	//Desctructor Called
	L3.remove(400000);
	cout<< "printing L3: " << endl;
	L3.print();
	cout << endl;


	
	  //Destructor - Heap Allocated Students
/*        delete s1;
	  delete s2;
	  delete s3;
	  delete s4;
	  delete s5;
	  delete s6;
	  delete s7;
	  delete s8;
	  delete s9;
	  delete s10;
	  delete s11;
	  delete s12;
*/	  //Destructor - Heap Allocated SortedLists
delete L4;
delete L5;  
delete L6;
	return 0;


}
