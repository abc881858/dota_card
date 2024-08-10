#pragma once

#include <QMainWindow>
#include <QThread>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Game *game;
    QThread thread;
public slots:
    void begin_start_game();
    void begin_finish_game();
    void begin_shuffle_blue_deck();
    void begin_shuffle_red_deck();
private slots:
    void on_game_start_triggered();
    void on_game_finish_triggered();
    void on_shuffle_blue_deck_triggered();
    void on_shuffle_red_deck_triggered();
signals:
    void signal_start_game();
    void end_start_game();
    void signal_finish_game();
    void end_finish_game();
    void signal_shuffle_blue_deck();
    void end_shuffle_blue_deck();
    void signal_shuffle_red_deck();
    void end_shuffle_red_deck();
};
