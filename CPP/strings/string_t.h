#include <string>
#include<iostream>

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

private:
    char* string;
    int len;
    char* createString(const char*);
};

