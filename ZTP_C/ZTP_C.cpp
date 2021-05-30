// ZTP_C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ZTP_C.h"
#include "CExampleListener.h"
#include <windows.h>
#include <WinUser.h>

using namespace ZOOMINSTANTSDK;



int main()
{
    std::cout << "Hello World!\n";
    CExampleListener exampleListener;
    exampleListener.joinSession();

    bool bRet = false;
    MSG msg;
    while ((bRet = GetMessage(&msg, nullptr, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
        }
        else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
