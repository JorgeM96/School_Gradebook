/* Author: Jorge Moreno
   Instructor: Dr. Keathly
   Date: 2/14/17
   Description: This cpp file holds my functions. */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "structures1.h"
using namespace std;

const int MEMORYBLOCK = 25;

void addCourse(coursesC * course2)  //1. This function adds a new course.
{
        if(course2->courseCnt == course2->courseCap)  //This if statement checks if the course count is equal to the coursecap which then it will reallocate memory.
        {
                course *temp;
                temp = new course[course2->courseCap+MEMORYBLOCK];
                for(int i=0; i < course2->courseCnt; i++)        //This for loop is used to put the data in the old array into the new one then delete the old one.
                {
                        temp[i]=course2->courseList[i];
                }
                course2->courseList=temp;
		delete[] temp;
                course2->courseCap+=MEMORYBLOCK;
        }
        cout << "Please enter the new course number:" << endl;  //User enters the new course id
        cin >>  (course2->courseList[course2->courseCnt].Cnum);
        cout << "Please enter the new course name: " << endl;  //User enters the new course name
        cin >> (course2->courseList[course2->courseCnt].Cname);
        cout << "Please enter the instructor's name:" << endl;  //User enters the new instructor name
        cin >> (course2->courseList[course2->courseCnt].teacher);
        course2->courseCnt +=1;  //increment the course count by 1 each time a new one is added.
}

void addStudent(studentsC * stud)  //2. This function adds a new student 
{
        if(stud->studCnt == stud->studCap) //This if statement checks if the student count is equal to the student capacity so then reallocation can occur 
        {
                student *temp;
                temp = new student[stud->studCap+MEMORYBLOCK];
                for(int j=0; j < stud->studCnt; j++)  //This for loop moves the data from studlist to the temp pointer and then will free temp and update the new size
                {
                        temp[j]=stud->studList[j];
                }
                stud->studList=temp;
		delete[] temp;
                stud->studCap+=MEMORYBLOCK;
        }
        cout << "Please enter your student's ID number:" << endl;   //User enters the new student
        cin >> (stud->studList[stud->studCnt].sID);
        cout << "Please enter the students first name:" << endl;   //User enters the new student's first name
        cin >> (stud->studList[stud->studCnt].first);
        cout << "Please enter the students last name:" << endl;   //User enters the new student's last name
        cin >> (stud->studList[stud->studCnt].last);
        cout << "Please enter the students gradelvl(number):" << endl;  //User enters the new student's gradelvl
        cin >> (stud->studList[stud->studCnt].gradelvl);
        stud->studCnt +=1;  //Increment the student count by 1 each time a new student is added
}

void addstudtocourse(registryC * reg)  //3. This function adds a student to a course
{
        if(reg->regCnt == reg->regCap)  //This if statement checks if the registry count is equal to the registry capacity and will reallocate memory
        {
                registry *temp;
                temp = new registry[reg->regCap+MEMORYBLOCK];
                for(int k=0; k < reg->regCnt; k++)  //this for loop will add the data in reglist into the temp and then delete temp
                {
                        temp[k]=reg->regList[k];   
                }
                reg->regList=temp;
		delete[] temp;
                reg->regCap+=MEMORYBLOCK;
        }
        cout << "Enter the student ID:" << endl; //User enters their student id
        cin >> (reg->regList[reg->regCnt].sIDs);
        cout << "Enter the course ID:" << endl;  //User enters their course id
        cin >> (reg->regList[reg->regCnt].Cnums);
        (reg->regList[reg->regCnt].gradeCnt)=0;  //Initialize the students grade count to 0 at first
        (reg->regList[reg->regCnt].gradeCap)=MEMORYBLOCK;   //Set the gradecap to the memory size
        reg->regCnt+=1;  //increment the registry count by 1 each time theres a new registry made
}

