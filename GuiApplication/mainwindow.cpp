#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QTime>
#include "label.h"

#define SHOW_DEBUG_INFO qDebug() << QString("%1").arg(metaObject()->className()) << __func__

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    game = new Game;
    connect(&thread, &QThread::finished, game, &Game::deleteLater);

    connect(this, &MainWindow::signal_game_start, game, &Game::slot_game_start);
    connect(game, &Game::begin_game_start, this, &MainWindow::begin_game_start);
    connect(this, &MainWindow::end_game_start, game, &Game::end_game_start);

    connect(this, &MainWindow::signal_game_finish, game, &Game::slot_game_finish);
    connect(game, &Game::begin_game_finish, this, &MainWindow::begin_game_finish);
    connect(this, &MainWindow::end_game_finish, game, &Game::end_game_finish);

    connect(this, &MainWindow::signal_shuffle_blue_deck, game, &Game::slot_shuffle_blue_deck);
    connect(game, &Game::begin_shuffle_blue_deck, this, &MainWindow::begin_shuffle_blue_deck);
    connect(this, &MainWindow::end_shuffle_blue_deck, game, &Game::end_shuffle_blue_deck);

    connect(this, &MainWindow::signal_shuffle_red_deck, game, &Game::slot_shuffle_red_deck);
    connect(game, &Game::begin_shuffle_red_deck, this, &MainWindow::begin_shuffle_red_deck);
    connect(this, &MainWindow::end_shuffle_red_deck, game, &Game::end_shuffle_red_deck);

    connect(this, &MainWindow::signal_phase_blue_draw, game, &Game::slot_phase_blue_draw);
    connect(game, &Game::begin_phase_blue_draw, this, &MainWindow::begin_phase_blue_draw);
    connect(this, &MainWindow::end_phase_blue_draw, game, &Game::end_phase_blue_draw);

    connect(this, &MainWindow::signal_phase_blue_standby, game, &Game::slot_phase_blue_standby);
    connect(game, &Game::begin_phase_blue_standby, this, &MainWindow::begin_phase_blue_standby);
    connect(this, &MainWindow::end_phase_blue_standby, game, &Game::end_phase_blue_standby);

    connect(this, &MainWindow::signal_phase_blue_main1, game, &Game::slot_phase_blue_main1);
    connect(game, &Game::begin_phase_blue_main1, this, &MainWindow::begin_phase_blue_main1);
    connect(this, &MainWindow::end_phase_blue_main1, game, &Game::end_phase_blue_main1);

    connect(this, &MainWindow::signal_phase_blue_battle, game, &Game::slot_phase_blue_battle);
    connect(game, &Game::begin_phase_blue_battle, this, &MainWindow::begin_phase_blue_battle);
    connect(this, &MainWindow::end_phase_blue_battle, game, &Game::end_phase_blue_battle);

    connect(this, &MainWindow::signal_phase_blue_main2, game, &Game::slot_phase_blue_main2);
    connect(game, &Game::begin_phase_blue_main2, this, &MainWindow::begin_phase_blue_main2);
    connect(this, &MainWindow::end_phase_blue_main2, game, &Game::end_phase_blue_main2);

    connect(this, &MainWindow::signal_phase_blue_end, game, &Game::slot_phase_blue_end);
    connect(game, &Game::begin_phase_blue_end, this, &MainWindow::begin_phase_blue_end);
    connect(this, &MainWindow::end_phase_blue_end, game, &Game::end_phase_blue_end);

    connect(this, &MainWindow::signal_phase_red_draw, game, &Game::slot_phase_red_draw);
    connect(game, &Game::begin_phase_red_draw, this, &MainWindow::begin_phase_red_draw);
    connect(this, &MainWindow::end_phase_red_draw, game, &Game::end_phase_red_draw);

    connect(this, &MainWindow::signal_phase_red_standby, game, &Game::slot_phase_red_standby);
    connect(game, &Game::begin_phase_red_standby, this, &MainWindow::begin_phase_red_standby);
    connect(this, &MainWindow::end_phase_red_standby, game, &Game::end_phase_red_standby);

    connect(this, &MainWindow::signal_phase_red_main1, game, &Game::slot_phase_red_main1);
    connect(game, &Game::begin_phase_red_main1, this, &MainWindow::begin_phase_red_main1);
    connect(this, &MainWindow::end_phase_red_main1, game, &Game::end_phase_red_main1);

    connect(this, &MainWindow::signal_phase_red_battle, game, &Game::slot_phase_red_battle);
    connect(game, &Game::begin_phase_red_battle, this, &MainWindow::begin_phase_red_battle);
    connect(this, &MainWindow::end_phase_red_battle, game, &Game::end_phase_red_battle);

    connect(this, &MainWindow::signal_phase_red_main2, game, &Game::slot_phase_red_main2);
    connect(game, &Game::begin_phase_red_main2, this, &MainWindow::begin_phase_red_main2);
    connect(this, &MainWindow::end_phase_red_main2, game, &Game::end_phase_red_main2);

    connect(this, &MainWindow::signal_phase_red_end, game, &Game::slot_phase_red_end);
    connect(game, &Game::begin_phase_red_end, this, &MainWindow::begin_phase_red_end);
    connect(this, &MainWindow::end_phase_red_end, game, &Game::end_phase_red_end);

    connect(this, &MainWindow::signal_blue_draw_cards, game, &Game::slot_blue_draw_cards);
    connect(game, &Game::begin_blue_draw_cards, this, &MainWindow::begin_blue_draw_cards);
    connect(this, &MainWindow::end_blue_draw_cards, game, &Game::end_blue_draw_cards);

    connect(this, &MainWindow::signal_red_draw_cards, game, &Game::slot_red_draw_cards);
    connect(game, &Game::begin_red_draw_cards, this, &MainWindow::begin_red_draw_cards);
    connect(this, &MainWindow::end_red_draw_cards, game, &Game::end_red_draw_cards);

    connect(this, &MainWindow::signal_record_load, game, &Game::slot_record_load);
    connect(this, &MainWindow::signal_record_next, game, &Game::slot_record_next);

    connect(this, &MainWindow::signal_record_save, game, &Game::slot_record_save);
    connect(game, &Game::begin_record_save, this, &MainWindow::begin_record_save);

    connect(this, &MainWindow::signal_move_card, game, &Game::slot_move_card);
    connect(game, &Game::begin_move_card, this, &MainWindow::begin_move_card);
    connect(this, &MainWindow::end_move_card, game, &Game::end_move_card);

    connect(this, &MainWindow::signal_effect_card, game, &Game::slot_effect_card);
    connect(game, &Game::begin_effect_card, this, &MainWindow::begin_effect_card);
    connect(this, &MainWindow::end_effect_card, game, &Game::end_effect_card);

    connect(this, &MainWindow::signal_try_card, game, &Game::slot_try_card);
    connect(game, &Game::begin_try_card, this, &MainWindow::begin_try_card);
    connect(this, &MainWindow::end_try_card, game, &Game::end_try_card);

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
    SHOW_DEBUG_INFO;
    emit signal_game_start();
}

