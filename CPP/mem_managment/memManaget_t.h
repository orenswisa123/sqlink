#ifndef MEMMANAGER_H
#define MEMMANAGER_H

class memManaget_t
{
public:
    memManager_t(); //default CTOR
    bool isMemEmpty();
    size_t getCurrentPosition();
    size_t setCurrentPosition();
protected:
    virtual size_t writeFuncInPlace(void*,size_t);//we get number of bytes
    virtual size_t writeFuncOtherPlace(size_t position,void*,size_t);
    virtual size_t readFuncInPlace(size_t)//return num of success bytes read
    virtual size_t readFuncOtherPlace(size_t position,size_t);

    ~memManaget_t();//DTOR

    
    size_t getactualSize();


private:
    size_t m_currentPosition;
    size_t m_capacity;

    

}

#endif // !MEMMANAGER_H