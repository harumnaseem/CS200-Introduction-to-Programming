#include <iostream>
#include "RPG.h"
#include <cstdlib>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

GameManager::GameManager()
{
    Map = new string*[7];

    for(int i = 0; i<7; i++)
    {
        Map[i] = new string[7];
    }

    for(int i = 0; i<7; i++)
    {
        for(int j = 0; j<7; j++)
        {
            Map[i][j] = "0/N/______";
        }
    }

    srand(time(NULL));
    int rowP = rand() % 7;
    int colP = rand() % 7;

    Map[rowP][colP] ="1/P/______";


    int rowB = rand() % 7;
    int colB = rand() % 7;

    while(rowB == rowP && colB == colP)
    {
            rowB = rand() % 7;
            colB = rand() % 7;
    }

    Map[rowB][colB] ="0/B/______";

    int rowM1 = rand() % 7;
    int colM1 = rand() % 7;

    while((rowM1 == rowP && colM1 == colP) || (rowM1 ==rowB && colM1 == colB))
    {
        rowM1 = rand() % 7;
        colM1 = rand() % 7;
    }

    Map[rowM1][colM1] ="0/M/______";

    int rowM2 = rand() % 7;
    int colM2 = rand() % 7;

    while((rowM2 == rowM1 && colM2 ==colM1) || (rowM2 == rowP && colM2 == rowP)||(rowM2 ==rowB && colM2 == colB))
    {
        rowM2 = rand() % 7;
        colM2 = rand() % 7;
    }

    Map[rowM2][colM2] ="0/M/______";

    int rowM3 = rand() % 7;
    int colM3 = rand() % 7;

    while((rowM3 == rowM2 && colM3 ==colM2) || (rowM3 == rowM1 && colM3 ==colM1) || (rowM3 == rowP && colM3 == rowP)||(rowM3 ==rowB && colM3 == colB))
    {
        rowM3 = rand() % 7;
        colM3 = rand() % 7;
    }

    Map[rowM3][colM3] ="0/M/______";

    int rowM4 = rand() % 7;
    int colM4 = rand() % 7;

    while((rowM4 == rowM3 && colM4 ==colM3) || (rowM4 == rowM2 && colM4 ==colM2) || (rowM4 == rowM1 && colM4 ==colM1) || (rowM4 == rowP && colM4 ==colP) || (colM4 == colB && rowM4 == rowB))
    {
        rowM4 = rand() % 7;
        colM4 = rand() % 7;
    }

    Map[rowM4][colM4] ="0/M/______";

    int rowH1 = rand() % 7;
    int colH1 = rand() % 7;


    while((rowH1 == rowM4 && colH1 ==colM4) || (rowH1 == rowM3 && colH1 ==colM3) || (rowH1 == rowM2 && colH1 ==colM2) || (rowH1 == rowM1 && colH1 ==colM1) || (rowH1 == rowP && colH1 ==colP) || (colH1 == colP && rowH1 == rowP))
    {
        rowH1 = rand() % 7;
        colH1 = rand() % 7;
    }

    Map[rowH1][colH1] ="0/N/H_2_30";

    int rowH2 = rand() % 7;
    int colH2 = rand() % 7;

    while((rowH2 == rowH1 && colH2 ==colH1) || (rowH2 == rowM4 && colH2 ==colM4) || (rowH2 == rowM3 && colH2 ==colM3) || (rowH2 == rowM2 && colH2 ==colM2) || (rowH2 == rowM1 && colH2 ==colM1) || (rowH2 == rowP && colH2 == colP) || (colH2 == colB && rowH2 == rowB))
    {
        rowH2 = rand() % 7;
        colH2 = rand() % 7;
    }
    Map[rowH2][colH2] ="0/N/H_2_30";


    int rowA = rand() % 7;
    int colA = rand() % 7;

    while((rowA == rowH2 && colA == colH2) || (rowA == rowH1 && colA ==colH1) || (rowA == rowM4 && colA ==colM4) || (rowA == rowM3 && colA ==colM3) || (rowA == rowM2 && colA ==colM2) || (rowA == rowM1 && colA ==colM1) || (rowA == rowP && colA ==colP) || (colA == colB && rowA == rowB))
    {
        rowA = rand() % 7;
        colA = rand() % 7;
    }


    Map[rowA][colA] ="0/N/A_1_40";

    int rowS1 = rand() % 7;
    int colS1 = rand() % 7;

    while((rowS1 == rowA && colS1 == colA) || (rowS1 == rowH2 && colS1 == colH2) || (rowS1 == rowH1 && colS1 ==colH1) || (rowS1 == rowM4 && colS1 ==colM4) || (rowS1 == rowM3 && colS1 ==colM3) || (rowS1 == rowM2 && colS1 ==colM2) || (rowS1 == rowM1 && colS1 ==colM1) || (rowS1 == rowP && colS1 ==colP) || (colS1 == colB || rowB == colS1))
    {
        rowS1 = rand() % 7;
        colS1 = rand() % 7;
    }

    Map[rowS1][colS1] ="0/N/S_1_00";

    int rowS2 = rand() % 7;
    int colS2 = rand() % 7;

    while((rowS2 == rowS1 && colS2 == colS1) || (rowS2 == rowA && colS2 == colA) || (rowS2 == rowH2 && colS2 == colH2) || (rowS2 == rowH1 && colS2 ==colH1) ||(rowS2 == rowM4 && colS2 ==colM4) || (rowS2 == rowM3 && colS2 ==colM3) || (rowS2 == rowM2 && colS2 ==colM2) || (rowS2 == rowM1 && colS2 ==colM1) || (rowS2 == rowP && colS2 ==colP) || (colS2 == colB && rowS2 == rowB))
    {
        rowS2 = rand() % 7;
        colS2 = rand() % 7;
    }

    Map[rowS2][colS2] ="0/N/S_1_00";

    int rowS3 = rand() % 7;
    int colS3 = rand() % 7;

    while((rowS3 == rowS2 && colS3 == colS2) || (rowS3 == rowS1 && colS3 == colS1) || (rowS3 == rowA && colS3 == colA) || (rowS3 == rowH2 && colS3 == colH2) || (rowS3 == rowH1 && colS3 ==colH1) || (rowS3 == rowM4 && colS3 ==colM4) || (rowS3 == rowM3 && colS3 ==colM3) || (rowS3 == rowM2 && colS3 ==colM2) || (rowS3 == rowM1 && colS3 ==colM1) || (rowS3 == rowP && colS3 ==colP) || (colS3 == colB || rowS3 == rowB))
    {
        rowS3 = rand() % 7;
        colS3 = rand() % 7;
    }

    Map[rowS3][colS3] ="0/N/S_1_00";

    for(int i=0; i<7; i++)
    {
        for(int j =0; j<7; j++)
        {
            cout<<Map[i][j]<<" ";
        }
        cout<<endl;
    }

    playerNode = new Node;
    playerNode->c = new Character;
    playerNode->c->inventorySize = 2;
    playerNode->c->characterType ="Player";
    playerNode->c->HP = 100;


    playerNode->c->inventory = new Item[2];
    playerNode->c->inventory[0].itemName = "Sword";
    playerNode->c->inventory[0].itemCateogry = 1;
    playerNode->c->inventory[0].points = 20;
    playerNode->c->inventory[1].itemName ="Health Potion";
    playerNode->c->inventory[1].itemCateogry = 2;
    playerNode->c->inventory[1].points = 20;

    playerNode->nodePosition[0]= rowP;
    playerNode->nodePosition[1]= colP;
    head = playerNode;

    minionNodesSize = 4;
    minionNodes = new Node*[4];
    for(int i=0; i<minionNodesSize; i++)
    {
        minionNodes[i]= new Node;
    }

    minionNodes[0]->c = new Character;
    minionNodes[0]->c->characterType="Minion";
    minionNodes[0]->c->HP = 100;
    minionNodes[0]->c->inventory = new Item[1];
    minionNodes[0]->c->inventorySize=1;
    minionNodes[0]->c->inventory[0].itemCateogry=1;
    minionNodes[0]->c->inventory[0].itemName="Dagger";
    minionNodes[0]->c->inventory[0].points=15;
    minionNodes[0]->nodePosition[0] = rowM1;
    minionNodes[0]->nodePosition[1] = colM1;

    minionNodes[1]->c = new Character;
    minionNodes[1]->c->characterType="Minion";
    minionNodes[1]->c->HP = 100;
    minionNodes[1]->c->inventory = new Item[1];
    minionNodes[1]->c->inventorySize=1;
    minionNodes[1]->c->inventory[0].itemCateogry=1;
    minionNodes[1]->c->inventory[0].itemName="Dagger";
    minionNodes[1]->c->inventory[0].points=15;
    minionNodes[1]->nodePosition[0] = rowM2;
    minionNodes[1]->nodePosition[1] = colM2;


    minionNodes[2]->c = new Character;
    minionNodes[2]->c->characterType="Minion";
    minionNodes[2]->c->HP = 100;
    minionNodes[2]->c->inventory = new Item[1];
    minionNodes[2]->c->inventorySize=1;
    minionNodes[2]->c->inventory[0].itemCateogry=1;
    minionNodes[2]->c->inventory[0].itemName="Dagger";
    minionNodes[2]->c->inventory[0].points=15;
    minionNodes[2]->nodePosition[0] = rowM3;
    minionNodes[2]->nodePosition[1] = colM3;


    minionNodes[3]->c = new Character;
    minionNodes[3]->c->characterType="Minion";
    minionNodes[3]->c->HP = 100;
    minionNodes[3]->c->inventory = new Item[1];
    minionNodes[3]->c->inventorySize=1;
    minionNodes[3]->c->inventory[0].itemCateogry=1;
    minionNodes[3]->c->inventory[0].itemName="Dagger";
    minionNodes[3]->c->inventory[0].points=15;
    minionNodes[3]->nodePosition[0] = rowM4;
    minionNodes[3]->nodePosition[1] = colM4;

    bossNode = new Node;
    bossNode->c = new Character;
    bossNode->c->characterType="Boss";
    bossNode->c->HP=100;
    bossNode->c->inventorySize = 1;
    bossNode->c->inventory = new Item[1];
    bossNode->c->inventory[0].itemCateogry = 1;
    bossNode->c->inventory[0].itemName ="Scythe";
    bossNode->c->inventory[0].points = 80;
    bossNode->nodePosition[0] = rowB;
    bossNode->nodePosition[1] = colB;

}

