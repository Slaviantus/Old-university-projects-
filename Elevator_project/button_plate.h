#ifndef BUTTON_PLATE_H
#define BUTTON_PLATE_H
#include "QGraphicsPixmapItem"
#include "QObject"


class Button_plate : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button_plate();
protected:
    bool sceneEvent(QEvent *event);
signals:
    void button_clicked();
};

#endif // BUTTON_PLATE_H
