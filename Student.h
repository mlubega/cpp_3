#ifndef STUDENT_H
#define STUDENT_H

/*
 * Student class
 *
 * A Student object contains a student ID, the number of credits, and an
 * overall GPA.
 */
class Student {

  public:
    
    Student();
    // Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA.

    Student(int ID);
    // Constructs a student with the given ID, 0 credits, and 0.0 GPA.

    Student(int ID, int cr, double grPtAv);
    // Constructs a student with the given ID, number of credits, and GPA.

    // Accessors
    int getID() const;       // returns the student ID
    int getCredits() const;  // returns the number of credits
    double getGPA() const;   // returns the GPA

    // Other methods

	Student(const Student &S); //copy constructor
	~Student(); //destructor
	const Student & operator=(const Student &S); //copy assignment




    void update(char grade, int cr);
    // Updates the total credits and overall GPA to take into account the
    // additions of the given letter grade in a course with the given number
    // of credits.  The update is done by first converting the letter grade
    // into a numeric value (A = 4.0, B = 3.0, etc.).  The new GPA is 
    // calculated using the formula:
    //
    //            (oldGPA * old_total_credits) + (numeric_grade * cr)
    //   newGPA = ---------------------------------------------------
    //                        old_total_credits + cr
    //
    // Finally, the total credits is updated (to old_total_credits + cr)

    void print() const;  
    // Prints out the student to standard output in the format:
    //   ID,credits,GPA
    // Note: the end-of-line is NOT printed after the student information 

  private:
    int studentID;
    int credits;
    double GPA;
};

#endif
