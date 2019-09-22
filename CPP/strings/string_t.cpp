#include "string_t.h"
#include <string.h>

string_t::string_t()
{
    string = 0;
    len = 0;
}
string_t::~string_t()
{
    delete[] string;
}

string_t::string_t(const string_t& str)
{
    string=new char[strlen(str.string)+1];
    strcpy(this->string,str.string);
    len=str.len;
}
string_t::string_t(const char* str)
{
    string=new char[strlen(str)+1];
    strcpy(this->string,str);
    len=strlen(str);
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
    string=new char[strlen(str)+1];
    strcpy(string,str);
    len=strlen(str);
}
string_t& string_t::operator=(const string_t & str)
{
    if(this!=&str)
    {
        delete[] string;
        string=new char[strlen(str.string)+1];
        strcpy(string,str.string);
        len=strlen(str.string);
    }
}
int string_t::compare(const char* str1) const
{
    if(string==str1)
    {
        return 0;
    }
    if(string>str1)
    {
        return 2;
    }
    if(str1>string)
    {
        return 1;
    }
}


