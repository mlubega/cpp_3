/*******************************************************************************
Author:        Austin Cain
CS Login:      acain

Pair Partner:  Maimuna Lubega
CS Login:      maimuna


Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 2

Credits:        Jim Skrentny
*******************************************************************************/

#include <iostream>
#include "Student.h"
#include <cctype>

using namespace std;


/**
 * A function that creates a student with ID, credits,
 * and GPA equivalent to 0.
 **/
Student::Student() :
studentID(000000), credits(0), GPA(0.0)
{
 
  // studentID = 0;
  // credits = 0;
  // GPA = 0.0;
 
}
/**
 * A function that creates a student with ID equivalent
 * to the ID that is given, and  credits
 * and GPA equivalent to 0.
 * @param (ID) (takes in ID of type int)
 **/
Student::Student(int ID) :
studentID(ID), credits(0), GPA(0.0)
{

  // studentID = ID;
  // credits = 0;
  // GPA = 0.0;
 
}
/**
 * A function that creates a student with ID equivalent
 * to the ID, credit equivalent to cr, and 
 * and GPA equivalent to grPTAV.
 * @param (ID) (takes in ID of type int)
 * @param (cr) (non negative integer value)
 * @param (grPtAv) (floating point number between 0.0 and 4.0 of type double)
 **/
Student::Student(int ID, int cr, double grPtAv): 
studentID(ID), credits(cr), GPA(grPtAv)
{
	
}

/**
 * Retrieves the ID of a student
 * @return (student's ID)
 **/
int Student::getID() const {return studentID;}
/**
 * Retrieves the credits of a student
 * @return (student's credits)
 **/
int Student::getCredits()const {return credits;}
/**
 * Retrieves the GPA of a student
 * @return (student's GPA)
 **/
double Student::getGPA() const {return GPA;}
/**
 *Copy constructor
 *@param (S) Takes in a student
 **/
Student::Student(const Student &S):
studentID(S.studentID), credits(S.credits), GPA(S.GPA)
{
}
/**
 *Copy assignment constructor
 *@param (S) Takes in a student
 *@return (Copy of student)
 * **/
const Student & Student::operator=(const Student &S)
{
	if(this != &S){
		studentID=S.studentID;
		credits=S.credits;
		GPA= S.GPA;
	}
	return *this;
}
/** 
 *Destructor
 * **/	

Student::~Student()
{
}



/**
 *Updates a student record GPA and credit total. Adds
 *given credits to current credits, and recalculates GPA
 *based on the recieved letter grade.
 * @param (grade) (letter grade (valid: A B C D F)
 * @param (cr) (number of credits from class)
 **/
void Student::update(char grade, int cr){
  grade=toupper(grade);
  switch (grade){

  case 'A':
  GPA  =  ((GPA * credits) + (4.0 * cr)) / (credits + cr);
  break;
  case 'B':
  GPA  =  ((GPA * credits) + (3.0 * cr)) / (credits + cr);
  break;
  case 'C':
  GPA  =  ((GPA * credits) + (2.0 * cr)) / (credits + cr);
  break;
  case 'D':
  GPA  =  ((GPA * credits) + (1.0 * cr)) / (credits + cr);
  break;
  case 'F':
  GPA  =  ((GPA * credits) + (0.0 * cr)) / (credits + cr);
  break;
  default:
    break;

  }


  credits = credits + cr;


}

/**
 * print out student's ID, credits and GPA
 **/
void Student::print() const{
  char comma = ',';
  cout << studentID << comma << credits << comma << GPA;

}  

