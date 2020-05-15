// i3_emu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <string>
#include "pch.h"
#include "framework.h"

#include "AppInst.h"
//#include "str_utils.h"
#include "DataContainer.h"
#include "i3_emu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // initialize MFC and print and error on failure
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: code your application's behavior here.
            wprintf(L"Fatal Error: MFC initialization failed\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: code your application's behavior here.
            auto app = i3::AppInst();
            //std::shared_ptr<DataContainer> dataCont = app.getDataContainer();
            auto dataCont = app.getDataContainer();
            int a;
            //auto shit = app.getOpenWindowVec();
            // app.fgWinName();
        }
    }
    else
    {
        // TODO: change error code to suit your needs
        wprintf(L"Fatal Error: GetModuleHandle failed\n");
        nRetCode = 1;
    }

    return nRetCode;
}
