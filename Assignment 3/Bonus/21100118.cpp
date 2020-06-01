#include <iostream>
using namespace std;

int Sum =0;
int Count =0;
int recursive(int x, int y)
{
    if(Count != x)
    {
        Sum +=y;
        Count++;
        recursive(x,y);

    }
    else
        return Sum;


}
int main()
{
    int x,y;
    cout<<"Enter your first number: ";
    cin>>x;
    cout<<"Enter your second number: ";
    cin>>y;
    cout<<endl<<"Your answer is "<<recursive(x,y);


return 0;

}
