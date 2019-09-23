#include <iostream>
#include <string.h>
#include "string_t.h"
using namespace std;

int main()
{
string_t str1;
int temp_to_compare;
char str_temp[256];
char str_temp2[256];
int choice;
bool flag = true;
while (flag != false){
cout << "*******************************\n";
cout << " 1 - To set string.\n";
cout << " 2 - To get string.\n";
cout << " 3 - To get length.\n";
cout << " 4 - compare string.\n";
cout << " 5 - Exit.\n";
cout << " Enter your choice and press return: ";

cin >> choice;

switch (choice) 
{

        case 1:
            cout << "set string: \n";
            cin >> str_temp;
            str1.operator=(str_temp);
            cout << str1.getString() << endl;
        break;  
        case 2:
            cout << str1.getString() << endl;
        break;  
        case 3:
            cout << str1.getLen() << endl;
        break;
        case 4:
            cout << "insert another string to check" << endl;
            cin >>str_temp2;
            temp_to_compare = str1.compare(str_temp2);
            cout << temp_to_compare << endl;
        break;
        case 5:
            cout << "End of Program.\n";
            flag = false;
        break;
        default:
            cout << "Not a Valid Choice.\n";
            cout << "Choose again.\n";
        break;
        }   
    }
    return 0;
}