#ifndef myPolynomial_H
#define myPolynomial_H

class myPolynomial
{
	private:
		int terms;
		float* degreeArray;
		float* coeffArray;
	public:
		myPolynomial(); //Constructor
		~myPolynomial(); //Destructor
		myPolynomial(const myPolynomial& p); //Copy constructor

		//Setters
		void set_terms(int Terms);
		void set_degreeArray(float* DegreeArray);
		void set_coeffArray(float* CoeffArray);

        //Getters
		int get_terms();
		float* get_degreeArray();
		float* get_coeffArray();

        //Operator overloading
        void operator =(const myPolynomial& b);
        friend myPolynomial operator +(const myPolynomial& p1, const myPolynomial& p2);
        friend myPolynomial operator -(const myPolynomial& p1, const myPolynomial& p2);
        friend myPolynomial operator *(const myPolynomial& p1, const myPolynomial& p2);
        bool operator ==(const myPolynomial& b);
        //other functions
        void printPolynomial();
        void readFromfile();


};


#endif

