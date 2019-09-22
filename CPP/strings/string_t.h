#include <string>
#include<iostream>

class string_t
{
public:
    string_t();
    string_t(const string_t& str);
    string_t(const char*);
    ~string_t();
    string_t& operator=(const string_t & str);

    int getLen() const;
    void setString(const char*);
    const char* getString() const;
    int compare(const char* str1) const;

private:
    char* string;
    int len;
};

