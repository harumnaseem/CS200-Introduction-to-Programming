#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "myPolynomial.h"

using namespace std;

myPolynomial::myPolynomial()
{
        terms = 0;
        degreeArray = NULL;
        coeffArray = NULL;
}

myPolynomial::~myPolynomial()
{
        delete[] degreeArray;
        delete[] coeffArray;
}

myPolynomial::myPolynomial(const myPolynomial& p)
{
        terms = p.terms;

        degreeArray = new float[terms];
        for(int i=0; i<terms; i++)
        {
            degreeArray[i] = p.degreeArray[i];
        }

        coeffArray = new float[terms];
        for(int i=0; i<terms; i++)
        {
            coeffArray[i] = p.coeffArray[i];
        }
}

void myPolynomial::set_terms(int Terms)
{
    terms = Terms;
}

void myPolynomial::set_degreeArray(float* DegreeArray)
{
    degreeArray = DegreeArray;
}

void myPolynomial::set_coeffArray(float* CoeffArray)
{
    coeffArray = CoeffArray;
}

int myPolynomial::get_terms()
{
    return terms;
}

float* myPolynomial::get_degreeArray()
{
    return degreeArray;
}

float* myPolynomial::get_coeffArray()
{
    return coeffArray;
}


void myPolynomial::operator =(const myPolynomial& b)
{
    terms = b.terms;
    degreeArray = new float[terms];
    coeffArray = new float[terms];

    for (int i = 0; i < terms; i++)
    {
        degreeArray[i] = b.degreeArray[i];
        coeffArray[i] = b.coeffArray[i];
    }
}


void myPolynomial::printPolynomial()
{

    int temp1, temp2;
    for (int i = 0; i < terms; i++)
    {
        for (int j = i+1; j < terms; j++)
        {
            if (degreeArray[i] < degreeArray[j])
            {
                temp1 = degreeArray[i];
                degreeArray[i] = degreeArray[j];
                degreeArray[j] = temp1;

                temp2 = coeffArray[i];
                coeffArray[i] = coeffArray[j];
                coeffArray[j] = temp2;
            }
        }
    }

    cout<<"Your polynomial is "<<endl;
    for(int i=0; i<terms; i++)
    {
        if(i==0)
        {
            cout<<coeffArray[i]<<"x^"<<degreeArray[i]<<" ";
        }
        else
        {
            if(coeffArray[i] < 0)
            {
                cout<<"- "<<abs(coeffArray[i])<<"x^"<<degreeArray[i]<<" ";
            }
            else
            {
                cout<<"+ "<<coeffArray[i]<<"x^"<<degreeArray[i]<<" ";
            }
        }
    }
}

void myPolynomial::readFromfile()
{
    ifstream student_file;
    string file_name;
    cout<<"Enter the name of your file: ";
    cin>>file_name;
    cout<<endl<<endl;
    file_name = file_name + ".txt";
    student_file.open(file_name.c_str());
    if(!student_file)
    {
        cout<<"Error! File cannot open."<<endl;
    }
    else
    {
        student_file >> terms;
        degreeArray = new float[terms];
        coeffArray = new float[terms];

        int Count = 0,i =0;
        float temp;

            for(int i=0; i<terms ; i++)
            {
                student_file >> temp;
                degreeArray[i] = temp;
            }

            for (int i = 0; i < terms; i++)
            {
                for (int j = i+1; j < terms; j++)
                {
                    if (degreeArray[i] < degreeArray[j])
                    {
                        temp = degreeArray[i];
                        degreeArray[i] = degreeArray[j];
                        degreeArray[j] = temp;
                    }
                }
            }
            for(int i =0; i<terms; i++)
            {
                student_file >> temp;
                coeffArray[i] = temp;
            }
        printPolynomial();

    }
}

bool myPolynomial::operator ==(const myPolynomial& b)
{
    bool equality = false;
    if (b.terms == terms)
    {
        for (int i = 0; i < terms; i++)
        {
            if (b.coeffArray[i] == coeffArray[i])
            {
                equality = true;
            }

            else
            {
                equality = false;
                break;
            }

            if (b.degreeArray[i] == degreeArray[i])
            {
                equality = true;
            }

            else
            {
                equality = false;
                break;
            }
        }
    }
    else
        equality = false;

    return equality;
}


myPolynomial operator -(const myPolynomial& p1, const myPolynomial& p2)
{
    myPolynomial temp;
    bool found = false;

    temp.terms = p1.terms;
    temp.degreeArray = new float[temp.terms];
    temp.coeffArray = new float[temp.terms];

    for (int i = 0; i < temp.terms; i++)
    {
        temp.degreeArray[i] = p1.degreeArray[i];
        temp.coeffArray[i] = p1.coeffArray[i];
    }

    for (int i = 0; i < p2.terms; i++)
    {
        for (int j = 0; j < temp.terms; j++)
        {
            if (p2.degreeArray[i] == temp.degreeArray[j])
            {
                temp.degreeArray[j] = p2.degreeArray[i];
                temp.coeffArray[j] = temp.coeffArray[j] - p2.coeffArray[j];
                found = true;
                break;
            }
        }
        if (!found)
        {
            float* temp2 = temp.degreeArray;
            temp.degreeArray = new float[temp.terms+1];

            for (int p = 0; p < temp.terms; p++)
            {
                temp.degreeArray[p] = temp2[p];
            }
            temp.degreeArray[temp.terms] = p2.degreeArray[i];

            temp2 = temp.coeffArray;
            temp.coeffArray = new float[temp.terms+1];
            for (int p = 0; p < temp.terms; p++)
            {
                temp.coeffArray[p] = temp2[p];
            }
            temp.coeffArray[temp.terms] = -p2.coeffArray[i];
            temp.terms++;
            delete[] temp2;
        }
        found = false;
    }

    return temp;
}


