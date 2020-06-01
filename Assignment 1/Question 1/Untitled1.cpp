#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Students
{
private:
    string name;
    double roll_number;
    double marks;
    char grade;

public:
    string get_name();
    int get_rollnumber();
    double get_marks();
    char get_grade();
    void set_name(string n);
    void set_rollnumber(int r);
    void set_marks(double m);
    void set_grade(char g);
};

void inputStudentInfo(ifstream& student_file, Students list_of_students[], int SIZE)
{
    int student_count =0;
    list_of_students[50];

    string name;
    int rollnumber;
    double marks;


    while(!student_file.eof())
    {
        student_file >> name >> rollnumber >> marks;

        list_of_students[student_count].set_name(name);
        list_of_students[student_count].set_rollnumber(rollnumber);
        list_of_students[student_count].set_marks(marks);


        student_count++;
    }
}

void sortMarks(ifstream& student_file, Students list_of_students[], int SIZE)
{
    int minimum_value_index = 0;
    Students temp_student;
    for(int i=0; i < SIZE; i++)
    {
        for(int k = i + 1; k < SIZE; k++)
        {
            if(list_of_students[k].get_marks() < list_of_students[i].get_marks())
            {
                temp_student = list_of_students[i];
                list_of_students[i]= list_of_students[k];
                list_of_students[k]= temp_student;
            }
        }
    }
}

void assignGrades(ifstream& student_file, Students list_of_students[], int SIZE)
{
    char grade;
        for(int i=0; i<SIZE; i++)
        {
            if(list_of_students[i].get_marks()>= 85)
            {
                grade='A';
                list_of_students[i].set_grade(grade);
            }
            else if(list_of_students[i].get_marks()>=75 && list_of_students[i].get_marks()<85)
            {
                grade='B';
                list_of_students[i].set_grade(grade);
            }
            else if(list_of_students[i].get_marks()>=65 && list_of_students[i].get_marks()<75)
            {
                grade='C';
                list_of_students[i].set_grade(grade);
            }
            else if(list_of_students[i].get_marks()>=50 && list_of_students[i].get_marks()<65)
            {
                grade='D';
                list_of_students[i].set_grade(grade);
            }
            else
            {
                grade='F';
                list_of_students[i].set_grade(grade);
            }
        }
}

void writeToFile(ofstream& final_file,Students list_of_students[], int SIZE)
{
    for(int i=0; i<SIZE; i++)
    {
        final_file << list_of_students[i].get_name() << "\t \t" << list_of_students[i].get_rollnumber() << "\t \t"<< list_of_students[i].get_marks() <<"\t \t"<< list_of_students[i].get_grade() << endl;
    }
}

int main()
{
    ifstream student_file;
    Students list_of_students[50];

    student_file.open("q1-students.txt");

    if(!student_file)
        cout<<"Error! File cannot open."<<endl;

    inputStudentInfo(student_file, list_of_students, 50);

    sortMarks(student_file, list_of_students, 50);

    assignGrades(student_file,list_of_students, 50);

    student_file.close();

    ofstream final_file;
    final_file.open("data.txt");

    if(!final_file)
    {
        cout<<"Error"<<endl;
    }

    writeToFile(final_file, list_of_students, 50);

    final_file.close();




return 0;
}

string Students::get_name()
{
    return name;
}

int Students::get_rollnumber()
{
    return roll_number;
}

double Students::get_marks()
{
    return marks;
}

char Students::get_grade()
{
    return grade;
}

void Students::set_name(string n)
{
    name = n;
}

void Students::set_rollnumber(int r)
{
    roll_number = r;
}

void Students::set_marks(double m)
{
    marks = m;
}

void Students::set_grade(char g)
{
    grade = g;
}
