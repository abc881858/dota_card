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
<<<<<<< HEAD
=======

void MainWindow::on_phase_blue_draw_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_blue_draw();
}

void MainWindow::begin_phase_blue_draw()
{
    SHOW_DEBUG_INFO;
    //animate phase_blue_draw
    emit end_phase_blue_draw();
}

void MainWindow::on_phase_blue_standby_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_blue_standby();
}

void MainWindow::begin_phase_blue_standby()
{
    SHOW_DEBUG_INFO;
    //animate phase_blue_standby
    emit end_phase_blue_standby();
}

void MainWindow::on_phase_blue_main1_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_blue_main1();
}

void MainWindow::begin_phase_blue_main1()
{
    SHOW_DEBUG_INFO;
    //animate phase_blue_main1
    emit end_phase_blue_main1();
}

void MainWindow::on_phase_blue_battle_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_blue_battle();
}

void MainWindow::begin_phase_blue_battle()
{
    SHOW_DEBUG_INFO;
    //animate phase_blue_battle
    emit end_phase_blue_battle();
}

void MainWindow::on_phase_blue_main2_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_blue_main2();
}

void MainWindow::begin_phase_blue_main2()
{
    SHOW_DEBUG_INFO;
    //animate phase_blue_main2
    emit end_phase_blue_main2();
}

void MainWindow::on_phase_blue_end_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_blue_end();
}

void MainWindow::begin_phase_blue_end()
{
    SHOW_DEBUG_INFO;
    //animate phase_blue_end
    emit end_phase_blue_end();
}

void MainWindow::on_phase_red_draw_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_red_draw();
}

void MainWindow::begin_phase_red_draw()
{
    SHOW_DEBUG_INFO;
    //animate phase_red_draw
    emit end_phase_red_draw();
}

void MainWindow::on_phase_red_standby_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_red_standby();
}

void MainWindow::begin_phase_red_standby()
{
    SHOW_DEBUG_INFO;
    //animate phase_red_standby
    emit end_phase_red_standby();
}

void MainWindow::on_phase_red_main1_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_red_main1();
}

void MainWindow::begin_phase_red_main1()
{
    SHOW_DEBUG_INFO;
    //animate phase_red_main1
    emit end_phase_red_main1();
}

void MainWindow::on_phase_red_battle_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_red_battle();
}

void MainWindow::begin_phase_red_battle()
{
    SHOW_DEBUG_INFO;
    //animate phase_red_battle
    emit end_phase_red_battle();
}

void MainWindow::on_phase_red_main2_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_red_main2();
}

void MainWindow::begin_phase_red_main2()
{
    SHOW_DEBUG_INFO;
    //animate phase_red_main2
    emit end_phase_red_main2();
}

void MainWindow::on_phase_red_end_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_phase_red_end();
}

void MainWindow::begin_phase_red_end()
{
    SHOW_DEBUG_INFO;
    //animate phase_red_end
    emit end_phase_red_end();
}

void MainWindow::on_blue_draw_one_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_blue_draw_cards(1);
}

void MainWindow::on_blue_draw_two_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_blue_draw_cards(2);
}

void MainWindow::on_blue_draw_three_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_blue_draw_cards(3);
}

void MainWindow::on_blue_draw_four_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_blue_draw_cards(4);
}

void MainWindow::on_blue_draw_five_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_blue_draw_cards(5);
}

void MainWindow::begin_blue_draw_cards(int size)
{
    SHOW_DEBUG_INFO;
    //animate blue_draw_cards
    emit end_blue_draw_cards(size);
}

void MainWindow::on_red_draw_one_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_red_draw_cards(1);
}

void MainWindow::on_red_draw_two_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_red_draw_cards(2);
}

void MainWindow::on_red_draw_three_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_red_draw_cards(3);
}

void MainWindow::on_red_draw_four_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_red_draw_cards(4);
}

void MainWindow::on_red_draw_five_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_red_draw_cards(5);
}

void MainWindow::begin_red_draw_cards(int size)
{
    SHOW_DEBUG_INFO;
    //animate red_draw_cards
    emit end_red_draw_cards(size);
}

void MainWindow::on_record_load_triggered()
{
    SHOW_DEBUG_INFO;
    QString fileName = QFileDialog::getOpenFileName(this, "record load", "C:/Users/Administrator/Desktop/Git/dota_card/GuiApplication", "*.csv");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QStringList list;
    while(!file.atEnd())
    {
        QString str = file.readLine().simplified();
        list << str;
    }
    file.close();

    qDebug() << "record list size:" << list.size();
    emit signal_record_load(list);
}

void MainWindow::on_record_next_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_record_next();
}

void MainWindow::on_record_save_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_record_save();
}

void MainWindow::begin_record_save(QStringList list)
{
    SHOW_DEBUG_INFO;
    QFile file(QString("C:/Users/Administrator/Desktop/Git/dota_card/GuiApplication/%1.csv").arg(QTime::currentTime().toString("record_hhmmss")));
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    for(QString str : list)
    {
        file.write(str.toUtf8());
    }
    file.close();
}

void MainWindow::on_move_card_clicked()
{
    SHOW_DEBUG_INFO;
    emit signal_move_card(ui->card_sn_move->text().toInt(), ui->from_area_move->currentText(), ui->from_index_move->text().toInt(), ui->to_area_move->currentText(), ui->to_index_move->text().toInt());
}

void MainWindow::begin_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index)
{
    SHOW_DEBUG_INFO;
    emit end_move_card(card_sn, from_area, from_index, to_area, to_index);
}

void MainWindow::on_effect_card_clicked()
{
    SHOW_DEBUG_INFO;
    emit signal_effect_card(ui->card_sn_effect->text().toInt(), ui->from_area_effect->currentText(), ui->from_index_effect->text().toInt());
}

void MainWindow::begin_effect_card(int card_sn, QString from_area, int from_index)
{
    SHOW_DEBUG_INFO;
    emit end_effect_card(card_sn, from_area, from_index);
}

void MainWindow::on_try_card_clicked()
{
    SHOW_DEBUG_INFO;
    emit signal_try_card(ui->card_sn_try->text().toInt(), ui->from_area_try->currentText(), ui->from_index_try->text().toInt());
}

void MainWindow::begin_try_card(int card_sn, QString from_area, int from_index)
{
    SHOW_DEBUG_INFO;
    emit end_try_card(card_sn, from_area, from_index);
}
>>>>>>> 16bc7a1 (fix game_finish bug && record_next bug)
