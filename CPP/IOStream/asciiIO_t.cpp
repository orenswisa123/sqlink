#include "asciiIO_t.h"

asciiIO_t &asciiIO_t::operator<<(int num)
{
    if (m_mode != 'w' || m_mode != 'w+' || m_mode != 'r+')
    {
        m_status = bad_access_e;
    }
    else if (m_status == ok_e)
    {
        int i;
        i = fprintf(this->m_fp, "%d", num);
        if (i < 0)
        {
            m_status = writeErr_e;
            throw m_status;
        }
    }
    else
    {
        throw m_status;
    }
}
asciiIO_t &asciiIO_t::operator>>(int &num)
{
    if (m_mode == 'rb' || m_mode == 'wb')
    {
        m_status = bad_access_e;
    }
    else if (m_mode == 'w')
    {
        m_status = readErr_e;
    }
    if (m_status == ok_e)
    {
        fscanf(this->m_fp, num);
    }
    else
    {
        throw m_status;
    }
}
