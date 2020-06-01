#include <iostream>
#include "task2.h"
#include <string>
#include <cmath>
using namespace std;

Date::Date()
{
    time = 0;
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(int Day, int Month, int Year, int Time)
{
    day = Day;
    month = Month;
    year = Year;
    time = Time;
}

void Date::set_year(int y)
{
    year = y;
}

int Date::get_year()
{
    return year;
}

void Date::set_time(int t)
{
    time = t;
}

int Date::get_time()
{
    return time;
}

void Date::set_month(int m)
{
    month = m;
}

int Date::get_month()
{
    return month;
}

void Date::set_day(int d)
{
    day = d;
}

int Date::get_day()
{
    return day;
}


Appointment::Appointment()
{
    description ="/0";
    d.set_time(0);
    d.set_year(0);
    d.set_month(0);
    d.set_day(0);
}

void Appointment::set_description(string d)
{
    description = d;
}

string Appointment::get_description() const
{
    return description;
}

void Appointment::set_date(Date x)
{
    d.set_year(x.get_year());
    d.set_time(x.get_time());
    d.set_month(x.get_month());
    d.set_day(x.get_day());
    d = x;
}

Date Appointment::get_date() const
{
    return d;
}


Onetime::~Onetime()
{
    delete this;
}

bool Onetime::occurs_on(int Year, int Month, int Day)
{
    if(Year == get_date().get_year() && Month == get_date().get_month() && Day == get_date().get_day())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Onetime::Onetime(string s, Date d)
{
    type = 'o';
    set_description(s);
    set_date(d);
}

void Onetime::operator =(const Onetime& O)
{
    set_description(O.get_description());
    set_date(O.get_date());
}


Daily::~Daily()
{
    delete this;
}

Daily::Daily(string s, Date d)
{
    type = 'd';
    set_description(s);
    set_date(d);
}

bool Daily::occurs_on(int Year, int Month, int Day)
{
    if(Month > get_date().get_month() && Year == get_date().get_year())
    {
        return 1;
    }
    else if(Month == get_date().get_month() && Day >= get_date().get_day())
    {
        return 1;
    }
    else if(Year > get_date().get_year())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Daily::Daily(int Year, int Month, int Day, int Time)
{
    get_date().set_year(Year);
    get_date().set_month(Month);
    get_date().set_time(Time);
    get_date().set_day(Day);
}

void Daily::operator =(const Daily& d)
{
    set_description(d.get_description());
    set_date(d.get_date());
}


Weekly::~Weekly()
{
    delete this;
}

Weekly::Weekly(string s, Date d)
{
    type = 'w';
    set_description(s);
    set_date(d);
}

bool Weekly::occurs_on(int Year, int Month, int Day)
{

    if(Year == get_date().get_year() && Month == get_date().get_month())
    {
        for(int i=0; 31>= i+get_date().get_day(); i= i+7)
        {
            if(Day == i+get_date().get_day())
            {
                return 1;
            }
        }
    }
    else if(Year >= get_date().get_year())
    {
        double temp;
        temp = abs(get_date().get_day()- Day);
        if(Day == get_date().get_day())
        {
            return 1;
        }
        if(fmod(temp,7.0) == 0)
        {
            return 1;
        }
        else
            return 0;
    }

    return 0;
    /*

    int array_of_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int m = get_date().get_month();
    int d = get_date().get_day();
    for(int i= d; m < Month; m++)
    {
        while(1)
        {
            d = d + 7;;

            if(d >= array_of_months[m-1])
            {
                d = d - array_of_months[m-1];
                break;
            }
        }
    }
    int x = Day - d;
    if(fmod(x,7.0) == 0)
    {
        return 1;
    }

    return 0;
    */
}

Weekly::Weekly(int Year, int Month, int Day, int Time)
{
    get_date().set_year(Year);
    get_date().set_month(Month);
    get_date().set_time(Time);
    get_date().set_day(Day);
}

void Weekly::operator =(const Weekly& w)
{
    set_description(w.get_description());
    set_date(w.get_date());
}


Monthly::~Monthly()
{
    delete this;
}

Monthly::Monthly(string s, Date d)
{
    type = 'm';
    set_description(s);
    set_date(d);
}

bool Monthly::occurs_on(int Year, int Month, int Day)
{
    if(Year == get_date().get_year() && Month >= get_date().get_month() && Day == get_date().get_day())
    {
        return 1;
    }
    else if(Year > get_date().get_year() && Day == get_date().get_day())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Monthly::Monthly(int Year, int Month, int Day, int Time)
{
    get_date().set_year(Year);
    get_date().set_month(Month);
    get_date().set_time(Time);
    get_date().set_day(Day);
}

void Monthly::operator =(const Monthly& m)
{
    set_description(m.get_description());
    set_date(m.get_date());
}


void test_function()
{
    int SIZE;
    cout<<"Enter the number of appointments you want to register: ";
    cin>>SIZE;
    Appointment* Array[SIZE];
    int Choice;
    for(int i =0; i<SIZE; i++)
    {
        cout<<endl<<"> Enter 1 for registering Onetime appointments."<<endl;
        cout<<"> Enter 2 for registering Daily appointments."<<endl;
        cout<<"> Enter 3 for registering Weekly appointments."<<endl;
        cout<<"> Enter 4 for registering Monthly appointments."<<endl;
        cout<<"Choice: "<<endl;
        cin>>Choice;

        int Y, M, T, D;
        string S;
        cout<<endl<<"Enter the Year: ";
        cin>> Y;
        cout<<endl<<"Enter the month: ";
        cin>> M;
        cout<<endl<<"Enter the day: ";
        cin>> D;
        cout<<endl<<"Enter the time: ";
        cin>> T;
        cin.ignore();
        cout<<endl<<"Enter description: ";
        getline(cin,S);


        if(Choice == 1)
        {
            Date d(D,M,Y,T);
            Array[i] = new Onetime(S,d);
        }
        else if(Choice == 2)
        {
            Date d(D,M,Y,T);
            Array[i] = new Daily(S,d);
        }
        else if(Choice == 3)
        {
            Date d(D,M,Y,T);
            Array[i] = new Weekly(S,d);
        }
        else if(Choice == 4)
        {
            Date d(D,M,Y,T);
            Array[i] = new Monthly(S,d);
        }

    }
    cout<<endl<<endl<<"APPOINTMENT CHECK";
    int da, mo, ye;
    cout<<endl<<"Enter the date: ";
    cin>>da;
    cout<<endl<<"Enter the month: ";
    cin>>mo;
    cout<<endl<<"Enter the year: ";
    cin>> ye;

    cout<<endl;
    int Count =0;
    for(int i=0; i<SIZE; i++)
    {
        int ans;
        ans = Array[i]->occurs_on(ye,mo,da);
        if(ans == 1)
        {
            if(Array[i]->type =="o")
            {
                cout<<"Onetime Appointment:"<<endl;
            }
            else if(Array[i]->type=="d")
            {
                cout<<"Daily Appointment:"<<endl;
            }
            else if(Array[i]->type == "w")
            {
                cout<<"Weekly Appointment:"<<endl;
            }
            else if(Array[i]->type == "m")
            {
                cout<<"Monthly Appointment:"<<endl;
            }

            cout<<"Description: "<<Array[i]->get_description()<<endl;
            cout<<"Year:  "<<ye<<endl;
            cout<<"Month: "<<mo<<endl;
            cout<<"Day:   "<<da<<endl;
            cout<<"Time:  "<<Array[i]->get_date().get_time()<<endl;
            Count++;
        }
        else if(Count == 0 && i == SIZE-1)
        {
            cout<<"There is no appointment."<<endl;
        }
    }
}