GameManager::~GameManager()
{    // incomplete
    delete playerNode;
    delete head;

    for(int i=0; i<7; i++)
    {
        delete Map[i];
    }
    delete []Map;
}

bool GameManager::playerMove(int direction)
{
    int choice;

    if(playerNode->nodePosition[0]==0 && playerNode->nodePosition[1]==0)
    {
        if(direction == 1)
            return 0;
        else if(direction == 3)
          return 0;
    }

    else if(playerNode->nodePosition[0] == 0 && playerNode->nodePosition[1] == 6)
    {
        if(direction == 1)
            return 0;
        else if(direction == 2)
            return 0;
    }

    else if(playerNode->nodePosition[0] == 6 && playerNode->nodePosition[1] == 0)
    {
        if(direction == 4)
            return 0;
        else if(direction == 3)
            return 0;
    }
    else if(playerNode->nodePosition[0] == 6 && playerNode->nodePosition[1] == 6)
    {
        if(direction == 2)
            return 0;
        else if(direction == 4)
            return 0;
    }

    if(playerNode->nodePosition[0]==0)
    {
        if(direction == 1)
            return 0;
    }
   else if(playerNode->nodePosition[1]==0)
    {
        if(direction == 3)
            return 0;
    }
    else if(playerNode->nodePosition[0]==6)
    {
        if(direction== 4)
            return 0;
    }
    else if(playerNode->nodePosition[1]==6)
    {
        if(direction ==2)
            return 0;
    }

    if(direction == 1)
    {
        if(playerNode->North == NULL)
        {

            int row = playerNode->nodePosition[0] - 1;
            int col = playerNode->nodePosition[1];
            playerNode->nodePosition[0] = row;

            if(Map[row][col][2] == 'B')
            {
                return 0;
            }
            else if(Map[row][col][2]=='M')
            {
                return 0;
            }
            else if(Map[row][col][4]=='S')
            {
               if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]+1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[0] = playerNode->nodePosition[0]+1;
                        return 0;
                    }
                }
            }
            else if(Map[row][col][4]=='A')
            {
                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]+1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[0] = playerNode->nodePosition[0]+1;
                        return 0;
                    }
                }
            }
            else if(Map[row][col][4]=='H')
            {
               if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]+1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[0] = playerNode->nodePosition[0]+1;
                        return 0;
                    }
                }
            }
            playerNode->nodePosition[0] = playerNode->nodePosition[0] + 1;

            Node* north;
            north = new Node;
            playerNode->North = north;
            north->nodePosition[0] = playerNode->nodePosition[0] - 1;
            north->nodePosition[1] = playerNode->nodePosition[1];
            north->South = playerNode;

            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";

            north->c = playerNode->c;
            north->item= playerNode->item;

            playerNode = north;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";

        }
        else
        {
            int row = playerNode->nodePosition[0];
            int col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";

            playerNode->North->c = playerNode->c;
            playerNode->North->item= playerNode->item;

            playerNode = playerNode->North;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";

        }
    }
    else if(direction == 2)
    {
        if(playerNode->East == NULL)
        {

            int row = playerNode->nodePosition[0];
            int col = playerNode->nodePosition[1] + 1;

            playerNode->nodePosition[1] = col;
            if(Map[row][col][2] == 'B')
            {

                return 0;
            }
            else if(Map[row][col][2]=='M')
            {
                return 0;
            }
            else if(Map[row][col][4]=='S')
            {
               if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[1] = playerNode->nodePosition[1]-1;
                        return 0;
                    }
                }

            }
            else if(Map[row][col][4]=='A')
            {
                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[1] = playerNode->nodePosition[1]-1;
                        return 0;
                    }
                }
            }
            else if(Map[row][col][4]=='H')
            {
                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[1] = playerNode->nodePosition[1]-1;
                        return 0;
                    }
                }
            }
            playerNode->nodePosition[1] = playerNode->nodePosition[1] - 1;

            Node* east;
            east = new Node;
            playerNode->East = east;
            east->nodePosition[0] = playerNode->nodePosition[0];
            east->nodePosition[1] = playerNode->nodePosition[1] + 1;
            east->West = playerNode;

            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";

            east->c = playerNode->c;
            east->item= playerNode->item;

            playerNode = east;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";

        }
        else
        {
            int row = playerNode->nodePosition[0];
            int col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";

            playerNode->East->c = playerNode->c;
            playerNode->East->item= playerNode->item;

            playerNode = playerNode->East;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";

        }
    }
    else if(direction == 3)
    {
        if(playerNode->West == NULL)
        {

            int row = playerNode->nodePosition[0];
            int col = playerNode->nodePosition[1]-1;
            playerNode->nodePosition[1] = col;

            if(Map[row][col][2] == 'B')
            {
                return 0;
            }
            else if(Map[row][col][2]=='M')
            {
                return 0;
            }
            else if(Map[row][col][4]=='S')
            {
                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[1] = playerNode->nodePosition[1]+1;
                        return 0;
                    }
                }
            }
            else if(Map[row][col][4]=='A')
            {
              if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[1] = playerNode->nodePosition[1]+1;
                        return 0;
                    }
                }
            }
            else if(Map[row][col][4]=='H')
            {
                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[1] = playerNode->nodePosition[1]+1;
                        return 0;
                    }
                }
            }

            playerNode->nodePosition[1] = playerNode->nodePosition[1]+1;
            Node* west;
            west = new Node;
            playerNode->West = west;
            west->nodePosition[0] = playerNode->nodePosition[0];
            west->nodePosition[1] = playerNode->nodePosition[1] - 1;
            west->East = playerNode;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";
            west->c = playerNode->c;
            west->item= playerNode->item;

            playerNode = west;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";
            return 1;
        }
        else
        {
            int row = playerNode->nodePosition[0];
            int col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";

            playerNode->West->c = playerNode->c;
            playerNode->West->item= playerNode->item;

            playerNode = playerNode->West;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";

        }
    }
    else if(direction == 4)
    {
        if(playerNode->South == NULL)
        {

            int row = playerNode->nodePosition[0]+1;
            int col = playerNode->nodePosition[1];
            playerNode->nodePosition[0] = row;
            if(Map[row][col][2] == 'B')
            {
                return 0;
            }
            else if(Map[row][col][2]=='M')
            {
                return 0;
            }
            else if(Map[row][col][4]=='S')
            {
                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                    }
                }

            }
            else if(Map[row][col][4]=='A')
            {
                                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                    }
                }
            }
            else if(Map[row][col][4]=='H')
            {
                                if(playerNode->c->inventorySize == 6)
                {
                    cout<<"Your Inventory is full. Please drop an item."<<endl;

                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                }
                else
                {
                    cout<<endl<<"Enter 0 for no."<<endl<<"Enter 1 for yes."<<endl<<endl;
                    cout<<endl<<"Do you wish to pick the item here?"<<endl;
                    cout<<"Choice: ";
                    cin>>choice;
                    if(choice == 1)
                    {
                        pickItem();
                    }
                    else
                    {
                        playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
                        return 0;
                    }
                }
            }
            playerNode->nodePosition[0] = playerNode->nodePosition[0]-1;
            Node* south;
            south = new Node;
            playerNode->South = south;
            south->nodePosition[0] = playerNode->nodePosition[0]+1;
            south->nodePosition[1] = playerNode->nodePosition[1];

            south->North = playerNode;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";

            south->c = playerNode->c;
            south->item= playerNode->item;

            playerNode = south;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";

        }
        else
        {
            int row = playerNode->nodePosition[0];
            int col = playerNode->nodePosition[1];

            Map[row][col] = "1/N/______";

            playerNode->South->c = playerNode->c;
            playerNode->South->item= playerNode->item;

            playerNode = playerNode->South;
            row = playerNode->nodePosition[0];
            col = playerNode->nodePosition[1];
            Map[row][col] = "1/P/______";
        }
    }
    for(int i=0; i<7; i++)
    {
        for(int j =0; j<7; j++)
        {
            cout<<Map[i][j]<<" ";
        }
        cout<<endl;
    }

    return 1;
}
void GameManager::searchNode(Node*& temp, Node* calling, int position[2], int direction)
{
        if(position[0] == calling->nodePosition[0] && position[1] == calling->nodePosition[1])
        {
            temp = calling;
            return;
        }
        else if(direction==0 && head->isVisited == 0)
        {
            direction = 9;
            head->isVisited = 1;
            searchNode(temp, head, position, direction);
            head->isVisited = 0;
        }
        else if(calling->North != NULL && direction != 4 && calling->North->isVisited == 0)
        {
            direction = 1;
            calling->North->isVisited = 1;
            searchNode(temp, calling->North, position, direction);
            calling->North->isVisited = 0;
        }
        else if(calling->South != NULL && direction != 1 && calling->South->isVisited == 0)
        {
            direction = 4;
            calling->South->isVisited = 1;
            searchNode(temp, calling->South, position, direction);
            calling->South->isVisited = 0;
        }
        else if(calling->West != NULL && direction != 3 && calling->West->isVisited == 0)
        {
            direction = 2;
            calling->West->isVisited = 1;
            searchNode(temp, calling->West, position, direction);
            calling->West->isVisited = 0;
        }
        else if(calling->East != NULL && direction != 2 && calling->West->isVisited ==0)
        {
            direction = 3;
            calling->South->isVisited = 1;
            searchNode(temp, calling->East, position, direction);
            calling->East->isVisited = 0;
        }
        else
        {
            temp = NULL;
        }
}

