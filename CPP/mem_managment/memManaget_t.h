#ifndef MEMMANAGER_H
#define MEMMANAGER_H
#include<string>

class memManaget_t
{
public:
    memManager_t(); //default CTOR
    bool isMemEmpty()const;
    size_t getCurrentPosition()const;
    size_t setCurrentPosition(size_t);
    size_t getactualSize()const;
protected:

    virtual size_t write(const void*,size_t);//we get number of bytes
    virtual size_t write(const void*,size_t,size_t position);
    virtual size_t read(void*,size_t)//return num of success bytes read
    virtual size_t read(void*,size_t,size_t position);
    virtual ~memManaget_t();//DTOR

private:
    size_t m_currentPosition;
    size_t m_capacity;

    

}

#endif // !MEMMANAGER_H