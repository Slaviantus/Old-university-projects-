#ifndef FLOORS_H
#define FLOORS_H
#include <QWidget>
#include <QRect>
#include "QPoint"

using namespace std;

class floors: public QWidget
{
    Q_OBJECT
public:
    floors();
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QRect rect;
    QPoint point;
};

#endif // FLOORS_H
