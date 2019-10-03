#ifndef memPool_t_H
#define memPool_t_H
#include "memPage_t.h"
#include <vector>
using namespace std;

class memPool_t : public memManager_t
{
public:
    memPool_t()
    {
        memPage_t *pg = new memPage_t;
        v.insert(v.end(), pg);
    }
    ~memPool_t()
    {
        for (int i = 0; i < v.size(); i++)
        {
            delete v[i];
        }
    }
    virtual bool isMemEmpty() const;
    virtual size_t getactualSize() const { return m_actualSize; }
    virtual size_t write(const void *, size_t); //we get number of bytes
    virtual size_t write(const void *, size_t, size_t position);
    virtual size_t read(void *, size_t); //return num of success bytes read
    virtual size_t read(void *, size_t, size_t position);

private:
    vector<memPage_t *> v;
    memPool_t(const memPool_t &mp) {}
    memPool_t &operator=(const memPool_t &mp);
    
};
#endif