#ifndef ComplexNumber_H
#define Complex_Number_H

class ComplexNumber
{
	private:
		double Real;
		double Imaginary;
	public:
		ComplexNumber();
		double GetReal();
		double GetImaginary();
		void SetReal(double r);
		void SetImaginary(double i);
		ComplexNumber Add(ComplexNumber c);
		ComplexNumber Multiply(ComplexNumber c);
		void PrintNumber();
		void Assign(ComplexNumber c);
		void InputNumber();

};


#endif
