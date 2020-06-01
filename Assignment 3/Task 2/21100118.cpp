#include <iostream>
using namespace std;
int Count =0;
int x = 1;
void recursive(int degree)
{
    if(Count != (degree + 1))
    {
     cout << " " << x;
     x = x * (degree - Count) / (Count + 1);
     Count++;
     recursive(degree);
    }
     else
        return;
}
int main()
{
int degree;
cout<<"Input: ";
cin>>degree;
int x=1;
cout<<"Output: ";
recursive(degree);
return 0;
}
