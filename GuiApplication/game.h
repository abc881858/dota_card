#pragma once

#include "card.h"
#include <QMap>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    enum Phase {
        PhaseBlueDraw,
        PhaseBlueStandby,
        PhaseBlueMain1,
        PhaseBlueBattle,
        PhaseBlueMain2,
        PhaseBlueEnd,
        PhaseRedDraw,
        PhaseRedStandby,
        PhaseRedMain1,
        PhaseRedBattle,
        PhaseRedMain2,
        PhaseRedEnd
    };
    Q_ENUM(Phase)
    int check_blue_front();
    int check_blue_back();
    int check_red_front();
    int check_red_back();
private:
    QMap<int, Card*> m_cards;
    QList<Card*> blue_hand;
    QList<Card*> red_hand;
    QList<Card*> blue_deck;
    QList<Card*> red_deck;
    QList<Card*> blue_grave;
    QList<Card*> red_grave;
    QList<Card*> blue_remove;
    QList<Card*> red_remove;
    Card* blue_front_1{nullptr};
    Card* blue_front_2{nullptr};
    Card* blue_front_3{nullptr};
    Card* blue_front_4{nullptr};
    Card* blue_front_5{nullptr};
    Card* blue_back_1{nullptr};
    Card* blue_back_2{nullptr};
    Card* blue_back_3{nullptr};
    Card* blue_back_4{nullptr};
    Card* blue_back_5{nullptr};
    Card* red_front_1{nullptr};
    Card* red_front_2{nullptr};
    Card* red_front_3{nullptr};
    Card* red_front_4{nullptr};
    Card* red_front_5{nullptr};
    Card* red_back_1{nullptr};
    Card* red_back_2{nullptr};
    Card* red_back_3{nullptr};
    Card* red_back_4{nullptr};
    Card* red_back_5{nullptr};
    int m_sn{100};
    Phase m_phase;
    int m_need_blue_draw{0};
    int m_need_red_draw{0};
    QStringList m_record;
    bool m_is_recording{false};
    bool m_enable_normal_summon{false};
public slots:
    void slot_game_start();
    void end_game_start();
    void slot_game_finish();
    void end_game_finish();
    void slot_shuffle_blue_deck();
    void end_shuffle_blue_deck();
    void slot_shuffle_red_deck();
    void end_shuffle_red_deck();
    void slot_phase_blue_draw();
    void end_phase_blue_draw();
    void slot_phase_blue_standby();
    void end_phase_blue_standby();
    void slot_phase_blue_main1();
    void end_phase_blue_main1();
    void slot_phase_blue_battle();
    void end_phase_blue_battle();
    void slot_phase_blue_main2();
    void end_phase_blue_main2();
    void slot_phase_blue_end();
    void end_phase_blue_end();
    void slot_phase_red_draw();
    void end_phase_red_draw();
    void slot_phase_red_standby();
    void end_phase_red_standby();
    void slot_phase_red_main1();
    void end_phase_red_main1();
    void slot_phase_red_battle();
    void end_phase_red_battle();
    void slot_phase_red_main2();
    void end_phase_red_main2();
    void slot_phase_red_end();
    void end_phase_red_end();
    void slot_blue_draw_cards(int size);
    void end_blue_draw_cards(int size);
    void slot_red_draw_cards(int size);
    void end_red_draw_cards(int size);
    void slot_record_load(QStringList list);
    void slot_record_next();
    void slot_record_save();
    void slot_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index);
    void end_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index);
    void slot_effect_card(int card_sn, QString from_area, int from_index);
    void end_effect_card(int card_sn, QString from_area, int from_index);
    void slot_try_card(int card_sn, QString from_area, int from_index);
    void end_try_card(int card_sn, bool try_summon, bool try_set, bool try_special, bool try_effect);
signals:
    void begin_game_start();
    void begin_game_finish();
    void begin_shuffle_blue_deck();
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
};
