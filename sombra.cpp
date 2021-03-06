#include "sombra.h"
#include "wing.h"
#include <QtWidgets>
QPainterPath wing;
QPoint offset;




Sombra::Sombra(QWidget *parent) :
    QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint);
    //set screen invisble and frameless

    QRect off = QApplication::desktop()->screenGeometry(this);
    QRect screen = QApplication::desktop()->availableGeometry(this);
    offset = QPoint(off.width() - screen.width(), off.height() - screen.height());

    QSize *size = new QSize(screen.height(), screen.width());

    //Get demensions for the launcher

    QRect *start = new QRect(QPoint(0,0), *size);
    setGeometry(*start);
    setFixedHeight(screen.height());
    setFixedWidth(screen.width());
    //set location to be centered on the mouse
}

void Sombra::paintEvent(QPaintEvent *)
{
    int newRes = 260;
    QPoint mouse = QCursor::pos();
    offset.setX(mouse.x() - offset.x());
    offset.setY(mouse.y() - offset.y());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QColor c(127, 0, 127);
    painter.setPen(Qt::NoPen);
    painter.setBrush(c);
    painter.translate(offset);

    QPainterPath center;
    QRectF wingBound = QRectF(newRes * -1.5, newRes * -1.5, newRes * 3, newRes * 3);
    QRectF bound = QRectF(newRes * -0.75, newRes * -0.75, newRes * 1.5, newRes * 1.5);
    center.addEllipse(bound);

    int span = 80;
    int off = 40;
    //wing.moveTo(newRes, 0);
//    wing.arcMoveTo(wingBound, off);
//    wing.arcTo(wingBound, off, span);
//    wing.arcTo(-newRes, -newRes, newRes * 2, newRes * 2, span+off, -span);
//    wing.closeSubpath();

//    painter.drawPath(center);
//    for (int i = 0; i < 8; i++)
//    {
//    //painter.drawPath(wing);
//    wing.arcMoveTo(wingBound, (off+180));
//    wing.arcTo(wingBound, (off+180), span);
//    wing.arcTo(-newRes, -newRes, newRes * 2, newRes * 2, span+(off+180), -span);
//    wing.closeSubpath();
//    painter.drawPath(wing);
//    }
    Wing test("", wingBound, span, newRes);
    test.set_angle(0);
    test.paint(&painter, this);
}

void Sombra::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF m = QPointF(event->pos().x() - offset.x(), event->pos().y() - offset.y());
        //QPointF m = QPointF(event->pos().x(), event->pos().y());
        if (wing.contains(m))
        {
            //TODO Finish this
        }
        else
        {
            qInfo();
            QApplication::quit();
        }
    }
}
