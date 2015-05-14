/*******************************************************************************
Author:        Austin Cain
CS Login:      acain

Pair Partner:  Maimuna Lubega
CS Login:      maimuna


Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 2

Credits:
 *******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include "SortedList.h"
#include "Student.h"


using namespace std ;
/**Constructor
 *
 * constructs an empty list
 **/
SortedList::SortedList() {
	head = NULL;
};

/**freeList
 *
 * Called by destructor.
 *Iterates and frees student, then each  node in the list.
 *@Param (Listnode* L) Head of list 
 **/
void SortedList::freeList(Listnode *L){
	Listnode* temp = L;
	Listnode* curr = temp;
	//if no list exists
	if(L == NULL){
		return;
	}
	//if there is only one node
	else if( L != NULL && L->next == NULL){
		delete L->student;
		delete L;
		return;
	}
	else{
		do{
			curr = temp;
			temp=temp->next;
			delete curr->student;
			delete curr;	
		}while (temp != NULL);

	}
};

/**
 *Copy List

 *Makes a heap allocated copy of the list that is passed in
 *@param (Listnode *L) Head of list to be copied
 *@return(Listnode *L) Returns pointer to head of copied list
 **/
SortedList::Listnode * SortedList::copyList(Listnode* L){

	Listnode* curr = NULL;
	Listnode* temp = L;
	Listnode* first = NULL;

	//if head exist, make a copy and assign node to remember
	// head for the new list
	if(temp != NULL){
		curr = new Listnode();
		curr->student = new Student(*(temp->student));
		curr->next= NULL;
		first = curr;
		//copies the rest of the list
		while (temp->next != NULL){
			temp = temp->next;
			curr = curr->next = new Listnode();
			curr->student = new Student(*(temp->student));
			curr->next = NULL;

		}

	}
	return first;
};
/**
 *Copy constructor
 *Assigns a new list, a heap allocated copy, 
 *of the list that is passed in.
 *@param (SortedList &L) List to be copied
 **/
SortedList::SortedList(const SortedList &L){
	head = copyList(L.head);

};
/**
 *Copy assignment operator
 *Deletes the old heap memory and reassigns this list -
 *a copy of the specified SortedList, L.
 *@param (SortedList &L) List to be copied
 *@return (SortedList *L) Returns a newly assigned list.
 **/
SortedList & SortedList::operator=(const SortedList &L){
	if(this != &L){
		//delete old memory 
		freeList(head);
		//create copy
		head = copyList(L.head);
	}
	return *this;

};
/**Destructor
 * Calls auxillary function FreeList
 **/
SortedList:: ~SortedList(){
	freeList(head);

};


/**Insert
 *
 * Inserts a new student into the database in an increasing order.
 * If a student is already in the database, the list doesn't change
 * and false is returned.
 * @param (s) a pointer of type student
 * @returen (bool) returns true if student successfully added, false if ID 
 * already in database
 **/
bool SortedList::insert(Student *s) {


	Listnode *temp;
	Listnode *newStudent;
	int studID;
	bool inserted = false;
	
	//Create new Listnode
	newStudent  = new Listnode();
	newStudent->student = s;
	newStudent->next = NULL;

	//save studentID as an int for easy comparison
	studID =s->getID();

	//if list is empty, newStudent becomes the head
	if (head == NULL) {
		head = newStudent;
		inserted = true;

	}
	else {
		//if list not empty and the newStudent is smaller than the
		//head record, insert newStudentbefore the head record
		if ((head->student)->getID() > studID) {
			newStudent->next = head;
			head = newStudent;
			inserted = true;
		}else{

			//initialize temp
			temp = head;

			//iterate through singly linked list, when it terminates, temp
			//node will the node previous to where newStudent should be
			//inserted
			while (temp->next != NULL && ((temp->next)->student)->getID() < studID){
				temp = temp->next;

			}
			//ID already in singly linked list
			if((temp->student)->getID() == studID){
				delete newStudent->student;
				delete newStudent;
				return inserted;
			}
			//add newStudent to the list
			else{
				newStudent->next = temp->next;
				temp->next = newStudent;
				inserted = true;
			}
		}
	}

	return inserted;
};
/**Find 
 *
 * Searches the database with a studentID.  Student is returned if found,
 * otherwise NULL is returned.
 * @param (studentID (6 digit integer ID of student)
 * @return (Student) (returns student record if found, otherwise NULL) 
 **/
Student* SortedList::find(int studentID){

	//there are no records present in singly linked list
	if(head == NULL){
		return NULL;
	}

	Listnode *temp;
	Student* s;
	temp = head;
	//iterate through linked list until a student matches ID given
	do{
		s = temp->student;
		if( (s->getID()) == studentID){
			return s;
		}
		temp = temp->next;

	}while(temp != NULL);


	return temp->student;

};

/**Remove
 *
 *Given a student ID to remvoe student from database.
 * Remove from list if found, otherwise return NULL.
 * @param (studentID) (6 digit integer ID of student)
 * @return (Student) student returned if found, otherwise NULL
 * returned if not found.
 **/
Student* SortedList::remove(int studentID){

	// no student was found in singly linked list with ID given
	if(head == NULL){
		return NULL;
	}

	Listnode* temp;
	Listnode* todelete;
	Student* s;
	temp = head;
	//if first node matches
	if((temp->student)->getID() == studentID){
		head = temp->next;
		s = temp->student;
		delete temp->student;
		delete temp;
		return s;
	}
	else{
		// step through singly linked list until ID matches a student record.
		// at loop termination temp holds node previous to node to be deleted
		while((((temp->next)->student)->getID() != studentID) && temp->next != NULL){
			temp = temp->next;
		}
		//check & delete node
		if( ((temp->next)->student)->getID() == studentID){
			s = (temp->next)->student;
			todelete = temp->next;
			temp->next  = (temp->next)->next;
			delete todelete->student;
			delete todelete;
			return s;	
		}else{
			return NULL;
		}

	}


};



/**Print
 *
 * prints out list of students in increasing order 
 * (which is the way they are stored) 
 **/
void SortedList:: print() const{
	Listnode* curr;

	if( head != NULL){
		curr = head;

		do{
			cout << (curr->student)->getID() << endl;
			curr = curr->next;
		}while(curr != NULL);
	}

};
