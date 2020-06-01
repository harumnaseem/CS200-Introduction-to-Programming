#ifndef task2_H
#define task2_H
#include <string>
#include <iostream>
using namespace std;
class Date
{
    private:
        int time;
        int year;
        int month;
        int day;
    public:
        Date();
        Date(int Day, int Month, int Year, int Time);
        void set_year(int y);
        int get_year();
        void set_time(int t);
        int get_time();
        void set_month(int m);
        int get_month();
        void set_day(int d);
        int get_day();
};

class Appointment
{
    private:
        string description;
        Date d;
    public:
        string type;
        Appointment();
        void set_description(string d);
        string get_description() const;
        void set_date(Date x);
        Date get_date() const;
        virtual bool occurs_on(int Year, int Month, int Day) =0;
};

class Onetime: public Appointment
{

    public:
        Onetime();
        ~Onetime();
        bool occurs_on(int Year, int Month, int Day);

        Onetime(string s, Date d);
        void operator =(const Onetime& O);
};

class Daily: public Appointment
{
    private:

    public:
        Daily();
        ~Daily();
        Daily(string s, Date d);
        bool occurs_on(int Year, int Month, int Day);
        Daily(int Year, int Month, int Day, int Time);
        void operator =(const Daily& d);
};

class Weekly: public Appointment
{
    private:

    public:
        Weekly();
        ~Weekly();
        Weekly(string s, Date d);
        bool occurs_on(int Year, int Month, int Day);
        Weekly(int Year, int Month, int Day, int Time);
        void operator=(const Weekly& w);
};

class Monthly: public Appointment
{
    private:

    public:
        Monthly();
        ~Monthly();
        Monthly(string s, Date d);
        bool occurs_on(int Year, int Month, int Day);
        Monthly(int Year, int Month, int Day, int Time);
        void operator=(const Monthly& m);
};



#endif

