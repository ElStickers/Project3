#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "activity.h"

using namespace std;

int Menu(vector<Course> *ptr)
{
	int choice;

	bool stop = false;

	while (stop == false)
	{
		cout << endl;

		cout << "Course Management System" << endl;

		cout << "1) Add a new course" << endl;

		cout << "2) Add a new student" << endl;

		cout << "3) Display all the courses" << endl;

		cout << "4) Display all the students with in a course" << endl;

		cout << "5) Remove a course" << endl;

		cout << "6) Remove a student withing a course" << endl;

		cout << "7) Exit" << endl;

		cin >> choice;

		cin.ignore();

		switch (choice)
		{
		case 1:
		{
			AddCourse(ptr);

			break;
		}

		case 2:
		{
			AddStudent(ptr);

			break;
		}

		case 3:
		{
			PrintCourse(ptr);

			break;
		}

		case 7:
		{
			Quit(stop);

			break;
		}

		default:
		{
			break;
		}
		}

	}

	return 0;
}

void AddCourse(vector<Course> *ptr)
{
	Course *newCourse = nullptr;

	cout << "Enter course name." << endl;

	string newClass;

	getline(cin, newClass);

	int units;

	cout << "Enter number of units." << endl;

	cin >> units;

	cout << "Adding Course" << endl << endl;

	newCourse = new Course(newClass, units);

	ptr->push_back(*newCourse);
}

void AddStudent(vector<Course> *ptr)
{
	string course;

	int newStudentID;

	string newStudentName;

	cout << "Enter course name." << endl;

	getline(cin, course);

	cout << "Enter student ID." << endl;

	cin >> newStudentID;

	cin.ignore();

	cout << "Enter student name." << endl;

	getline(cin, newStudentName);

	Student *newStudent = nullptr;

	newStudent = new Student(newStudentID, newStudentName);

	for (int i = 0; i < ptr->size(); i++)
	{
		if (ptr->at(i).getName() == course)
		{
			//ptr->at(i)push_back(*newStudent);
		}
		else
		{
			cout << "No class match input." << endl;
		}
	}



}
void PrintCourse(vector<Course> *ptr)
{
	//int size = ptr->size();

	cout << "Found" << ptr->size() << "course(s)." << endl;

	for (int i = 0; i < ptr->size(); i++)
	{
		string temp = ptr->at(i).getName();

		cout << "courseName = " << temp << endl;
	}

	cout << endl;
}

void Quit(bool &access)
{
	cout << "Come back again!" << endl;

	cin.ignore();

	access = true;
}