void GameManager::minionMove()
{
   for(int i=0; i<4; i++)
   {

       if(Map[minionNodes[i]->nodePosition[0] - 1][minionNodes[i]->nodePosition[1]] == "1/N/______")
       {

            int row = minionNodes[i]->nodePosition[0];
            int col = minionNodes[i]->nodePosition[1];

            Map[row][col] = "1/N/______";

            minionNodes[i]->North->c = minionNodes[i]->c;
            minionNodes[i]->North->item= minionNodes[i]->item;

            minionNodes[i] = minionNodes[i]->North;
            row =  minionNodes[i]->nodePosition[0];
            col = minionNodes[i]->nodePosition[1];
            Map[row][col] = "1/M/______";

       }
       else if(Map[minionNodes[i]->nodePosition[0] + 1][minionNodes[i]->nodePosition[1]] == "1/N/______")
       {
            int row = minionNodes[i]->nodePosition[0];
            int col = minionNodes[i]->nodePosition[1];

            Map[row][col] = "1/N/______";

            minionNodes[i]->South->c = minionNodes[i]->c;
            minionNodes[i]->South->item= minionNodes[i]->item;

            minionNodes[i] = minionNodes[i]->South;
            row =  minionNodes[i]->nodePosition[0];
            col = minionNodes[i]->nodePosition[1];
            Map[row][col] = "1/M/______";
       }
       else if(Map[minionNodes[i]->nodePosition[0]][minionNodes[i]->nodePosition[1] + 1] == "1/N/______")
       {
            int row = minionNodes[i]->nodePosition[0];
            int col = minionNodes[i]->nodePosition[1];

            Map[row][col] = "1/N/______";

            minionNodes[i]->East->c = minionNodes[i]->c;
            minionNodes[i]->East->item= minionNodes[i]->item;

            minionNodes[i] = minionNodes[i]->East;
            row =  minionNodes[i]->nodePosition[0];
            col = minionNodes[i]->nodePosition[1];
            Map[row][col] = "1/M/______";
       }
        else if(Map[minionNodes[i]->nodePosition[0]][minionNodes[i]->nodePosition[1]- 1] == "1/N/______")
       {
            int row = minionNodes[i]->nodePosition[0];
            int col = minionNodes[i]->nodePosition[1];

            Map[row][col] = "1/N/______";

            minionNodes[i]->West->c = minionNodes[i]->c;
            minionNodes[i]->West->item= minionNodes[i]->item;

            minionNodes[i] = minionNodes[i]->West;
            row =  minionNodes[i]->nodePosition[0];
            col = minionNodes[i]->nodePosition[1];
            Map[row][col] = "1/M/______";
       }
   }
}

