#include <iostream>
#include "TimeFormatMistake.h"

using namespace std;


TimeFormatMistake::TimeFormatMistake()
{
    error_message = "There is no such time as ";
}

void TimeFormatMistake::set_error(string e)
{
    error_message = e;
}

string TimeFormatMistake::get_error()
{
    return error_message;
}
