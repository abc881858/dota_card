#pragma once

#include <QObject>

class Master : public QObject
{
    Q_OBJECT
public:
    explicit Master(QObject *parent = nullptr);
};