bool GameManager::fight(Node* enemyNode)
{

}

void GameManager::showEnemy(Node* enemyNode)
{
    cout<<"Enemy Status"<<endl;
    cout<<"Health Points: "<< enemyNode->c->HP;
    cout<<endl<<"Items: ";
    for(int i=0; i<(enemyNode->c)->inventorySize; i++)
    {

        cout<<endl<<i+1<<". Type "<<enemyNode->c->inventory[i].itemCateogry<<" "<<enemyNode->c->inventory[i].itemName<<" "<<enemyNode->c->inventory[i].points<<".";
    }
}

void GameManager::useItem(Item item, Node* character,int choice)
{

}

void GameManager::dropItem()
{
    int CHOICE;
    cout<<"This is the list of items you have in your inventory: "<<endl;
    for(int i=0; i<playerNode->c->inventorySize;i++)
    {
        cout<<i<<". "<<playerNode->c->inventory[i].itemName<<endl;
    }
    cout<<endl<<endl<<"Enter the corresponding index number for the item you wish to drop."<<endl;
    cin>> CHOICE;


    Item* Inventory = new Item[playerNode->c->inventorySize - 1];
    int j =0;
    for(int i=0; i<playerNode->c->inventorySize ; i++)
    {
        if(CHOICE != i)
        {
            Inventory[j]= playerNode->c->inventory[i];
            j++;
        }

    }
    playerNode->c->inventorySize = playerNode->c->inventorySize - 1;
    playerNode->c->inventory = Inventory;
}

