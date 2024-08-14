#include "label.h"

Label::Label(QWidget *parent) : QLabel(parent)
{
}

void Label::focusInEvent(QFocusEvent *)
{
    setStyleSheet("QLabel { background-color : white; }");
    emit select_card();
}

void Label::focusOutEvent(QFocusEvent *)
{
    setStyleSheet("QLabel { background-color : rgb(85, 255, 255); }");
    emit deselect_card();
}
