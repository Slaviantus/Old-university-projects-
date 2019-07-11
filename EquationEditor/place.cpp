#include "place.h"
#include <QFontMetrics>
#include <QPainter>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QTextCursor>
#include "equation.h"
//#include <QGraphicsTextItem>

PlaceEditor *Place::itemEditor(NULL);

Place::Place(const QFont &font, QObject *parent) :
    CommonItem(font, 0, parent),
    item(NULL),
    restriction(None),
    editable(true)
{
    if (!itemEditor) {
        itemEditor = new PlaceEditor(this->font);
        qDebug() << "Place::Place: editor created";
    }
    penEmptyPlace = QPen(Qt::gray);
    penEmptyPlace.setStyle(Qt::DashLine);
    penEmptyPlace.setWidthF(0.5);
    updateSize();
}

void Place::setChildPos()
{
    if (item) {
        item->setPos(0.0, 0.0);
    }
}

void Place::updateSize()
{
    prepareGeometryChange();
    QSizeF s;
    QFontMetrics fm(font);
    qreal b = border();
    if (item) {
        item->updateSize();
        s = item->boundingRect().size();
    } else {
        s = fm.size(Qt::TextSingleLine, text.isEmpty() ? QString("X") : text);
        if (s.width() < 10.0) {
            s.setWidth(10.0);
        }
    }
    s += QSizeF(2*b, 2*b);
    m_sz = s;
    m_topLeft = QPointF(0.0, -m_sz.height() / 2.0);
}

void Place::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (itemEditor->parentItem() == this && itemEditor->hasFocus()) {
        return;
    }
    QFont fnt(font);                        // этот шрифт может модифицироваться
    QString s(text);

    if (s.contains(QRegExp("[*-]"))) {
        fnt.setFamily("Symbol");
    }
    s.replace('*', QChar(0xD7));
    //s.replace('-', "-");

    QRectF r(boundingRect());
    // если знакоместо занято простым текстом, рисуем его, иначе ничего не делаем -
    // дочерний элемент нарисует себя сам
    if (!item) {
        if (!text.isEmpty()) {
            painter->setPen(Qt::black);
            painter->setFont(fnt);
            painter->drawText(r, Qt::AlignHCenter | Qt::AlignVCenter, s);
        } else {
            painter->setBrush(Qt::NoBrush);
            painter->setPen(penEmptyPlace);
            painter->drawRect(r);
        }
    }
}

void Place::insertItem(CommonItem *item)
{
    if (!item || restriction != None) {
        return;
    }
    this->item = item;
    item->setParentItem(this);
    item->setPos(0.0, 0.0);
    text.clear();
    //parseText();
}

void Place::setRestriction(const Place::Restrictions r)
{
    restriction = r;
}

Place::Restrictions Place::getRestriction() const
{
    return restriction;
}

QString Place::getText() const
{
    return text;
}

void Place::setText(const QString text)
{
    if (item) {
        removeItem();
        //item = NULL;
    }
    this->text = text;
    parseText();
}

void Place::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (!editable) {
        event->ignore();
        return;
    } else if (item) {
        event->ignore();
        return;
    }

    // редактирование
    beginEditing();
}

void Place::enableEditable(const bool mode)
{
    editable = mode;
}

bool Place::isEditable() const
{
    return editable;
}

void Place::removeItem()
{
    text.clear();
    if (!item) {
        return;
    } else {
        item->removeChildItems();
        item = NULL;
    }
    static_cast<Equation *>(getRootItem())->updateSize();
}

const CommonItem *Place::getItem() const
{
    return item;
}

PlaceEditor *Place::placeEditor()
{
    return itemEditor;
}

void Place::beginEditing()
{
    if (!isEditable()) {
        return;
    }
    if (itemEditor) {
        itemEditor->beginEditing(this);
    }
}

QRectF Place::boundingRect() const
{
    return QRectF(0.0, -m_sz.height() / 2.0,
                  m_sz.width(), m_sz.height());
}

void Place::updateText(QString newText)
{
    text = newText;
    static_cast<Equation *>(getRootItem())->updateSize();
}

void Place::endEditing()
{
    disconnect(itemEditor, SIGNAL(textChanged(QString)), 0, 0);
    disconnect(itemEditor, SIGNAL(focusLost()), 0, 0);

    parseText();
}

void Place::parseText()
{
//    QStringList parts = text.split('_', QString::SkipEmptyParts);
//    мц76м
//    // дальше доделать выделение частей основной, нижнего и верхнего индексов
}