void GameManager::pickItem()
{
    playerNode->c->inventorySize = playerNode->c->inventorySize + 1;
    Item* Inventory = new Item[playerNode->c->inventorySize];
    for(int i=0; i<(playerNode->c->inventorySize-1); i++)
    {
        Inventory[i] = playerNode->c->inventory[i];
    }
    int row = playerNode->nodePosition[0];
    int col = playerNode->nodePosition[1];
    if(Map[row][col][4]== 'S')
    {
        Inventory[playerNode->c->inventorySize - 1].itemCateogry = 1;
        Inventory[playerNode->c->inventorySize - 1].itemName = "Sword piece";
        Inventory[playerNode->c->inventorySize - 1].points = 0;
    }
    else if(Map[row][col][4]=='H')
    {
        Inventory[playerNode->c->inventorySize - 1].itemCateogry = 2;
        Inventory[playerNode->c->inventorySize - 1].itemName = "Health potion";
        Inventory[playerNode->c->inventorySize - 1].points = 30;
    }
    else if(Map[row][col][4]== 'A')
    {
        Inventory[playerNode->c->inventorySize - 1].itemCateogry = 1;
        Inventory[playerNode->c->inventorySize - 1].itemName = "Axes";
        Inventory[playerNode->c->inventorySize - 1].points = 40;
    }

    playerNode->c->inventory = Inventory ;
}