void MainWindow::begin_game_start()
{
    SHOW_DEBUG_INFO;
    //animate game_start
    emit end_game_start();
}

void MainWindow::on_game_finish_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_game_finish();
}

void MainWindow::begin_game_finish()
{
    SHOW_DEBUG_INFO;
    //animate game_finish
    emit end_game_finish();
}

void MainWindow::on_shuffle_blue_deck_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_shuffle_blue_deck();
}

void MainWindow::begin_shuffle_blue_deck()
{
    SHOW_DEBUG_INFO;
    //animate shuffle_blue_deck
    emit end_shuffle_blue_deck();
}

void MainWindow::on_shuffle_red_deck_triggered()
{
    SHOW_DEBUG_INFO;
    emit signal_shuffle_red_deck();
}

void MainWindow::begin_shuffle_red_deck()
{
    SHOW_DEBUG_INFO;
    //animate shuffle_red_deck
    emit end_shuffle_red_deck();
}

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
    Label *label = new Label(this);
    connect(label, &Label::select_card, [=](){ emit signal_try_card(card_sn, "blue_hand", 0); });
    label->setText(QString::number(card_sn));
    ui->blue_hand->addWidget(label);
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

void MainWindow::begin_try_card(int card_sn, bool try_summon, bool try_set, bool try_special, bool try_effect)
{
    SHOW_DEBUG_INFO;
    qDebug() << "card_sn" << card_sn << "try_summon" << try_summon << "try_set" << try_set << "try_special" << try_special << "try_effect" << try_effect;
    emit end_try_card(card_sn, try_summon, try_set, try_special, try_effect);
}
