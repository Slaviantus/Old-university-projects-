#ifndef MATRIXITEM_H
#define MATRIXITEM_H

#include "commonitem.h"
#include "place.h"

#define MATRIX_PARTS 9

class MatrixItem : public CommonItem
{
    Q_OBJECT
public:
     explicit MatrixItem(const QFont &font, QObject *parent = 0);
     void setChildPos() override;
     void updateSize() override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
     int max_index_1;
     int max_index_2;
     int max_index_3;
     double max_windth;
};

#endif // MATRIXITEM_H
