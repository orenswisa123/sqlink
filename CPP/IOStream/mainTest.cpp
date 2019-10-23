#include "asciiIO_t.h"
#include "binIO_t.h"

// int main()
// {
//     // try
//     // {
//     //     binIO_t t1("Marianna.txt","w");
//     //     t1.Fopen();
//     //     t1<<"oren",3;//write to file bin
//     // }
//     // catch(string e)
//     // {
//     //     cout<<e<<endl;
//     // }
//     // return 0;
// }

using namespace std;
void testStream(virtIO_t* virtStream, int virtType);

int main()
{
    size_t optionBinAscii = 1;

    virtIO_t *virtS=0;

    while (optionBinAscii)
    {

        cout << "1 - ASCII" << endl;
        cout << "2 - BINARY" << endl;

        cin >> optionBinAscii;
        switch (optionBinAscii)
        {
        case 1:
        {
            testStream(virtS, 1);
            break;
        }

        case 2:
        {
            testStream(virtS, 2);
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

void testStream(virtIO_t* virtStream, int virtType)
{
    string name;
    string mode;

    cout << "Enter name of file" << endl;
    cin >> name;
    cout << "Enter mode r||r+||w||w+" << endl;
    cin >> mode;

    if (virtType == 1)
    {
        virtStream = new asciiIO_t(name, mode);
    }
    else
    {
        virtStream = new binIO_t(name, mode);
    }

    virtStream->Fopen();

    while (i)
    {
        //__write <<
        //read >>

        //getlen
        //getpos
        //
    }
    
}