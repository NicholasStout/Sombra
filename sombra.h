#ifndef SOMBRA_H
#define SOMBRA_H

#include <QWidget>

namespace Ui {
class Sombra;
}

class Sombra : public QWidget
{
    Q_OBJECT

public:
     Sombra(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // SOMBRA_H
