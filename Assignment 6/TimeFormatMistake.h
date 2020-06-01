#ifndef TimeFormatMistake_H
#define TimeFormatMistake_H
#include <iostream>
#include <string>
using namespace std;
class TimeFormatMistake{
	 private:
        string error_message;
    public:
        TimeFormatMistake();
        void set_error(string e);
        string get_error();
};


#endif

