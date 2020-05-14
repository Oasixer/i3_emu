#pragma once

#include <vector>
#include <string>
//#include "Window.h"
//#include "App.h"
//#include "GlobalConfig.h"

namespace i3 {
    class App;
    class GlobalConfig;
    class DataContainer
    {
        std::vector<App*> apps;
        GlobalConfig* globalConfig;

    public:
        std::vector<App*>* getApps() { return &apps; };
        DataContainer(std::string pathToSaveDir);
        App* findAppByNameOrCreateNewIfNeeded(std::string name, std::vector<std::wstring> vec);
        void parseOpenWindowsFromVec(std::vector<std::vector<std::wstring> >* vec);
        //App* findAppByNameOrCreateNewIfNeeded(std::string name, std::vector<std::wstring>* vec);

    };
}
