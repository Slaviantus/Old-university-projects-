#ifndef PLACE_H
#define PLACE_H

#include "commonitem.h"
#include <QPen>
#include <QGraphicsTextItem>
#include "placeeditor.h"

/**
  Класс знакоместа.
  Знакоместо используется в качестве дочернего элемента, который может содержать текст (число, идентификатор, символ(ы) операции)
  или вложенный дочерний блок - элемент формулы.
  Знакоместо может быть редактируемым либо нередактируемым. При щелчке по редактируемому знакоместу на его месте появляется
  поле редактирования текста. При щелчке по нередактиуемому знакоместу выделяется его родительский блок.
**/

class Place : public CommonItem
{
    Q_OBJECT
public:
    enum Restrictions { None, ValueOnly, IDOnly };

public:
    explicit Place(const QFont &font, QObject *parent = 0);

    void updateSize();
    void setChildPos();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void insertItem(CommonItem *item);
    void setRestriction(const Restrictions r);
    Restrictions getRestriction() const;
    QString getText() const;
    void setText(const QString text);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void enableEditable(const bool mode = true);
    bool isEditable() const;
    void removeItem();
    const CommonItem *getItem() const;
    static PlaceEditor *placeEditor();
    void beginEditing();
    QRectF boundingRect() const;

signals:

public slots:
    void updateText(QString newText);
    void endEditing();

private:
    void parseText();

private:
    QString text;                           // текстовое значение (равно "", если в знакоместо вставлен элемент)
    CommonItem *item;                       // элемент, вставленный в знакоместо. Если NULL, отображается текст
    Restrictions restriction;
    bool editable;
    QPen penEmptyPlace;
    static PlaceEditor *itemEditor;
    QString lowerIndex;                     // строка нижнего индекса
    QString upperIndex;                     // строка верхнего индекса
    QString baseStr;                        // строка основная

};

#endif // PLACE_H
