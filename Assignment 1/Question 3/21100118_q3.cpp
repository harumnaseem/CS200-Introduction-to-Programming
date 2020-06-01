#include <iostream>
#include "ComplexNumber.cpp"

using namespace std;

int main()
{
    int ans;
    cout<<"Menu:"<<endl;
    cout<<"Enter 1 >> Assign"<<endl;
    cout<<"Enter 2 >> Add"<<endl;
    cout<<"Enter 3 >> Multiply"<<endl;
    cout<<"Enter 4 >> Print Number"<<endl;
    cout<<"Enter 5 >> Input Number"<<endl;

    cout<<endl<<"Choice:";
    cin>>ans;
    while(ans != 1 && ans !=2 && ans !=3 && ans !=4 && ans!=5)
    {
        cin.clear();
        cin.ignore(999999,'\n');
        cout<<"Invalid choice"<<endl<<"Enter choice again: ";
        cin>>ans;
    }
    ComplexNumber c1, c2, c3;
    if(ans == 1)
    {
        c1.Assign(c1);
        c1.PrintNumber();
    }
    else if(ans == 2)
    {
        c1.InputNumber();
        cout<<endl;
        c2.InputNumber();
        c3 = c1.Add(c2);
        cout<<endl;
        c3.PrintNumber();
    }
    else if(ans == 3)
    {
        c1.InputNumber();
        cout<<endl;
        c2.InputNumber();
        cout<<endl;
        c3 = c1.Multiply(c2);
        c3.PrintNumber();
    }
    else if(ans ==4 )
    {
        c1.InputNumber();
        cout<<endl;
        c1.PrintNumber();
    }
    else if(ans==5)
    {
         c1.InputNumber();
         cout<<endl;
         c1.PrintNumber();
    }


    return 0;
}


