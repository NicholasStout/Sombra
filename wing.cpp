#include "wing.h"
#include <string>
#include <fstream>

    Wing::Wing(string appName, QRectF wing_bound, int span, int new_res)
    {
        bound = wing_bound;
        this->span = span;
        res = new_res;
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

    Wing::~Wing() {}

    void Wing::set_angle(int ang)
    {
        angle = ang;
    }

    int Wing::get_angle()
    {
        return angle;
    }

    void Wing::make_path()
    {
        path = QPainterPath();
        path.arcMoveTo(bound, angle);
        path.arcTo(bound, angle, span);
        path.arcTo(-res, -res, res * 2, res * 2, (span+angle), -span);
        path.closeSubpath();
   }

   void Wing::paint(QPainter *painter, QWidget *widget)
   {
       this->make_path();
       painter->drawPath(path);
   }




