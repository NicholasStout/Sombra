#include "wing.h"
#include <string>
#include <fstream>

    Wing::Wing(string appName)
    {
        string line;
        ifstream desktop;
        desktop.open ("/usr/share/applications/");
        if (desktop.is_open())
        {
            while (getline(desktop, line))
            {
                if (line.find("Name="))
                {
                    name = line.substr(5);
                }
            }
        }
    }



