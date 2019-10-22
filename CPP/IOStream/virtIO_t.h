#ifndef VIRTIO_T_CLASS_H
#define VIRTIO_T_CLASS_H
#include <iostream>
#include <string>
using namespace std;
enum status
{
    ok_e,
    cant_open_file_e,
    bad_access_e,
    writeErr_e,
    readErr_e
};
class virtIO_t
{
public:
    virtIO_t();
    virtIO_t(string, string);
    virtual ~virtIO_t() = 0;
    virtual size_t getfileLen() const;
    virtual string getFileName() const { return m_name; }
    virtual string getFileMode() const { return m_mode; }
    virtual size_t getPosition() const { return m_pos; }
    virtual void setPosition(size_t position);
    virtual status getStatus() const { return m_status; }
    virtual status setStatus(status) { m_status = status; }

    virtual virtIO_t &operator>>(int &num) = 0;

    virtual virtIO_t &operator<<(int num) = 0; //need to do to all types!!!  work with fprintf(fp,"%d",num)

private:
    virtIO_t(const virtIO_t &t);
    virtIO_t &operator=(const virtIO_t &t);

protected:
    FILE *m_fp;
    status m_status;
    string m_name;
    string m_mode;
    size_t m_pos;
};
#endif