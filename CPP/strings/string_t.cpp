#include "string_t.h"
#include <string.h>

string_t::string_t()
{
    createString(0);
}
string_t::~string_t()
{
    delete[] string;
}
string_t::string_t(const string_t& str)
{
    createString(str.string);
}
string_t::string_t(const char* str)
{
    createString(str);
}
int string_t::getLen() const
{
    return len;
}
const char* string_t::getString() const
{
    return string;
}
void string_t::setString(const char* str)
{
    createString(str);
}
string_t& string_t::operator=(const string_t & str)
{
    if(this!=&str)
    {
        delete[] string;
        createString(str.string);
    }
    return *this;
}
int string_t::compare(const char* str1) const
{
    int c = strcmp(string,str1);
    if(c==0)
    {
        return 0;
    }
    if(c<0)
    {
        return 2;
    }
    if(c>0)
    {
        return 1;
    }
}
char* string_t::createString(const char* str)
{
    if(str==0)
    {
        string = new char[256];
        string[0]='\0';
    }
    else
    {
        string=new char[strlen(str)+1];
        strcpy(string,str);
        len=strlen(str);
    }
    return string;
    
}


