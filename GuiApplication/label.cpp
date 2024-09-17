#include "label.h"

Label::Label(QWidget *parent) : QLabel(parent)
{
    setFixedSize(100, 50);
    setAlignment(Qt::AlignCenter);
    setFocusPolicy(Qt::ClickFocus);
    setStyleSheet("QLabel { background-color : rgb(85, 255, 255); }");
}

void Label::mousePressEvent(QMouseEvent *)
{
    setStyleSheet("QLabel { background-color : white; }");
    emit select_card();
}

void Label::focusOutEvent(QFocusEvent *)
{
    setStyleSheet("QLabel { background-color : rgb(85, 255, 255); }");
}
