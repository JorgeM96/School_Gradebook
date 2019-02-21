/* Author: Jorge Moreno
   Instructor: Dr. Keathley
   Date: 2/14/17
   Description: This is the header file for my structures. */

 
typedef struct student_info{   //1.Structure holds information about individual students
int sID;                //Holds the students ID number
std::string first;          //Holds the first name of the student
std::string last;            //Holds the last name of the student
int gradelvl;          //Holds the gradelvl of the student
}student;

typedef struct students_collection{   //2. Structure holds a collection of all students
int studCnt;   //Holds the amount of students enrolled
int studCap;   //Holds the max amount of students that can be enrolled.
student *studList;
}studentsC;

typedef struct course_info{   //3.Structure holds information about an individual course.
int Cnum;                     //Holds the course number
std::string Cname;                 //Holds the course name
std::string teacher;              //Holds the name of teacher in that course
}course;

typedef struct courses_collection{  //4.Structure holds a collection of all courses
int courseCnt;   //Holds the number of available courses
int courseCap;   //Holds the max amount of courses
course *courseList;
}coursesC;

typedef struct  registry{   //5.Structure holds information about a student and their course                 
int sIDs;                  //Holds students ID
int Cnums;                  //Holds course number
int *Grades;
int gradeCnt;
int gradeCap;
double gradeAvg;
}registry;

typedef struct registry_collection{   //6.Structure holds a collection of all registries.
int regCnt;             //Holds the number of registries
int regCap;              //Holds the limit of registries
registry *regList;
}registryC;

