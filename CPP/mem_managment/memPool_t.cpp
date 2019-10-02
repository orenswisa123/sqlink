#include "memPool_t.h"
#include <iostream>
#include <string>
#include<stdlib.h>

bool memPool_t::isMemEmpty()
{
    if (v.size() == 0 || v.size() == 1 && v[0].m_actualSize == 0)
        return true;
    else
        return false;
}
size_t memPool_t::write(const void *inputBuffer, size_t bufferSize)
{
    size_t s = 0;
    char *temp = (char *)inputBuffer;
    int i = this->getCurrentPosition();
    while (s != bufferSize)
    {
        if (i > this->v.size() - 1)
        {
            memPage_t *page = new memPage_t;
            v.insert(v.end(), page);
        }
        if (v[i]->getCurrentPosition() == 0)
        {

            s += v[i]->write(temp + s, bufferSize - s, 0);
        }
        else
        {
            cout << "test test" << v[i]->getCurrentPosition() << endl;
            s += v[i]->write(temp + s, bufferSize - s, v[i]->getCurrentPosition() + 1);
        }
        i++;
    }
    if (v.size() != 1)
    {
        this->setactualSize((v.size() - 1) * v[0]->getCapacity() + v[v.size() - 1]->getactualSize());
    }
    else
    {
        this->setactualSize(v[0]->getactualSize());
    }
    this->getCurrentPosition(--i);
    return s;
}
size_t memPool_t::write(const void *inputBuffer, size_t bufferSize, size_t pos)
{
    if (pos > this->v.size() - 1)
    {
        return 0;
    }
    size_t s = 0;
    char *temp = (char *)inputBuffer;
    int i = pos;
    while (s != bufferSize)
    {
        if (i > this->v.size() - 1)
        {
            memPage_t *page = new memPage_t;
            v.insert(v.end(), page);
        }
        if (v[i]->getCurrent() == 0)
        {
            s += v[i]->write(temp + s, bufferSize - s, 0);
        }
        else
        {
            s += v[i]->write(temp + s, bufferSize - s, v[i]->getCurrentPosition() + 1);
        }
        i++;
    }
    if (v.size() != 1)
    {
        this->setactualSize((v.size() - 1) * v[0]->getCapacity() + v[v.size() - 1]->getactualSize());
    }
    else
    {
        this->setactualSize(v[0]->getactualSize());
    }
    this->setCurrentPosition(--i);
    return s;
    ​
}

​