myPolynomial operator +(const myPolynomial& p1, const myPolynomial& p2)
{
    myPolynomial temp;
    bool found = false;

    if (p1.terms > p2.terms)
        {
            temp.terms = p1.terms;
            temp.degreeArray = new float[temp.terms];
            temp.coeffArray = new float[temp.terms];

            for (int i = 0; i < temp.terms; i++)
            {
                temp.degreeArray[i] = p1.degreeArray[i];
                temp.coeffArray[i] = p1.coeffArray[i];
            }

            for (int j = 0; j < p2.terms; j++)
            {
                for (int k = 0; k < temp.terms; k++)
                {
                    if (temp.degreeArray[k] == p2.degreeArray[j])
                    {
                        found= true;
                        temp.coeffArray[k] += p2.coeffArray[j];
                        break;
                    }
                }
                if (!found) //a certain degree present in p2 is not present in result
                {
                    float* temp2 = temp.degreeArray;
                    temp.degreeArray = new float[temp.terms+1];

                    for (int i = 0; i <temp.terms; i++)
                    {
                        temp.degreeArray[i] = temp2[i];
                    }
                    temp.degreeArray[temp.terms] = p2.degreeArray[j];

                    temp2 = temp.coeffArray;
                    temp.coeffArray = new float[temp.terms+1];
                    for (int l = 0; l < temp.terms; l++)
                    {
                        temp.coeffArray[l] = temp2[l];
                    }
                    temp.coeffArray[temp.terms] = p2.coeffArray[j];
                    temp.terms++;
                    delete[] temp2;
                }
                found = false;
            }
        }
    else if (p1.terms < p2.terms)
        {
            temp.terms = p2.terms;
            temp.degreeArray = new float[temp.terms];
            temp.coeffArray = new float[temp.terms];

            for (int i = 0; i < temp.terms; i++)
            {
                temp.degreeArray[i] = p2.degreeArray[i];
                temp.coeffArray[i] = p2.coeffArray[i];
            }

            for (int j = 0; j < p1.terms; j++)
            {
                for (int l = 0; l < temp.terms; l++)
                {
                    if (temp.degreeArray[l] == p1.degreeArray[j])
                    {
                        found = true;
                        temp.coeffArray[l] += p1.coeffArray[j];
                        break;
                    }
                }
                if (!found) //a certain degree present in p1 is not present in result
                {
                    float* temp2 = temp.degreeArray;
                    temp.degreeArray = new float[temp.terms+1];

                    for (int i = 0; i < temp.terms; i++)
                    {
                        temp.degreeArray[i] = temp2[i];
                    }
                    temp.degreeArray[temp.terms] = p1.degreeArray[j];

                    temp2 = temp.coeffArray;
                    temp.coeffArray = new float[temp.terms+1];
                    for (int k = 0; k < temp.terms; k++)
                    {
                        temp.coeffArray[k] = temp2[k];
                    }
                    temp.coeffArray[temp.terms] = p1.coeffArray[j];
                    temp.terms++;
                    delete[] temp2;
                }
                found = false;
            }
        }
    else
        {
            temp.terms = p1.terms;
            temp.degreeArray = new float[temp.terms];
            temp.coeffArray = new float[temp.terms];

            for (int i = 0; i < p1.terms; i++)
            {
                for (int j = 0; j < p2.terms; j++)
                {
                    if (p2.degreeArray[j] == p1.degreeArray[i])
                    {
                        found =true;
                        temp.degreeArray[i] = p2.degreeArray[j];
                        temp.coeffArray[i] = p1.coeffArray[i] + p2.coeffArray[j];
                        break;
                    }
                }
                if (!found)
                {
                    temp.degreeArray[i] = p1.degreeArray[i];
                    temp.coeffArray[i] = p1.coeffArray[i];
                }
                found = false;
            }


            for (int j = 0; j < p2.terms; j++)
            {
                for (int l = 0; l < temp.terms; l++)
                {
                    if (temp.degreeArray[l] == p2.degreeArray[l])
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    float* temp2 = temp.degreeArray;
                    temp.degreeArray = new float[temp.terms+1];

                    for (int k = 0; k < temp.terms; k++)
                    {
                        temp.degreeArray[k] = temp2[k];
                    }
                    temp.degreeArray[temp.terms] = p2.degreeArray[j];

                    temp2 = temp.coeffArray;
                    temp.coeffArray = new float[temp.terms+1];
                    for (int l = 0; l < temp.terms; l++)
                    {
                        temp.coeffArray[l] = temp2[l];
                    }
                    temp.coeffArray[temp.terms] = p2.coeffArray[j];
                    temp.terms++;
                    delete[] temp2;
                }
                found = false;
            }
        }

    return temp;
}
