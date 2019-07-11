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
     void setChildPos();
};

#endif // MATRIXITEM_H
