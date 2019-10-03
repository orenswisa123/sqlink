#include "memPage_t.h"
#include "memPool_t.h"
#include <iostream>
#include <cstring>
using namespace std;

void test(memManager_t *m);

int main()
{
    size_t option;
    memManager_t *mptr;

    cout << "Choose object: 1-MemPage, 2-MemPool" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        mptr = new memPage_t;
        break;

    case 2:
        mptr = new memPool_t;
        break;

    default:
        break;
    }

    test(mptr);
  //  delete mptr;

    return 0;
}

void test(memManager_t *m)
{
    size_t count, option, position, size;
    bool cont = true;

    while (cont)
    {
        cout << "1. Write with position" << endl
             << "2. Write without position" << endl
             << "3. Read with position" << endl
             << "4. Read without position" << endl
             << "5. Set position" << endl
             << "Any another number - stop" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
        {
            char buffer[32];
            cout << "Enter string to write: " << endl;
            cin >> buffer;
            cout << "Enter size and position: " << endl;
            cin >> size >> position;

            try
            {
                count = m->write(buffer, size, position);
            }
            catch (string e)
            {
                cerr << e << endl;
                break;
            }

            break;
        }
        case 2:
        {
            char buffer[32];
            cout << "Enter string to write: " << endl;
            cin >> buffer;
            cout << "Enter size: " << endl;
            cin >> size;

            try
            {
                count = m->write(buffer, size);
            }
            catch (string e)
            {
                cerr << e << endl;
                break;
            }

            break;
        }
        case 3:
        {
            char buffer[32];
            memset(&buffer, '\0', 32);
            cout << "Enter size and position: " << endl;
            cin >> size >> position;

            try
            {
                count = m->read(buffer, size, position);
            }
            catch (string e)
            {
                cerr << e << endl;
                break;
            }

            cout << buffer << endl;
            break;
        }
        case 4:
        {
            char buffer[32];
            memset(&buffer, '\0', 32);
            cout << "Enter size: " << endl;
            cin >> size;

            try
            {
                count = m->read(buffer, size);
            }
            catch (string e)
            {
                cerr << e << endl;
                break;
            }

            cout << buffer << endl;
            break;
        }
        case 5:
        {
            cout << "Enter position: " << endl;
            cin >> position;
            try
            {
                m->setCurrentPosition(position);
            }
            catch (string e)
            {
                cerr << e << endl;
            }
            break;
        }
        default:
        {
            cont = false;
            break;
        }
        }
    }
}
