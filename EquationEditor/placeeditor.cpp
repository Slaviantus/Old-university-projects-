#include "placeeditor.h"
#include "place.h"
#include <QKeyEvent>
#include <QDebug>

/**
 * @brief PlaceEditor::PlaceEditor
 * Конструктор.
 * @param font
 * Шрифт, задаваемый в редакторе. Как правило, шрифт устанавливается таким же, как и в
 * родительском знакоместе.
 * @param parent
 * Родительский элемент (не задается)
 */
PlaceEditor::PlaceEditor(const QFont &font, QGraphicsItem *parent) :
    QGraphicsTextItem(parent)
{
    setVisible(false);
    this->font = font;
    //setFont(font);
}

/**
 * @brief PlaceEditor::beginEditing
 * Подготовка редактора к началу редактирования. Устанавливается шрифт, соответствующий
 * шрифту родительского знакоместа; редактор становится видимым; настраиваются его параметры;
 * устаналивается фокус ввода в редактор; выполняются соединения слотов и сигналов.
 * @param place
 * Редактируемое знакоместо. На время редактирования устаналивается в качестве родительского элемента
 * для редактора.
 */
void PlaceEditor::beginEditing(Place *place)
{

    setFont(place->getFont());
    setParentItem(place);
    setVisible(true);
    setPlainText(place->getText());
    setPos(QPointF(-3.0, -place->boundingRect().height() / 2.0-4.0));
    setTextInteractionFlags(Qt::TextEditorInteraction);
    setFocus(Qt::MouseFocusReason);
    connect(this, SIGNAL(textChanged(QString)), place, SLOT(updateText(QString)));
    connect(this, SIGNAL(focusLost()), place, SLOT(endEditing()));
}

/**
 * @brief PlaceEditor::focusOutEvent
 * Виртуальный метод - обработчик события "Потерян фокус".
 * Редактор скрывается; разрывается связь с родительским знакоместом;
 * генерируется сигнал "Потерян фокус редактором".
 * @param event
 * Объект с параметрами события. См. справку по классу QFocusEvent.
 */
void PlaceEditor::focusOutEvent(QFocusEvent *event)
{
    Qt::FocusReason reason = event->reason();
    if (reason > 1)
        return;
    QGraphicsTextItem::focusOutEvent(event);
    setVisible(false);
    setParentItem(NULL);
    qDebug() << "PlaceEditor::focusOutEvent: " << event->reason();
    emit focusLost();
}

/**
 * @brief PlaceEditor::keyPressEvent
 * Виртуальный метод - обработчик события "Нажатие на клавишу на клавиатуре".
 * @param event
 * Объект с параметрами события. См. справку по классу QKeyEvent.
 */
void PlaceEditor::keyPressEvent(QKeyEvent *event)
{
    static QString s1;
    static QString s2;
    s1 = this->toPlainText();
    switch (event->key()) {
    case Qt::Key_Enter:
    case Qt::Key_Escape:
        clearFocus();
        return;
    }

    QGraphicsTextItem::keyPressEvent(event);
    s2 = this->toPlainText();
    if (s1.length() != s2.length()
            || s1 != s2) {
        emit textChanged(s2);
    }
}
