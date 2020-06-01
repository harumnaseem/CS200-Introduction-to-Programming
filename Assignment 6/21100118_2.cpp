#include <iostream>
#include "TimeFormatMistake.cpp"

using namespace std;

int main()
{
     while(true)
    {
        int hours, minutes;
        cout<<"24-hour notation:"<<endl;
        cout<<">>Enter hours: ";
        while( !(cin>>hours) )
        {
            cout<<"Not a valid input for hours!"<<endl<<endl;
            cin.clear();
            cin.ignore(999999,'\n');
            cout<<">>Enter hours again: ";
        }

        cout<<">>Enter minutes: ";
        while( !(cin>>minutes) )
        {
            cout<<"Not a valid input for minutes!"<<endl<<endl;
            cin.clear();
            cin.ignore(999999,'\n');
            cout<<">>Enter minutes again: ";
        }

        TimeFormatMistake e;
        try
        {
            if(hours > 24 || hours < 0 || minutes>60 || minutes<0)
            {
                throw e;
            }
            else
            {
                if(hours>12)
                {
                    hours = hours-12;
                    if(minutes<10)
                    {
                         cout<<">>That is the same as: "<<hours<<":0"<<minutes<<endl;
                    }
                    else
                    {
                        cout<<">>That is the same as: "<<hours<<":"<<minutes<<endl;
                    }

                }
                else if(hours <=12)
                {
                    if(minutes<10)
                    {
                         cout<<">>That is the same as: "<<hours<<":0"<<minutes<<endl;
                    }
                    else
                    {
                        cout<<">>That is the same as: "<<hours<<":"<<minutes<<endl;
                    }
                }
            }
        }
        catch(TimeFormatMistake em)
        {
            cout<<">>"<< em.get_error() << hours<<":"<<minutes<<"."<<endl;
        }
        string c;
        cout<<">>Enter -1 to exit or enter anything else to continue: ";
        cin>> c;
        if(c=="-1")
        {
            break;
        }

    }

    return 0;
}


