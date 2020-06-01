#include <iostream>
#include "task1.h"
#include <cstdlib>
#include <time.h>
using namespace std;


void Tool::set_strength(int s)
{
    strength = s;
}

int Tool::get_strength() const
{
    return strength;
}

void Tool::set_type(char t)
{
    type = t;
}

char Tool::get_type() const
{
    return type;
}

Tool::Tool()
{
    strength = 0;
    type = '0';
}

Tool::Tool(int s, char t)
{
    strength = s;
    type = t;
}

void Tool::operator =(const Tool &T)
{
    set_strength(T.get_strength());
    set_type(T.get_type());
}

void Rock::operator=(const Rock &R)
{
    set_strength(R.get_strength());
    set_type(R.get_type());
}

void Paper::operator=(const Paper &P)
{
    set_strength(P.get_strength());
    set_type(P.get_type());
}

void Scissor::operator=(const Scissor& S)
{
    set_strength(S.get_strength());
    set_type(S.get_type());
}

Rock::Rock()
{
    set_strength(1);
    set_type('r');
}

Rock::Rock(int s)
{
    set_strength(s);
    set_type('r');
}

bool Rock::fight(Tool* t)
{
    int str;
    if(t->get_type() == 's')
    {
        str = get_strength();
        str = 2*str;
        if(t->get_strength()  > str)
        {
            return 0;
        }
        else if(t->get_strength() == str)
        {
            cout<< "Same strength."<<endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(t->get_type() == 'p')
    {
        str = get_strength();
        str = str/2.0;

        if(t->get_strength()  > str)
        {
            return 0;
        }
        else if(t->get_strength() == str)
        {
            cout<< "Same strength."<<endl;
            return 0;
        }
        else
        {
                    return 1;
        }
    }
    else
    {
        cout<<"Rock cannot fight Rock."<<endl;
    }
}
Rock::~Rock()
{
    delete this;
}

Paper::Paper()
{
    set_strength(1);
    set_type('p');
}

Paper::Paper(int s)
{
    set_strength(s);
    set_type('p');
}

bool Paper::fight(Tool* t)
{
    int str;
    if(t->get_type() == 's')
    {
        str = get_strength();
        str = str/2.0;

        if(t->get_strength()  > str)
        {
            return 0;
        }
        else if(t->get_strength() == str)
        {
            cout<< "Same strength."<<endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(t->get_type() == 'r')
    {
        str = get_strength();
        str = 2*str;

        if(t->get_strength() > str)
        {
            return 0;
        }
        else if(t->get_strength() == str)
        {
            cout<< "Same strength."<<endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        cout<<"Paper cannot fight Paper."<<endl;
    }
    }
Paper::~Paper()
{
    delete this;
}

Scissor::Scissor()
{
    set_strength(1);
    set_type('s');
}

Scissor::Scissor(int s)
{
    set_strength(s);
    set_type('s');
}
bool Scissor::fight(Tool* t)
{
    int str;
    if(t->get_type() == 'p')
    {
        str = get_strength();
        str = str*2.0;
        if(t->get_strength()  > str)
        {
            return 0;
        }
        else if(t->get_strength() == str)
        {
            cout<< "Same strength."<<endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else if(t->get_type() == 'r')
    {
        str = get_strength();
        str = str/2;
        if(t->get_strength()  > str)
        {
            return 0;
        }
        else if(t->get_strength() == str)
        {
            cout<< "Same strength."<<endl;
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        cout<<"Scissor cannot fight Scissor."<<endl;
    }
}

Scissor::~Scissor()
{
    delete this;
}


void Test()
{
    Tool *t1;
    t1 = new Scissor;
    Tool *t2;
    t2 = new Paper;
    Tool * t3;
    t3 = new Rock;

    t1->set_strength(5);
    t2->set_strength(7);
    t3->set_strength(15);
    int ans;
    cout<<"Fight between Scissor and Paper: "<<endl;
    ans = t1->fight(t2);
    if(ans == 1)
    {
        cout<<"Scissor wins."<<endl;
    }
    else
    {
        cout<<"Paper wins."<<endl;
    }
    cout<<endl<<"Fight between Scissor and Rock: "<<endl;
    ans = t1->fight(t3);
    if(ans == 1)
    {
        cout<<"Scissor wins."<<endl;
    }
    else
    {
        cout<<"Rock wins."<<endl;
    }
    cout<<endl<<"Fight between Paper and Rock: "<<endl;
    ans = t2->fight(t3);
    if(ans == 1)
    {
        cout<<"Paper wins."<<endl;
    }
    else
    {
        cout<<"Rock wins."<<endl;
    }
    cout<<endl<<endl;
}

RPSPlay::RPSPlay()
{
    human_wins =0;
    Computer_wins=0;
    ties = 0;
    cout<<"You will have 10 matches in total!"<<endl;
    for(int i=0; i<10; i++)
    {
        int Computer_determine = rand() % 3;
        if(Computer_determine == 0)
        {
            Computer = new Paper;
        }
        else if(Computer_determine == 1)
        {
            Computer = new Scissor;
        }
        else
        {
            Computer = new Rock;
        }

        cout<<"> Enter 1 to choose rock."<<endl;
        cout<<"> Enter 2 to choose paper."<<endl;
        cout<<"> Enter 3 to choose scissor."<<endl;
        int human_determine;
        cout<<"Choice: ";
        cin>> human_determine;
        cout<<endl<<endl;
        int ans;

        if(human_determine == 1)
        {
            Human = new Rock;
            if(Human->get_type() == Computer->get_type())
            {
                cout<<"Its a tie."<<endl;
                ties++;
                cout<<"Progress till now..."<<endl;
                cout<<"You:      "<<human_wins<<endl;
                cout<<"Computer: "<< Computer_wins<<endl;
                cout<<"Ties:     "<<ties<<endl<<endl<<endl;
                continue;
            }
                ans= Human->fight(Computer);

        }
        else if(human_determine == 2)
        {
            Human = new Paper;
            if(Human->get_type() == Computer->get_type())
            {
                cout<<"Its a tie."<<endl;
                ties++;
                cout<<"Progress till now..."<<endl;
                cout<<"You:      "<<human_wins<<endl;
                cout<<"Computer: "<< Computer_wins<<endl;
                cout<<"Ties:     "<<ties<<endl<<endl<<endl;
                continue;
            }
                ans = Human->fight(Computer);
        }
        else if(human_determine = 3)
        {
            Human = new Scissor;
            if(Human->get_type() == Computer->get_type())
            {
                cout<<"Its a tie."<<endl;
                ties++;
                cout<<"Progress till now..."<<endl;
                cout<<"You:      "<<human_wins<<endl;
                cout<<"Computer: "<< Computer_wins<<endl;
                cout<<"Ties:     "<<ties<<endl<<endl<<endl;
                continue;
            }
                ans = Human->fight(Computer);
        }
        if(ans == 0)
        {
            Computer_wins++;
            cout<<"You lost.";
        }

        else if(ans == 1)
        {
            human_wins++;
            cout<<"You won.";
        }

        cout<<"Progress till now..."<<endl;
        cout<<"You:      "<<human_wins<<endl;
        cout<<"Computer: "<< Computer_wins<<endl;
        cout<<"Ties:     "<<ties<<endl<<endl<<endl;
    }

        cout<<"GAME OVER!"<<endl;
        if(human_wins> Computer_wins)
        {
            cout<<"You won!"<<endl;
        }
        else if(human_wins < Computer_wins)
        {
            cout<<"You lost!"<<endl;
        }

}
void RPSPlay::set_Human(Tool* h)
{
    Human = h;
}
Tool* RPSPlay::get_Human() const
{
    return Human;
}
void RPSPlay::set_Computer(Tool* c)
{
    Computer = c;
}

Tool* RPSPlay::get_Computer() const
{
    return Computer;
}

void RPSPlay::set_human_wins(int h)
{
    human_wins = h;
}

int RPSPlay::get_human_wins() const
{
    return human_wins;
}

void RPSPlay::set_computer_wins(int c)
{
    Computer_wins = c;
}

int RPSPlay::get_computer_wins() const
{
    return Computer_wins;
}

void RPSPlay::set_ties(int s)
{
    ties = s;
}

int RPSPlay::get_ties() const
{
    return ties;
}

void RPSPlay::operator =(const RPSPlay & rps)
{
    set_Human(rps.get_Human());
    set_Computer(rps.get_Computer());
    set_human_wins(rps.get_human_wins());
    set_computer_wins(rps.get_computer_wins());
    set_ties(rps.get_ties());
}
