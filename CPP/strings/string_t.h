#include <string.h>
#include<iostream>
using namespace std;
class string_t
{
public:
    ~string_t(); //DTOR
    string_t(); //default COTR
    string_t(const string_t& str); //COTR
    string_t(const char*); //copy COTR
    string_t& operator=(const string_t & str); 

    int getLen() const; //get length
    void setString(const char*); //set string
    const char* getString() const; //getstring
    int compare(const char*) const; //compare 2 string
    void printString();

    void toUppercase();
    void toLowercase();
    void preprend(const char*);
    void preprend(const string_t &);
    string_t& operator+=(const char* str);
    string_t& operator+=(const string_t & str_t);
    bool operator<(const string_t & str_t);
    bool operator>(const string_t & str_t);
    bool operator==(const string_t & str_t);
    bool operator!=(const string_t & str_t);
    bool operator<=(const string_t & str_t);
    bool operator>=(const string_t & str_t);
    bool contains(const char*);
    char operator[](size_t) const;
private:
    char* string;
    int len;
    char* createString(const char*);
};
ostream& operator<<(ostream& os,const string_t& str_t);
istream& operator>>(istream& is, string_t& str_t);

