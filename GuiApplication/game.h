#pragma once

#include <QObject>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
public slots:
    void slot_start_game();
    void end_start_game();
    void slot_finish_game();
    void end_finish_game();
    void slot_shuffle_blue_deck();
    void end_shuffle_blue_deck();
    void slot_shuffle_red_deck();
    void end_shuffle_red_deck();
signals:
    void begin_start_game();
    void begin_finish_game();
    void begin_shuffle_blue_deck();
    void begin_shuffle_red_deck();
};
