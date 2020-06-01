#include <iostream>
#include "myPolynomial.cpp"
using namespace std;

int main()
{
    myPolynomial a,b,c;
    bool terminate = false;
    bool a_defined = false;

    bool b_defined = false;
    bool c_defined = false;
    while(!terminate)
    {
        int choice;
        cout<<"MENU:"<<endl;
        cout<<">> Enter 0 to exit."<<endl;
        cout<<">> Enter 1 to Input polynomial A from file."<<endl;
        cout<<">> Enter 2 to Input polynomial B from file."<<endl;
        cout<<">> Enter 3 to Add polynomials A and B to get C."<<endl;
        cout<<">> Enter 4 to subtract polynomials A and B to get C."<<endl;
        cout<<">> Enter 5 to Multiply polynomials A and B to get C."<<endl;
        cout<<">> Enter 6 to print A."<<endl;
        cout<<">> Enter 7 to print B."<<endl;
        cout<<">> Enter 8 to print C."<<endl;
        cout<<">> Enter 9 to check A==B."<<endl;
        cout<<">> Enter 10 to do A=B."<<endl;
        cout<<endl<<"Your choice: ";
        while( !(cin>>choice) || (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10))
        {
            cout<<"Not a valid input!"<<endl<<endl;
            cin.clear();
 	        cin.ignore(999999,'\n');
 	        cout<<"Enter your choice again: ";
        }


        // input check

        if(choice == 0)
            break;

        else if(choice == 1)
        {
            cout<<endl;
            a.readFromfile();
            cout<<endl;
            a_defined = true;
        }

        else if(choice == 2)
        {
            cout<<endl;
            b.readFromfile();
            b_defined = true;
            cout<<endl;
        }

        else if(choice == 3)
        {
            if(!a_defined || !b_defined)
            {
                cout<<"A or B are not defined yet."<<endl;
                break;
            }

            c = a+b;
            c.printPolynomial();
            c_defined = true;
        }

        else if(choice == 4)
        {
            if(!a_defined || !b_defined)
            {
                cout<<"A or B are not defined yet."<<endl;
                break;
            }
            c = a-b;
            c.printPolynomial();
            c_defined = true;
        }

        else if(choice == 5)
        {
             if(!a_defined || !b_defined)
            {
                cout<<"A or B are not defined yet."<<endl;
                break;
            }
            //Multiply
            c_defined = true;
        }

        else if(choice == 6)
        {
            if(!a_defined)
            {
                cout<<"A has not been inputted from any file yet."<<endl;
            }
            else
            {
                a.printPolynomial();
            }
            cout<<endl;
        }

        else if(choice == 7)
        {
            if(!b_defined)
            {
                cout<<"B has not been inputted from any file yet."<<endl;
            }
            else
            {
                b.printPolynomial();
            }
            cout<<endl;
        }

        else if(choice == 8)
        {
            if(!b_defined)
            {
                cout<<"C has not been calculated and defined by any operation yet."<<endl;
            }
            else
            {
                c.printPolynomial();
            }
            cout<<endl;
        }

        else if(choice == 9)
        {
                bool equality = a==b;
                if (equality)
                {
                    cout<<endl<< "They are equal"<<endl;
                }

                else
                {
                    cout<<endl<< "They are not equal"<<endl;
                }
        }
        else if(choice == 10)
        {
                a = b;
                a.printPolynomial();
        }

        cout<<endl<<endl<<endl;
    }
    b.~myPolynomial();
    a.~myPolynomial();
    c.~myPolynomial();
    return 0;
}
