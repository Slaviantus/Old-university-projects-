#ifndef PLACEEDITOR_H
#define PLACEEDITOR_H

#include <QGraphicsTextItem>
#include <QFont>
#include "commonitem.h"

/**
 * @brief The PlaceEditor class
 * Класс редактора линейного текста для знакомест.
 * Редактор представляет собой текстовый графический элемент.
 * Редактор появляется на экране при ЛКМ по редактируемому знакоместу и связывается
 * с этим знакоместом - отображает его текущий текст; после редактирования измененный текст
 * устанавливается снова в знакоместо. Пока редактор активен, его родительским элементом является знакоместо.
 * После завершения редактирования редактор становится невидимым.
 * Данный класс является синглетоном, т.е. предполагает наличие только единственного экземпляра.
 * Это обеспечивается за счет объявления объекта-редактора как статического члена класса знакоместа Place.
 */

class PlaceEditor : public QGraphicsTextItem
{
    Q_OBJECT
    QFont font;
public:
    // Конструктор
    explicit PlaceEditor(const QFont &font, QGraphicsItem * parent = 0);

signals:
    // Сигнал "Текст изменен"
    void textChanged(QString);
    // Сигнал "Фокус потерян"
    void focusLost();

public slots:
    // Подготовка редактора перед началом редактирования
    void beginEditing(Place *place);
    // Обработчик события "Потеря фокуса редактором"
    void focusOutEvent(QFocusEvent *event);
    // Обработчик нажатия на клавишу пользователем
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLACEEDITOR_H