void GameManager::craft()
{
    int index_sword[3];
    int j=0;
    for(int i=0; i<playerNode->c->inventorySize; i++)
    {
        if(playerNode->c->inventory[i].itemName == "Sword piece")
        {
            index_sword[j] = i;
            j++;
        }
    }

    if(j==3)
    {

        int k=0;
        Item* Inventory = new Item[playerNode->c->inventorySize - 2];

        for(int i=0; i<playerNode->c->inventorySize;i++)
        {
            if(index_sword[0] != i && index_sword[1] != i && index_sword[2] !=i)
            {
                Inventory[k] = playerNode->c->inventory[i];
                k++;
            }
        }
        playerNode->c->inventorySize = playerNode->c->inventorySize - 2;
        Inventory[playerNode->c->inventorySize - 1].itemCateogry = 1;
        Inventory[playerNode->c->inventorySize - 1].itemName="Divine Sword";
        Inventory[playerNode->c->inventorySize - 1].points = 80;
        playerNode->c->inventory = Inventory;

    }
    else
    {
        cout<<"You don't have all the pieces for the divine sword."<<endl;
    }
}

void GameManager::displayMap()
{
    string temp;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            if(Map[i][j][0] == '1')
            {
                if(Map[i][j][2] == 'P')
                    cout<<"P ";
                else if(Map[i][j][2] == 'N')
                    cout<<"1 ";
            }
            else if(Map[i][j][0] == '0')
            {
                if(Map[i][j][4] == 'S')
                    cout<<"S ";
                else if(Map[i][j][4] == 'H')
                    cout<<"H ";
                else if(Map[i][j][4] == 'A')
                    cout<<"A ";
                else
                    cout<<"_ ";
            }
        }
        cout<<endl;
    }

}

