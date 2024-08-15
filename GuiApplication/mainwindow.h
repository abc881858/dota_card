#pragma once

#include <QMainWindow>
#include <QThread>
#include <QHash>
#include "game.h"
#include "label.h"

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
    QHash<int, QLabel*> m_labels;
public slots:
    void begin_game_start();
    void begin_game_finish();
    void begin_shuffle_blue_deck(QList<int> list);
    void begin_shuffle_red_deck();
    void begin_phase_blue_draw();
    void begin_phase_blue_standby();
    void begin_phase_blue_main1();
    void begin_phase_blue_battle();
    void begin_phase_blue_main2();
    void begin_phase_blue_end();
    void begin_phase_red_draw();
    void begin_phase_red_standby();
    void begin_phase_red_main1();
    void begin_phase_red_battle();
    void begin_phase_red_main2();
    void begin_phase_red_end();
    void begin_blue_draw_cards(int size);
    void begin_red_draw_cards(int size);
    void begin_record_save(QStringList list);
    void begin_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index);
    void begin_effect_card(int card_sn, QString from_area, int from_index);
    void begin_try_card(int card_sn, bool try_summon, bool try_set, bool try_special, bool try_effect);
    void begin_summon_card(int card_sn, int to_index);
private slots:
    void on_game_start_triggered();
    void on_game_finish_triggered();
    void on_shuffle_blue_deck_triggered();
    void on_shuffle_red_deck_triggered();
    void on_phase_blue_draw_triggered();
    void on_phase_blue_standby_triggered();
    void on_phase_blue_main1_triggered();
    void on_phase_blue_battle_triggered();
    void on_phase_blue_main2_triggered();
    void on_phase_blue_end_triggered();
    void on_phase_red_draw_triggered();
    void on_phase_red_standby_triggered();
    void on_phase_red_main1_triggered();
    void on_phase_red_battle_triggered();
    void on_phase_red_main2_triggered();
    void on_phase_red_end_triggered();
    void on_blue_draw_one_triggered();
    void on_blue_draw_two_triggered();
    void on_blue_draw_three_triggered();
    void on_blue_draw_four_triggered();
    void on_blue_draw_five_triggered();
    void on_red_draw_one_triggered();
    void on_red_draw_two_triggered();
    void on_red_draw_three_triggered();
    void on_red_draw_four_triggered();
    void on_red_draw_five_triggered();
    void on_record_load_triggered();
    void on_record_next_triggered();
    void on_record_save_triggered();
    void on_move_card_clicked();
    void on_effect_card_clicked();
    void on_try_card_clicked();
    void on_summon_card_clicked();
signals:
    void signal_game_start();
    void end_game_start();
    void signal_game_finish();
    void end_game_finish();
    void signal_shuffle_blue_deck();
    void end_shuffle_blue_deck();
    void signal_shuffle_red_deck();
    void end_shuffle_red_deck();
    void signal_phase_blue_draw();
    void end_phase_blue_draw();
    void signal_phase_blue_standby();
    void end_phase_blue_standby();
    void signal_phase_blue_main1();
    void end_phase_blue_main1();
    void signal_phase_blue_battle();
    void end_phase_blue_battle();
    void signal_phase_blue_main2();
    void end_phase_blue_main2();
    void signal_phase_blue_end();
    void end_phase_blue_end();
    void signal_phase_red_draw();
    void end_phase_red_draw();
    void signal_phase_red_standby();
    void end_phase_red_standby();
    void signal_phase_red_main1();
    void end_phase_red_main1();
    void signal_phase_red_battle();
    void end_phase_red_battle();
    void signal_phase_red_main2();
    void end_phase_red_main2();
    void signal_phase_red_end();
    void end_phase_red_end();
    void signal_blue_draw_cards(int size);
    void end_blue_draw_cards(int size);
    void signal_red_draw_cards(int size);
    void end_red_draw_cards(int size);
    void signal_record_load(QStringList);
    void signal_record_next();
    void end_record_next();
    void signal_record_save();
    void signal_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index);
    void end_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index);
    void signal_effect_card(int card_sn, QString from_area, int from_index);
    void end_effect_card(int card_sn, QString from_area, int from_index);
    void signal_try_card(int card_sn, QString from_area, int from_index);
    void end_try_card(int card_sn, bool try_summon, bool try_set, bool try_special, bool try_effect);
    void signal_summon_card(int card_sn);
    void end_summon_card(int card_sn);
};
