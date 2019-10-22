#include "virtIO_t.h"

virtIO_t::virtIO_t()
{
    m_fp = NULL;
    m_name = '/0';
    m_mode = '/0';
    m_status = ok_e;
    m_pos = 0;
}
virtIO_t::virtIO_t(string newName, string newMode)
{
    m_fp = fopen(newName, newMode);
    if (m_fp == NULL)
    {
        m_status = cant_open_file_e;
        throw m_status;
    }
    m_name = newName;
    m_mode = newMode;
    m_status = ok_e;
    m_pos = 0;
}