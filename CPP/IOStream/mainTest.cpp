#include "asciiIO_t.h"
#include "binIO_t.h"

int main()
{
    try
    {
        binIO_t t1("Marianna.txt","w+");
        t1.Fopen();
        t1.operator<<(5);//write to file bin
    }
    catch(string e)
    {
        cout<<e<<endl;
    }
    return 0;
}