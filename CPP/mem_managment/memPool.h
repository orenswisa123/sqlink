#include "memPage.h"
#include <vector>
using namespace std;

class memPool: public memManager_t
{
    public:
    memPool()
    {
        Page_t* pg= new Page_t;
        v.insert(v.end(),pg);
    }
    ~memPool()
    {
        for(int i=0;i<v.size();i++)
        {
            delete v[i];
        }
    }
    virtual write;
    virtual read;


    private:
    vector<Page_t*> v;
}