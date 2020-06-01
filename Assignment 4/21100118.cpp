#include <iostream>
#include "RPG.cpp"


using namespace std;

int main()
{
    GameManager O;
    int direction;
    int a;
    bool termination = false;
    int choice;
    while(!termination)
    {
        cout<<endl<<endl;
        cout<<"Enter 1 to move the player."<<endl;
        cout<<"Enter 2 to see if the player is alive."<<endl;
        cout<<"Enter 3 to save the game."<<endl;
        cout<<"Enter 4 to load the game."<<endl;
        cout<<"Enter 5 to show the players status."<<endl;
        cout<<"Enter 6 to show the enemys status."<<endl;
        cout<<"Enter 7 to drop an item from your inventory."<<endl;
        cout<<"Enter 8 to craft your divine sword."<<endl;
        cout<<"Enter -1 to exit."<<endl;
        cout<<"Choice: ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<endl<<endl<<endl<<"Move in position: ";
            cin>>direction;  // 1 2 3 4 only constraint
            a = O.playerMove(direction);
            if(a==0)
            {
                cout<<"Player cannot move from this position in this direction."<<endl;
            }

            O.displayMap();

        }

        else if(choice == 5)
        {
            O.showPlayerStatus();
        }

        else if(choice == 2)
        {
            bool alive;
            alive = O.isPlayerAlive();
            if(alive)
            {
                cout<<endl<<"Player is alive."<<endl;

            }
            else
            {
                cout<<endl<<"Player is not alive."<<endl;
            }
        }
        else if(choice == 7)
        {
            O.dropItem();

        }
        else if(choice == 3)
        {
            O.saveGame("fileSave.txt");
        }
        else if(choice == 4)
        {
            O.loadGame("fileSave.txt");
            O.displayMap();
        }
        else if(choice == 8)
        {
            O.craft();
        }
        else if(choice == -1)
        {
            break;
        }
        else if(choice == 6)
        {
            cout<<"BOSS:"<<endl;
            O.showEnemy(O.bossNode);
            cout<<endl<<endl<<"MINION 1:"<<endl;
            O.showEnemy(O.get_minionNodes(0));
            cout<<endl<<endl<<"MINION 2:"<<endl;
            O.showEnemy(O.get_minionNodes(1));
            cout<<endl<<endl<<"MINION 3:"<<endl;
            O.showEnemy(O.get_minionNodes(2));
            cout<<endl<<endl<<"MINION 4:"<<endl;
            O.showEnemy(O.get_minionNodes(3));
        }
    }



    return 0;

}


