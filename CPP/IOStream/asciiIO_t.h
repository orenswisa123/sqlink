#ifndef ASCIIIO_T_CLASS_H
#define ASCIIIO_T_CLASS_H
#include "virtIO_t.h"

class asciiIO_t : public virtIO_t
{
public:
    asciiIO_t() {}
    ~asciiIO_t() {}
    asciiIO_t(string newName, string newMode) : virtIO_t(newName, newMode)
    {
        if (m_mode != 'r' || m_mode != 'r+' || m_mode != 'w' || m_mode != 'w+')
        {
            m_status = bad_access_e;
            throw m_status;
        }
    }
    asciiIO_t &operator<<(int num);

private:
    asciiIO_t(const asciiIO_t &t);
    asciiIO_t &operator=(const asciiIO_t &t);
};
#endif