bool GameManager::saveGame(string fileName)
{
    ofstream outfile;
    outfile.open(fileName.c_str());

    for(int i=0; i<7; i++)
    {
        for(int j =0; j<7; j++)
        {
            outfile<<Map[i][j]<<" ";
        }
        outfile<<endl;
    }

    outfile<<playerNode->c->characterType<<" "<< playerNode->c->HP<<" "<< playerNode->c->inventorySize<<" ";
    outfile<<endl;

    for(int i=0; i<playerNode->c->inventorySize;i++)
    {
        outfile<<playerNode->c->inventory[i].itemCateogry<<" "<<playerNode->c->inventory[i].itemName<<" "<<playerNode->c->inventory[i].points<<" ";
        outfile<<endl;
    }

    outfile.close();

    cout<<endl<<"File has been saved."<<endl;
}

bool GameManager::loadGame(string fileName)
{
    ifstream infile;
    infile.open(fileName.c_str());

    for(int i=0; i<7; i++)
    {
        for(int j =0; j<7; j++)
        {
            infile>>Map[i][j];
        }
    }

    infile>>playerNode->c->characterType>>playerNode->c->HP>>playerNode->c->inventorySize;


    for(int i=0; i<playerNode->c->inventorySize;i++)
    {
        infile>>playerNode->c->inventory[i].itemCateogry>>playerNode->c->inventory[i].itemName>>playerNode->c->inventory[i].points;
    }

    infile.close();

    cout<<endl<<"File has been loaded."<<endl;
}

void GameManager::showPlayerStatus()
{
    cout<<"Player Status"<<endl;
    cout<<"Health Points: "<< playerNode->c->HP;
    cout<<endl<<"Items: ";
    for(int i=0; i<((playerNode->c)->inventorySize); i++)
    {

        cout<<endl<<i+1<<". Type "<<playerNode->c->inventory[i].itemCateogry<<" "<<playerNode->c->inventory[i].itemName<<" "<<playerNode->c->inventory[i].points<<".";
    }

}

bool GameManager::isPlayerAlive()
{
    if(playerNode->c->HP <= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    cout << playerNode->c->HP;
}


