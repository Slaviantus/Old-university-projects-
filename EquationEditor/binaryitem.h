#ifndef BINARYITEM_H
#define BINARYITEM_H

#include "commonitem.h"
#include "place.h"

#define BIN_NUM_OF_PARTS 3                                      // количество дочерних элементов

/**
 * @brief The BinaryItem class
 * Класс элемента "Бинарная операция"
 * Структура элемента:
 *   item[0] - левый операнд  (редактируемый) (LO)
 *   item[1] - символ(ы) операции             (OS)
 *   item[2] - правый операнд (редактируемый) (RO)
 * Выходная строка: LO { + | - | / | ./ | * | .* } RO
 */
class BinaryItem : public CommonItem
{
    Q_OBJECT

    QString operatorSymbol;                                     // символ(ы) бинарной операции

public:
    // Конструктор
    explicit BinaryItem(const QFont &font,  const QString os, QObject *parent = 0);
    // Элемент, представляющий левый операнд
    Place *getLeft();
    // Элемент, представляющий правый операнд
    Place *getRight();
    // задание взаимного расположения дочерних элементов
    void setChildPos();

signals:

public slots:

};

#endif // BINARYITEM_H
