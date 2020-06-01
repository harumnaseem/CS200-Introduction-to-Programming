#ifndef my_vector_H
#define my_vector_H
#include <iostream>
#include <vector>
using namespace std;

template <typename DataType>

class my_vector
{
    private:
        int Count;
        int Capacity;
        DataType* arr;
    public:
        my_vector();
        ~my_vector();
        int get_count();
        void set_count(int c);
        int get_capacity();
        void set_capacity(int c);
        DataType* get_arr();
        void set_arr(DataType* a);
        void Push_back(DataType x);
        DataType Pop_back();
        void Remove(DataType x);
        DataType& operator[](int index);
};


#endif