void addGradetostud(registryC * reg) //4. This function adds grades to a student for a specific course
{
        int choice2;    //This variable is used for the while loop
        int studid;    //Temporary studentid variable 
        int courseid;    //temporary courseid variable
        int i;    //counter variable
        int j=0;    //counter variable
        double totalgrades=0;
        cout << "Enter the student's ID:" << endl;  //User enters their student ID
        cin >> studid;
        cout << "Enter the student's course ID:" << endl;  //User enters their course ID
        cin >> courseid;
        for(i=0;i< reg->regCnt; i++)     //for loop that stops when it reaches the reg count
        {
                if(reg->regList[i].sIDs == studid && reg->regList[i].Cnums == courseid)  //Checks if the entered user and couse id matches what has been entered
                {
                        reg->regList[i].Grades = new int[reg->regList[i].gradeCap];  //Allocating memory for the grades
                        while(choice2 !=2)
                        {
                                if(reg->regList[i].gradeCnt == reg->regList[i].gradeCap) //Checking if grade count is the same as grade cap and then reallocate memory
                                {
                                        registry *temp;  //temp pointer for registry
                                        temp = new registry[reg->regList[i].gradeCap+MEMORYBLOCK];  
                                        for(int j=0;j< reg->regList[i].gradeCap;j++)  //For loop to move data for reglist into temp
                                        {
                                                temp[j]=reg->regList[j];
                                        }
                                        reg->regList=temp;
                                        delete[] temp;
                                        reg->regList[i].gradeCap+MEMORYBLOCK;
                                }
                                cout << "Please enter your new grade for this course." << endl;  //User enters new grade for their course
                                cin >> reg->regList[i].Grades[j];
                                totalgrades+= reg->regList[i].Grades[j];  //This is used to find the average used for another function
                                j++;  //updates a counter
                                reg->regList[i].gradeCnt+=1;  //implements the grade count by 1 every time a new grade is added
                                cout << "Do you want to add another grade? Press 1 for yes or 2 for no." << endl;  //Asks user if they wish to add another grade
                                cin >> choice2;  //User enters 1 to add a new grade or 2 if not
                        }
                }
        }
	reg->regList[i].gradeAvg=totalgrades/j;  //Keeps a grade average for the student
        cout << "Your average grade for this course at the moment is: " << reg->regList[i].gradeAvg << endl;
}

void prtStudGrades(registryC * reg)  //5. This function prints the grades for a student in a course
{
        int i=0;  //counter variable
        int j=0;  //counter variable
        int studid;   //temporary studentid variable
        int courseid;  //temporary courseid variable
        cout << "What is your course ID: ?" << endl;  //Ask user to input their course id
        cin >> courseid;
        cout << "What is your student ID: " << endl;  //Ask user to input their student id
        cin >> studid;
        for(i=0;i < reg->regCnt; i++)  //for loop that ends when it reaches the reg count
        {
                if(reg->regList[i].Cnums == courseid && reg->regList[i].sIDs == studid)  //if statement to check if the user entered course/student id is the same in the reg
                {

                      	cout << "These are the grades for student ID:" << reg->regList[i].sIDs <<  endl;   //Outputs the students grades
                        for(j=0;j< reg->regList[i].gradeCnt;j++)
                        {
                                cout << "Grade # " << j+1 << ":" << reg->regList[i].Grades[j] << endl;
                        }
                }
        }
}

void prtStudCourse(registryC * reg, studentsC * stud) //6. This function prints the students in a course
{
        int courseid;  //temp courseid variable
        int i;  //counter variable
        int j;  //counter variable
        cout << "Enter the course ID to see students who've enrolled." << endl;  //User enters the course id
        cin >> courseid;
        cout << "The students in this course are: " << endl;  
        for(int i=0;i< reg->regCnt;i++)   //For loop stops when it reaches the reg count
        {
                if(reg->regList[i].Cnums == courseid)  //Checks if the course id entered is the same one saved in the reglist
                {
                        for(int j=0;j< stud->studCnt;j++)
                        {
                                if(reg->regList[i].sIDs == stud->studList[j].sID)  //Checks if the same student id is the same as the one for the individual struct
                                {

                                        cout << "Student # " << i+1 << ": " << endl;
                                        cout << "Student's ID: ";
                                        cout << stud->studList[j].sID << endl;  //  Ouputs the student id
                                        cout << "Student's First Name: " << stud->studList[j].first << endl;  //output the student's first name
                                        cout << "Student's Last Name: " << stud->studList[j].last << endl;   //output the students's last name
                                }
                        }
                }
        }
}

