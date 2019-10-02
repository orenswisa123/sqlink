#include "memPool_t.h"
#include <string>

bool memPool_t::isMemEmpty()
{
    if (v.size() == 0 || v.size() == 1 && v[0].m_actualSize == 0)
        return true;
    else
        return false;
}
