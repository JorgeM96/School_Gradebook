/* Author: Jorge Moreno
   Instructor: Keathly
   Date: 2/2/17
   Description: This program is ment to be a gradebook that has a menu to hold functions for calculating different things for students and their courses. */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "structures1.h"
#include "functions1.h"
using namespace std;

const int MEMORYBLOCK = 25;  //Used to increase memory allocation by this number.

int main()
{
	studentsC stud; //This is a variable for the student collection struct
	coursesC course2;  //this is a variable for the course collection struct
	registryC reg;  //this is a variable for the registry collection struct
	int choice = -1;
	stud.studCnt=0;    //initialize the stud count to 0
	course2.courseCnt=0;  //initialie the course count to 0
	reg.regCnt=0;  //initialize the registry count to 0
	stud.studCap = course2.courseCap = reg.regCap = MEMORYBLOCK;  //set all capacities to the same memoryblock

	stud.studList = new student[MEMORYBLOCK];   //Allocating memory

	course2.courseList = new course[MEMORYBLOCK];

	reg.regList = new registry[MEMORYBLOCK];

	while(choice != 0)  //loop to allow the menu to show again after an option has been closed
	{
		cout <<" =========================================================" << endl;  //showing the user the menu
		cout<< "Please select one of the menu option numbers." << endl;
		cout<< "1. Add a new course \n" << "2. Add a new student \n" << "3. Add a student to a course \n"
		<< "4. Add grades for a student in a course \n" << "5. Print a list of all grades for a student in a course \n"
		<< "6. Print a list of all students in a course \n" << "7. Compute the average for a student in a course \n" <<
		"8. Print a list of all courses \n" << "9. Print a list of all students \n" << "10. Compute the average for a course \n"
		<< "11. Store Grade Book (to a disk file) \n" << "12. Load Grade Book (from a disk file) \n" << "13. Exit Gradebook Program" << endl;
		cout <<" =========================================================" << endl;
		cin >> choice;

		switch(choice)  //switch used to open the different functions
		{
			case 1: addCourse(&course2);break;
			case 2: addStudent(&stud);break;
			case 3: addstudtocourse(&reg);break;
			case 4: addGradetostud(&reg);break;
			case 5: prtStudGrades(&reg);break;
			case 6: prtStudCourse(&reg,&stud);break;
			case 7: avgStudCourse(&reg);break;
			case 8: prtCourseList(&course2);break;
			case 9: prtStudList(&stud);break;
			case 10: avgCourse(&reg);break;
			case 11: storeBook(&stud,&course2,&reg);break;  
			case 12: loadBook(&stud,&course2,&reg);break;           
			case 13: exitprogram();break;
			default:
				cout << "Please enter a number corresponding to a menu choice." << endl;
				break;
		}
	} 
	delete(stud.studList);  //freeing the memory
	delete(reg.regList);
	delete(course2.courseList);

	return 0;
}