void avgStudCourse(registryC * reg) //7. This function averages the grade for a student in a course
{
        int studid;  //temp student id variable
        int i;  //counter variable
        int j;   //counter variable
        int courseid;  //temp course id variable
        double gradeT;  //variable to hold the count of all the grades added
        cout << "Enter the course ID: " << endl;  //User enters the course id
        cin >> courseid;
        cout << "Enter the student ID: " << endl;  //User enters the student id
        cin >> studid;
        for(i=0;i < reg->regCnt; i++)  //for loop that ends when it reaches the reg count
        {
                if(reg->regList[i].Cnums == courseid && reg->regList[i].sIDs == studid)  //Checks if the entered course/student id is the same thats in the registry
                {
                        for(j=0;j< reg->regList[i].gradeCnt;j++)
                        {
                                gradeT += reg->regList[i].Grades[j];  //Keeps a counter off the grades added up
                        }
                        reg->regList[i].gradeAvg=gradeT/reg->regList[i].gradeCnt;  //Gets the students average for that course
                        cout << "Your average in this course is: " << reg->regList[i].gradeAvg;
                }
        }
}

void prtCourseList(coursesC * course2) //8. This function prints out all the courses that have been added to the gradebook
{
        for(int i=0;i < course2->courseCnt;i++)  //For Loop that ends when it reaches the course count
        {
                cout << "Course ID #"<< i+1 << ": " << course2->courseList[i].Cnum << endl;  //Outputs the course ID
                cout << "Course Name #" << i+1 <<": " << course2->courseList[i].Cname << endl;  //Outputs the course name
                cout << "Course Teacher: " << course2->courseList[i].teacher << endl;  //Outputs the course teacher
                cout << endl;
        }
}

void prtStudList(studentsC * stud) //9. This function prints out all the students that have been added to the gradebook
{
        for(int j=0;j < stud->studCnt ;j++)  //For loop that ends when it reaches the student count
        {
                cout << "Student ID #"<< j+1 << ": " << stud->studList[j].sID << endl;  //outputs the student id
                cout << "Student's First Name: " << stud->studList[j].first << endl;  //outputs the student's first name
                cout << "Student's Last Name: " << stud->studList[j].last << endl;  //outputs the students last name
                cout << "Student's Grade level: " << stud->studList[j].gradelvl << endl;  //outputs the students gradelvl
                cout << endl;
        }
}

void avgCourse(registryC * reg) //10. This function finds the average for all the grades in a course
{
        int courseid;  //temp course id variable
        int i;  //cunter variable
        int j;  //counter variable
        int k=0;  //counter variable
        double courseAverage=0;  //set the course average to 0
        double totalAverage=0;  //set totalgrade average to 0
        double gradeT=0;
        double average=0;
        cout << "Enter Course ID" << endl;  //User enters the course ID
        cin >> courseid;  //user enters their course id
        for(i=0;i < reg->regCnt;i++)
        {
                if(reg->regList[i].Cnums == courseid)  //Checks if the user inputted courseid is the same as in the reg
                {
                        for(j=0; j < reg->regList[i].gradeCnt;j++)
                        {

                                gradeT += reg->regList[i].Grades[j]; //counts up all the grades
                        }
                        average = gradeT/reg->regList[i].gradeCnt;  //finds the average for each student
                        totalAverage +=average;  //finds the total average
                        gradeT=0;
                        average=0;
                        k++;  //increments k
                }
        }
        courseAverage = totalAverage/k;  //gets th course average
        cout << "The Average  for this course is: " << courseAverage << endl;
}

