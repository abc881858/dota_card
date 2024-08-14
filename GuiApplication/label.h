#pragma once

#include <QLabel>
#include <QFocusEvent>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget* parent = nullptr);
protected:
    void focusInEvent(QFocusEvent *) override;
    void focusOutEvent(QFocusEvent *) override;
signals:
    void select();
    void deselect();
};
