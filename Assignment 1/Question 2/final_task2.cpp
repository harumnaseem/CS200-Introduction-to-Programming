#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
int system_choice(int choice)
{
        cout<<"Enter 1 for decimal number system."<<endl;
        cout<<"Enter 2 for binary number system."<<endl;
        cout<<"Enter 3 for hexadecimal number system."<<endl;
        cout<<"Enter -1 to exit."<<endl<<endl;
        cout<<"Your choice: ";
        while( !(cin>>choice) || (choice != 1 && choice != 2 && choice != 3 && choice != -1))
        {
            cout<<"Not a valid input!"<<endl<<endl;
            cin.clear();
 	        cin.ignore(999999,'\n');
 	        cout<<"Enter your choice again: ";
        }
        cout<<endl<<endl;
    return choice;
}

bool binary_input_fail_check(string binary_input)
{
    for(int i=0; i < binary_input.length(); i++)
    {
        if(binary_input.substr(i,1) != "1" && binary_input.substr(i,1) != "0")
            {
                return true;
            }
    }
    return false;
}

void decimal_number_to_hexadecimal(int decimal_number)
{
    int size_of_array = 16;
    string key_for_hexadecimal_number[size_of_array]= {"0","1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    int length_of_hexa_number = 0;
    int rem = decimal_number;
    int quotient;
    if(decimal_number<=15)
    {
        cout<<"Hexadecimal: "<< key_for_hexadecimal_number[decimal_number]<<endl;
    }

    else if(decimal_number>15)
    {
    while(rem !=0)
    {
        rem = rem/16;
        length_of_hexa_number++;
    }

    int hexa_values[length_of_hexa_number]={};
    quotient = decimal_number;

    for(int i=length_of_hexa_number-1; i>=0; i--)
    {
        rem= quotient%16;
        quotient = quotient/16;
        hexa_values[i]= rem;
    }
    cout<<"Hexadecimal: ";
    for(int output_index=0; output_index<length_of_hexa_number; output_index++)
    {
        int values_of_array_index = hexa_values[output_index];
        cout<<key_for_hexadecimal_number[values_of_array_index];
    }
    cout<<endl;
    }

}

int binary_to_decimal(string binary)
{

    int length_of_binary = binary.length();
    int decimal_number = 0;

    //to find the decimal number
    for(int i = 0; i < length_of_binary; i++)
    {
        if(binary[i] == '1')
            decimal_number += pow(2 , length_of_binary -1 - i);
        else
            continue; // in case it's 0 it doesn't matter if we add 0 multiplied by something because its still zero
    }
    return decimal_number;

}
void binary_number_system(string binary)
{
   int x = binary_to_decimal(binary);
   cout<< "Binary: "<<x<<endl;
   decimal_number_to_hexadecimal(x);
}
void decimal_number_system(int decimal_number)
{
     decimal_number_to_hexadecimal(decimal_number);
     // decimal to binary number
     int length_of_binary=0;
     int quotient = decimal_number;
     while(quotient != 0)
     {
         quotient = quotient/2;
         length_of_binary++;
     }
     quotient= decimal_number;
     int rem;
     int array_of_binary[length_of_binary]={};
     cout<<"Binary: ";
     for(int i=length_of_binary-1; i >= 0; i--)
     {
         rem= quotient%2;
         quotient= quotient/2;
         array_of_binary[i]=rem;
     }
    for(int i=0; i < length_of_binary; i++)
    {
        cout<<array_of_binary[i];
    }
    cout<<endl<<endl<<endl;
}


bool hexadecimal_input_fail_check(string hexadecimal)
{
    for(int i=0; i< hexadecimal.length(); i++)
    {
        if((hexadecimal.substr(i,1) != "1") && (hexadecimal.substr(i,1) !="2") && (hexadecimal.substr(i,1) != "3") && (hexadecimal.substr(i,1) !="4") && (hexadecimal.substr(i,1)  !="5") && (hexadecimal.substr(i,1) !="6") && (hexadecimal.substr(i,1) !="7") && (hexadecimal.substr(i,1) !="8") && (hexadecimal.substr(i,1) !="9") && (hexadecimal.substr(i,1) !="A") && (hexadecimal.substr(i,1) != "B") && (hexadecimal.substr(i,1) !="C") && (hexadecimal.substr(i,1) !="D") && (hexadecimal.substr(i,1) !="E") && (hexadecimal.substr(i,1) != "F") && (hexadecimal.substr(i,1) != "a") && (hexadecimal.substr(i,1) != "b") && (hexadecimal.substr(i,1) != "c") && (hexadecimal.substr(i,1) != "d") && (hexadecimal.substr(i,1) != "e") && (hexadecimal.substr(i,1) != "f") )
         {
             return true;

        }
    }
    return false;

}
void hexadecimal_number_system(string hexadecimal)
{
    string array_of_binary[hexadecimal.length()]={};
    for(int i=0; i< hexadecimal.length(); i++)
    {
        if(hexadecimal.substr(i,1)=="0")
            array_of_binary[i]="0000";
        else if(hexadecimal.substr(i,1) == "1")
            array_of_binary[i]="0001";
        else if(hexadecimal.substr(i,1) == "2")
            array_of_binary[i]="0010";
        else if(hexadecimal.substr(i,1) == "3")
            array_of_binary[i]="0011";
        else if(hexadecimal.substr(i,1) == "4")
            array_of_binary[i]="0100";
        else if(hexadecimal.substr(i,1) == "5")
            array_of_binary[i]="0101";
        else if(hexadecimal.substr(i,1) == "6")
            array_of_binary[i]="0110";
        else if(hexadecimal.substr(i,1) == "7")
            array_of_binary[i]="0111";
        else if(hexadecimal.substr(i,1) == "8")
            array_of_binary[i]="1000";
        else if(hexadecimal.substr(i,1) == "9")
            array_of_binary[i]="1001";
        else if((hexadecimal.substr(i,1) == "A") || (hexadecimal.substr(i,1)== "a"))
            array_of_binary[i]="1010";
        else if((hexadecimal.substr(i,1) == "B") || (hexadecimal.substr(i,1) == "b"))
            array_of_binary[i]="1011";
        else if((hexadecimal.substr(i,1) == "C") || (hexadecimal.substr(i,1)== "c"))
            array_of_binary[i]="1100";
        else if((hexadecimal.substr(i,1) == "D") || (hexadecimal.substr(i,1)== "d"))
            array_of_binary[i]="1101";
        else if((hexadecimal.substr(i,1) == "E")|| (hexadecimal.substr(i,1)== "e"))
            array_of_binary[i]="1110";
        else if((hexadecimal.substr(i,1) == "F") || (hexadecimal.substr(i,1)== "f"))
            array_of_binary[i]="1111";
    }
    cout<<"Binary: ";
    string combined_binary ="";
    for(int p=0; p <hexadecimal.length(); p++)
    {
        cout<<array_of_binary[p];
        combined_binary += array_of_binary[p];
    }
    cout<<endl;

    cout<< "Decimal: "<< binary_to_decimal(combined_binary)<<endl<<endl;
}

int main()
{
    bool termination= false;
    int choice, decimal_value;
    string binary_value, hexadecimal_value;
    cout<<"\t \t \t \t \t NUMBER SYSTEM CONVERSION CALCULATOR"<<endl<<endl;

   while(!termination)
    {
        choice= system_choice(choice);

        if(choice == 1)
        {

            cout<<"Enter a decimal number: ";
            while( !(cin>>decimal_value) || decimal_value > 99999)
        {
            cout<<"This is not a valid input for this calculator"<<endl<<endl;
            cin.clear();
 	        cin.ignore(999999,'\n');
 	        cout<<"Enter a 5 or less digit decimal number: ";
        }

            decimal_number_system(decimal_value);

        }

        else if(choice == 2)
        {
            cout<<"Enter a binary number: ";
            while( !(cin>>binary_value) || binary_input_fail_check(binary_value))
        {
            cout<<"This is not a binary number"<<endl<<endl;
            cin.clear();
 	        cin.ignore(999999,'\n');
 	        cout<<"Enter a binary number: ";
        }

            binary_number_system(binary_value);

            cout<<endl<<endl<<endl;
        }

        else if(choice == 3)
        {
            cout<<"Enter a hexadecimal number: ";

            //functions: hexadecimal to binary and hexadecimal to decimal
            while( !(cin>>hexadecimal_value) || hexadecimal_input_fail_check(hexadecimal_value))
        {
            cout<<"This is not a valid input."<<endl<<endl;
            cin.clear();
 	        cin.ignore(999999,'\n');
 	        cout<<"Enter a valid hexadecimal number: ";
        }
        hexadecimal_number_system(hexadecimal_value);

        }

        else if(choice == -1 )
        {
            break;
        }
    }

return 0;
}
