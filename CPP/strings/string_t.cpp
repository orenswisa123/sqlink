#include "string_t.h"
#include <string.h>
#include <iostream>
using namespace std;

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
void string_t::printString()
{
    cout<<string<<endl;
}
void string_t::toUppercase()
{
    int i;
    for(i=0;i<this->len;i++)
    {
    if(string[i]>='a'&&string[i]<='z')
        string[i]=string[i]-32;
    }
}
void string_t::toLowercase()
{
    int i;
    for(i=0;i<this->len;i++)
    {
    if(string[i]>='A'&&string[i]<='Z')
        string[i]=string[i]+32;
    }
}
void string_t::preprend(const char* str)
{
    char* temp=(char*)str;
    strcat(temp,this->string);
    strcpy(string,temp);
    len=strlen(string);
}
void string_t::preprend(const string_t& str_t)
{
    preprend(str_t.string);
}
string_t& string_t::operator+=(const char* str)
{
    strcat(this->string,str);
    this->len=strlen(this->string);
    return *this;
}
string_t& string_t::operator+=(const string_t & str_t)
{
    strcat(string,str_t.string);
    len=strlen(string);
    return *this;
}
bool string_t::operator<(const string_t & str_t)
{
    if(strcmp(this->string,str_t.string)<0)
    {
    return true;
    }
    return false;
}
bool string_t::operator>(const string_t & str_t)
{
    if(strcmp(this->string,str_t.string)>0)
    {
    return true;
    }
    return false;
}
bool string_t::operator==(const string_t & str_t)
{
    if(strcmp(this->string,str_t.string)==0)
    return true;
    return false;
}
bool string_t::operator!=(const string_t & str_t)
{
    if(strcmp(this->string,str_t.string)!=0)
    return true; 
    return false;
}
bool string_t::operator<=(const string_t & str_t)
{
    if(strcmp(this->string,str_t.string)<=0)
    {
    return true;
    }
    return false;

}
bool string_t::operator>=(const string_t & str_t)
{
    if(strcmp(this->string,str_t.string)>=0)
    {
    return true;
    }
    return false;
}
bool string_t::contains(const char* str)
{
    if(strstr(string,str)!=NULL)
    {
        return true;
    }
    return false;
}
char string_t::operator[](size_t index) const
{
    if(index<=this->len)
    {
    return this->string[index];
    }
    else
    {
        cout<<"out on bound \n";
    }
}
char& string_t::operator[](size_t index)
{
    if(index>this->len)
    {
        cout<<"out on bound \n";
        return NULL;
    }
    return this->string[index];
}
ostream& operator<<(ostream& os,const string_t& str_t)
{
    os<< "string: " << str_t.getString()<<endl
    << "length: " << str_t.getLen()<<endl;
    return os;
}
istream& operator>>(istream& is, string_t& str_t)
{
    char str[64];
    is >> str;
    str_t.setString(str);
    return is;


}



