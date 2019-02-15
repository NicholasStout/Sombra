#ifndef WING_H
#define WING_H
#include <string>
#include <QtWidgets>

using namespace std;
class Wing: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int angle READ get_angle WRITE set_angle)
private:
    string name;
    string pathToIcon;
    QPainterPath path;
public:
    int angle;
    QRectF bound;
    int span;
    int res;
    Wing(string appName, QRectF wing_bound, int span, int new_res);
    bool contains(int x, int y);
    void set_angle(int ang);
    int get_angle();
    void make_path();
    virtual ~Wing();
    void paint(QPainter *painter, QWidget *widget);
};

#endif // WING_H
