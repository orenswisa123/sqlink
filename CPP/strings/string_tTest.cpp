#include "string_t.h"
#include <iostream>
using namespace std;
int main()
{
    string_t s1;
    s1.setString("orenswisa");
    cout<<s1.getString()<<"\n";
    s1.setString("avivgil");
    cout<<s1.getLen()<<"\n";
    return 1;
}