void storeBook(studentsC * stud, coursesC * course2, registryC * reg)  //11. This function stores the data to a text file named Gradebook
{
        ofstream fout;  //fout is an ofstream variable
        int i,j;  //counter variables

        cout << "Opening file: Gradebook.txt" << endl;

        fout.open("Gradebook.txt");  //opens the file
        if(fout.fail())  //checking if the file fails to open
        {
                cout << "Unable to save to this file!" << endl;
                exit(EXIT_FAILURE);
        }
        cout << "Output file opened." << endl;

        //save course info
	fout << course2->courseCnt << endl;  //stores the course count
        for(i=0;i< course2->courseCnt;i++)
        {
                fout << course2->courseList[i].Cnum;  //this stores the course number
                fout << " ";
                fout << course2->courseList[i].Cname;  //this stores the course name
                fout << " ";
                fout << course2->courseList[i].teacher;  //this stores the course teacher
                fout << endl;
        }
        //save student info
	fout << stud->studCnt << endl;  //stores the student count
        for(i=0;i< stud->studCnt;i++)
        {
                fout << stud->studList[i].sID; //this stores the students id
                fout << " ";
                fout << stud->studList[i].first;  //this stores the student's first name
		fout << " ";
                fout << stud->studList[i].last;  //this stores the student's last name
                fout << " ";
                fout << stud->studList[i].gradelvl;  //this stores the students gradelvl
                fout << endl;
        }
        //save registry information
	fout << reg->regCnt << endl;   //stores the registry count
	for(i=0;i < reg->regCnt; i++)
	{
		fout << reg->regList[i].sIDs;  //this stores the student ids
		fout << " ";
		fout << reg->regList[i].Cnums;  //this stores the course numbers
		fout << " ";
		fout << reg->regList[i].gradeCnt;  //this stores the grade count
		fout << " ";
		fout << reg->regList[i].gradeCap;  //this stores the grade cap
		fout << endl;
		
		for(j=0;j< reg->regList[i].gradeCnt;j++)  //for loop to store all the grades
		{
			fout << reg->regList[i].Grades[j];
			fout << " ";
		}
		fout << reg->regList[i].gradeAvg;
		fout << " ";
	}
	
        fout.close();   //close the file
        cout << "Gradebook has been saved to file: Gradebook.txt" << endl;
        cout << "Use the Load menu option to open this file." << endl;
}

void loadBook(studentsC * stud,coursesC * course2, registryC * reg) //12. This function reads in the grades from the textfile 
{
        ifstream fin;  //ifstream variable named fin
        int i,j;  //counter variables
        int count=0;  

        cout << "Opening file: Gradebook.txt" << endl;

        fin.open("Gradebook.txt");  //opening the file Gradebook
        if(fin.fail())  //Checking if the file failed to open
        {
                cout << "Unable to open this file!" << endl;
                exit(EXIT_FAILURE);
        }
        cout << "Input file opened: Gradebook.txt" << endl;

        //reads in course info
	fin >> course2->courseCnt;  //reads in the course count
	if(course2->courseCnt == course2->courseCap)  //This if statement check if reallocation needs to occur
	{
		course *temp;
		temp = new course[course2->courseCap+MEMORYBLOCK];
		for(i=0;i< course2->courseCnt;i++)
		{
			temp[i]=course2->courseList[i];
		}
		course2->courseList=temp;
		delete[] temp;
		course2->courseCap+=MEMORYBLOCK;
	}
        for(i=0;i< course2->courseCnt;i++)
        {
                fin >> course2->courseList[i].Cnum;  //this reads in the course number
                fin >> course2->courseList[i].Cname;  //this reads in the course name
                fin >> course2->courseList[i].teacher;  //this reads in the course teacher
        }
        //reads in student info
	fin >> stud->studCnt;  //This reads in the student count
	if(stud->studCnt == stud->studCap)  //This if statement checks if reallocation needs to occur
	{
		student *temp;
		temp = new student[stud->studCap+MEMORYBLOCK];
		for(j=0;j< stud->studCnt; j++)
		{
			temp[j]=stud->studList[j];
		}
		stud->studList=temp;
		delete[] temp;
		stud->studCap+=MEMORYBLOCK;
	}
        for(i=0;i< stud->studCnt;i++)
        {
                fin >> stud->studList[i].sID;  //this reads in the students id
                fin >> stud->studList[i].first;  //this reads in the student first name
		fin >> stud->studList[i].last;  //this reads in the student's last name
                fin >> stud->studList[i].gradelvl;  //this reads in the gradelvl
        }
        //reads in  the registry information
	fin >> reg->regCnt;  //this reads in the reg count
	for(i=0;i< reg->regCnt;i++)
	{
		fin >> reg->regList[i].sIDs;  //this reads in the student ids
		fin >> reg->regList[i].Cnums;  //this reads in the course numbers
		fin >> reg->regList[i].gradeCnt;  //this reads in the grade count
		fin >> reg->regList[i].gradeCap;  //this reads in the gradecap
		
		reg->regList[i].Grades = new int[reg->regList[i].gradeCap];
		for(j=0;j< reg->regList[i].gradeCnt;j++)
		{
			fin >> reg->regList[i].Grades[j];
		}
		fin >> reg->regList[i].gradeAvg;
	}
        fin.close();
        cout << "Gradebook has successfully been opened." << endl;
}

void exitprogram() //13. This function gives the user the option to end the program
{
        cout << "Gradebook will now close." << endl;
        exit(EXIT_FAILURE);
}


