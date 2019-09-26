#ifndef MEMMANAGER_H
#define MEMMANAGER_H
#include<string>

class memManager_t
{
public:
    memManager_t(); //default CTOR
    bool isMemEmpty()const;
    size_t getCurrentPosition()const;
    size_t setCurrentPosition(size_t);
    size_t getactualSize()const;
protected:

    virtual size_t write(const void*,size_t){return 0;}//we get number of bytes
    virtual size_t write(const void*,size_t,size_t position){return 0;}
    virtual size_t read(void*,size_t){return 0;}//return num of success bytes read
    virtual size_t read(void*,size_t,size_t position){return 0;}
    virtual ~memManaget_t();//DTOR

private:
    size_t m_currentPosition;
    size_t m_actualSize;

    

};

#endif // !MEMMANAGER_H