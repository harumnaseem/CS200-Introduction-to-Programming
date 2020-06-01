#include <iostream>
#include "my_vector.cpp"

using namespace std;

int main()
{
    int l;
    my_vector<int> v;
    int Size;
    cout<<"Enter the size of your vector: ";
    cin>>Size;
    cout<<endl<<endl;
    for(int i=0; i<Size; i++)
    {
        cout<<"Enter the "<< i<<"th index: ";
        cin>> l;
        v.Push_back(l);
        cout<<*(v.get_arr() + i)<<" ";
    }

    int k;
    cout<<endl<<"Enter a number you want to delete: ";
    cin>>k;
    v.Remove(k);
    for(int i=0; i<Size;i++)
    {
        if(i==Size-1)
        {
            cout<<0<<" ";
        }
        else
            cout<< *(v.get_arr() + i)<<" ";
    }
    cout<<endl<<"Pop called for all elements: "<<endl;
    for(int i=0; i<Size; i++)
    {
        if(i==0)
        {
            v.Pop_back();
            cout<<0<<" ";
        }
        else
        {
            cout<< v.Pop_back()<<" ";
        }

    }

    return 0;
}


