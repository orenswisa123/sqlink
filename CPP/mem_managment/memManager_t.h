#ifndef MEMMANAGER_H
#define MEMMANAGER_H
#include <string>

class memManager_t
{
public:
    memManager_t(); //default CTOR
    virtual bool isMemEmpty() const;
    virtual bool isMemFull() const;
    size_t getCurrentPosition() const { return m_currentPosition; }
    void setCurrentPosition(size_t); //do with try catch and throw
    size_t getactualSize() const { return m_actualSize; }
    void setactualSize(size_t);

protected:
    virtual size_t write(const void *, size_t) { return 0; } //we get number of bytes
    virtual size_t write(const void *, size_t, size_t position) { return 0; }
    virtual size_t read(void *, size_t) { return 0; } //return num of success bytes read
    virtual size_t read(void *, size_t, size_t position) { return 0; }
    size_t m_currentPosition;
    size_t m_actualSize;
    virtual ~memManager_t(); //DTOR

private:
    
    memManager_t(const memManager_t &mm) {}
    memManager_t &operator=(const memManager_t &mm) {}
};

#endif // !MEMMANAGER_H