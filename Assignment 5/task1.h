#ifndef task1_H
#define task1_H

class Tool
{
    private:
        int strength;
        char type;
    public:
        void set_strength(int s);
        int get_strength() const;
        void set_type(char t);
        char get_type() const;
        Tool();
        Tool(int s, char t);
        void operator =(const Tool &T);
        virtual bool fight(Tool* t)=0;
};

class Rock: public Tool
{
    public:
        Rock();
        Rock(int s);
        void operator=(const Rock &R);
        bool fight(Tool* t);
        ~Rock();
};

class Paper: public Tool
{
    public:
        Paper();
        Paper(int s);
        void operator=(const Paper &P);
        bool fight(Tool* t);
        ~Paper();
};

class Scissor: public Tool
{
    public:
        Scissor();
        Scissor(int s);
        void operator=(const Scissor &S);
        bool fight(Tool* t);
        ~Scissor();
};

class RPSPlay
{
    private:
        Tool* Human;
        Tool* Computer;
        int human_wins;
        int Computer_wins;
        int ties;
    public:
        RPSPlay();
        void set_Human(Tool* h);
        void set_Computer(Tool* c);
        Tool* get_Human() const;
        Tool* get_Computer() const;
        void set_human_wins(int h);
        int get_human_wins() const;
        void set_computer_wins(int c);
        int get_computer_wins() const;
        void set_ties(int s);
        int get_ties() const;
        void operator =(const RPSPlay & rps);
};
 #endif
