#include <iostream>
#include "my_vector.h"

using namespace std;
#include <iostream>
#include <vector>
using namespace std;

template <typename DataType>


my_vector<DataType>::my_vector()
{
    Count = 0;
    Capacity = 0;
    arr = new DataType[0];
}
template <typename DataType>
my_vector<DataType>::~my_vector()
{
    delete arr;
}
template <typename DataType>
int my_vector<DataType>::get_count()
{
    return Count;
}
template <typename DataType>
void my_vector<DataType>::set_count(int c)
{
    Count = c;
}
template <typename DataType>
int my_vector<DataType>::get_capacity()
{
    return Capacity;
}
template <typename DataType>
void my_vector<DataType>::set_capacity(int c)
{
    Capacity = c;
}
template <typename DataType>
DataType* my_vector<DataType>::get_arr()
{
    return arr;
}
template <typename DataType>
void my_vector<DataType>::set_arr(DataType* a)
{
    arr = a;
}
template <typename DataType>
void my_vector<DataType>::Push_back(DataType x)
{
    if(Count > Capacity)
    {
        DataType* arr1 = new DataType[Capacity+2];
        for(int i=0; i<=Capacity; i++)
        {
            arr1[i] = arr[i];
        }

        Capacity++;
        delete arr;

        for(int i = 0; i<=Capacity;i++)
        {
            arr[i] = arr1[i];
        }

        delete arr1;
    }

    arr[Count] = x;
    Count++;
}
template <typename DataType>
DataType my_vector<DataType>::Pop_back()
{
    DataType x = arr[Capacity];
    Capacity--;
    DataType* arr1 = new DataType[Capacity+1];

    for(int i=0; i<=Capacity; i++)
    {
        arr1[i] = arr[i];
    }

    arr = new DataType[Count];

    for(int i=0; i<=Capacity; i++)
    {
        arr[i] = arr1[i];
    }

    delete arr1;
    Count--;
    return x;
}
template <typename DataType>
void my_vector<DataType>::Remove(DataType x)
{
    for(int i=0; i<=Count; i++)
    {
        if(arr[i]==x)
        {
            if(i==Count)
            {
                arr[Count] = 0;
            }
            else
            {
                for(; i<=Count; i++)
                {
                    arr[i] = arr[i+1];
                    arr[Count] = 0;
                }
            }

            break;
        }
    }


}
template <typename DataType>
DataType& my_vector<DataType>::operator[](int index)
{
    return arr[index];
}



