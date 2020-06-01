#include <iostream>
#include "ComplexNumber.h"

using namespace std;

ComplexNumber::ComplexNumber()
{
    Real=0;
    Imaginary=0;
}

double ComplexNumber::GetReal()
{
    return Real;
}

double ComplexNumber::GetImaginary()
{
    return Imaginary;
}

void ComplexNumber::SetReal(double r)
{
    Real = r;
}

void ComplexNumber::SetImaginary(double i)
{
    Imaginary = i;
}

ComplexNumber ComplexNumber::Add(ComplexNumber c)
{
    ComplexNumber sum;
    double Real= GetReal() + c.Real;
    sum.SetReal(Real);
    double Imaginary= GetImaginary() + c.Imaginary;
    sum.SetImaginary(Imaginary);

    return sum;
}

ComplexNumber ComplexNumber::Multiply(ComplexNumber c)
{
    ComplexNumber product;
    double real = (GetReal() * c.Real) - (GetImaginary() * c.Imaginary);
    product.SetReal(real);
    double imaginary = (GetReal() * c.Imaginary) + (GetImaginary() * c.Real);
    product.SetImaginary(imaginary);

    return product;
}

void ComplexNumber::PrintNumber()
{
    if(Imaginary < 0)
    {
        cout<< Real <<" - i"<< -1* Imaginary<<endl;
    }
    else
    {
        cout<< Real <<" + i"<< Imaginary<<endl;
    }
}
void ComplexNumber::Assign(ComplexNumber c)
{
    SetImaginary(3);
    SetReal(5);
}

void ComplexNumber::InputNumber()
{
    double real, imaginary;
    cout<<"Enter the Real part: ";
    cin>> real;
    SetReal(real);
    cout<<endl<<"Enter the Imaginary part: ";
    cin>> imaginary;
    SetImaginary(imaginary);
}


