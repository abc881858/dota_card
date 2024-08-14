#pragma once

#include <QLabel>
#include <QFocusEvent>
#include <QMouseEvent>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget* parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent *) override;
    void focusOutEvent(QFocusEvent *) override;
signals:
    void select_card();
    // void deselect_card();
};
