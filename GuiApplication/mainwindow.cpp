#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define SHOW_DEBUG_INFO qDebug() << QString("%1").arg(metaObject()->className()) << __func__;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    game = new Game;
    connect(&thread, &QThread::finished, game, &Game::deleteLater);

    connect(this, &MainWindow::signal_start_game, game, &Game::slot_start_game);
    connect(game, &Game::begin_start_game, this, &MainWindow::begin_start_game);
    connect(this, &MainWindow::end_start_game, game, &Game::end_start_game);

    connect(this, &MainWindow::signal_finish_game, game, &Game::slot_finish_game);
    connect(game, &Game::begin_finish_game, this, &MainWindow::begin_finish_game);
    connect(this, &MainWindow::end_finish_game, game, &Game::end_finish_game);

    connect(this, &MainWindow::signal_shuffle_blue_deck, game, &Game::slot_shuffle_blue_deck);
    connect(game, &Game::begin_shuffle_blue_deck, this, &MainWindow::begin_shuffle_blue_deck);
    connect(this, &MainWindow::end_shuffle_blue_deck, game, &Game::end_shuffle_blue_deck);

    connect(this, &MainWindow::signal_shuffle_red_deck, game, &Game::slot_shuffle_red_deck);
    connect(game, &Game::begin_shuffle_red_deck, this, &MainWindow::begin_shuffle_red_deck);
    connect(this, &MainWindow::end_shuffle_red_deck, game, &Game::end_shuffle_red_deck);

    thread.start();
}

MainWindow::~MainWindow()
{
    thread.quit();
    thread.wait();
    delete ui;
}

void MainWindow::on_game_start_triggered()
{
    SHOW_DEBUG_INFO
    emit signal_start_game();
}

void MainWindow::on_game_finish_triggered()
{
    SHOW_DEBUG_INFO
    emit signal_finish_game();
}

void MainWindow::begin_start_game()
{
    SHOW_DEBUG_INFO
    //animate start_game
    emit end_start_game();
}

void MainWindow::begin_finish_game()
{
    SHOW_DEBUG_INFO
    //animate finish_game
    emit end_finish_game();
}

void MainWindow::on_shuffle_blue_deck_triggered()
{
    SHOW_DEBUG_INFO
    emit signal_shuffle_blue_deck();
}

void MainWindow::begin_shuffle_blue_deck()
{
    SHOW_DEBUG_INFO
    //animate shuffle_blue_deck
    emit end_shuffle_blue_deck();
}

void MainWindow::on_shuffle_red_deck_triggered()
{
    SHOW_DEBUG_INFO
    emit signal_shuffle_red_deck();
}

void MainWindow::begin_shuffle_red_deck()
{
    SHOW_DEBUG_INFO
    //animate shuffle_red_deck
    emit end_shuffle_red_deck();
}
