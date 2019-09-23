#include <iostream>
#include <string.h>
#include "string_t.h"
using namespace std;

int main()
{
string_t str1;
string_t str2;
int temp_to_compare;
char str_temp[256];
int choice;
bool flag = true;
while (flag != false){
cout << "*******************************\n";
cout << " 1 - To set string.\n";
cout << " 2 - To print string.\n";
cout << " 3 - To get length.\n";
cout << " 4 - compare string.\n";
cout << " 5 - to upper case.\n";
cout << " 6 - to lower case.\n";
cout << " 7 - to prepend char.\n";
cout << " 8 - to prepend object.\n";
cout << " 9 - to append char.\n";
cout << " 10 - to append object.\n";
cout << " 11 - check operator.\n";
cout << " 12 - if contains.\n";
cout << " 13 - get index.\n";
cout << " 14 - << operators >>.\n";
cout << " 15 - Exit.\n";
cout << " Enter your choice and press return: ";

cin >> choice;

switch (choice) 
{

        case 1:
            cout << "set string: \n";
            cin >> str_temp;
            str1.operator=(str_temp);
        break;  
        case 2:
            str1.printString();
        break;  
        case 3:
            cout << str1.getLen() << endl;
        break;
        case 4:
            cout << "insert another string to check" << endl;
            cin >>str_temp;
            temp_to_compare = str1.compare(str_temp);
            cout << temp_to_compare << endl;
        break;
        case 5:
            str1.toUppercase();
        break;
        case 6:
            str1.toLowercase();
        break;
        case 7:
            cout << "insert another string to check" << endl;
            cin >>str_temp;
            str1.preprend(str_temp);
        break;
        case 8:
            cout << "enter string: \n";
            cin >> str_temp;
            str2.setString(str_temp);
            str1.preprend(str2);
        break;
        case 9:
            cout << "insert another string to check" << endl;
            cin >>str_temp;
            str1+=str_temp;
        break;
        case 10:
            cout << "enter string: \n";
            cin >> str_temp;
            str2.setString(str_temp);
            str1+=str2;
        break;
        case 11:
            cout << "enter string: \n";
            cin >> str_temp;
            str2.setString(str_temp);
            if(str1>str2)
            {
                cout <<"true"<<endl;
            }
        break;
        case 12:
            cout << "enter string: \n";
            cin >> str_temp;
            if(str1.contains(str_temp)==true)
            {
                cout<<"its contains!!"<<endl;
            }
        break;    
        case 13:
            cout<<"enter index: \n";
            int index;
            cin>>index;
            cout<<str1[index]<<endl;
        break;
        case 14:
            cin>>str1;
        break;
        case 15:
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