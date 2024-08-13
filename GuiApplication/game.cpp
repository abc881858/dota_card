#include "game.h"
#include <QDebug>

#define SHOW_DEBUG_INFO qDebug() << QString("%1").arg(metaObject()->className()) << __func__;

Game::Game(QObject *parent)
    : QObject{parent}
{
}

void Game::slot_start_game()
{
    SHOW_DEBUG_INFO
    //init players
    //init cards
    //init board
    //init rule    
    emit begin_start_game();
}

void Game::end_start_game()
{
    SHOW_DEBUG_INFO
    //change phase
    m_phase = DrawBlue;
    qDebug() << "change phase to" << m_phase;
    // slot_shuffle_blue_deck();
}

void Game::slot_finish_game()
{
    SHOW_DEBUG_INFO
    //deinit players
    //deinit cards
    //deinit board
    //deinit rule
    //deinit phase
    emit begin_finish_game();
}

void Game::end_finish_game()
{
<<<<<<< HEAD
    SHOW_DEBUG_INFO
    //over
=======
    SHOW_DEBUG_INFO;
    if (m_is_recording) { m_is_recording = false; }
>>>>>>> 16bc7a1 (fix game_finish bug && record_next bug)
}

void Game::slot_shuffle_blue_deck()
{
    SHOW_DEBUG_INFO
    //do shuffle blue deck
    emit begin_shuffle_blue_deck();
}

void Game::end_shuffle_blue_deck()
{
    SHOW_DEBUG_INFO
    //change phase
    // slot_shuffle_red_deck();
}

void Game::slot_shuffle_red_deck()
{
    SHOW_DEBUG_INFO
    //do shuffle red deck
    emit begin_shuffle_red_deck();
}

void Game::end_shuffle_red_deck()
{
<<<<<<< HEAD
    SHOW_DEBUG_INFO
    //change phase
    //do draw_blue
    // emit begin_draw_blue();
=======
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_blue_draw()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseBlueDraw;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_blue_draw();
}

void Game::end_phase_blue_draw()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_blue_standby()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseBlueStandby;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_blue_standby();
}

void Game::end_phase_blue_standby()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_blue_main1()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseBlueMain1;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_blue_main1();
}

void Game::end_phase_blue_main1()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_blue_battle()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseBlueBattle;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_blue_battle();
}

void Game::end_phase_blue_battle()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_blue_main2()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseBlueMain2;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_blue_main2();
}

void Game::end_phase_blue_main2()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_blue_end()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseBlueEnd;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_blue_end();
}

void Game::end_phase_blue_end()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_red_draw()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseRedDraw;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_red_draw();
}

void Game::end_phase_red_draw()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_red_standby()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseRedStandby;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_red_standby();
}

void Game::end_phase_red_standby()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_red_main1()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseRedMain1;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_red_main1();
}

void Game::end_phase_red_main1()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_red_battle()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseRedBattle;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_red_battle();
}

void Game::end_phase_red_battle()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_red_main2()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseRedMain2;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_red_main2();
}

void Game::end_phase_red_main2()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_phase_red_end()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    m_phase = PhaseRedEnd;
    qDebug() << "change phase to" << m_phase;
    emit begin_phase_red_end();
}

void Game::end_phase_red_end()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

int Game::check_blue_front()
{
    if(blue_front_1 == nullptr)
    {
        return 1;
    }
    else if(blue_front_2 == nullptr)
    {
        return 2;
    }
    else if(blue_front_3 == nullptr)
    {
        return 3;
    }
    else if(blue_front_4 == nullptr)
    {
        return 4;
    }
    else if(blue_front_5 == nullptr)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

int Game::check_blue_back()
{
    if(blue_back_1 == nullptr)
    {
        return 1;
    }
    else if(blue_back_2 == nullptr)
    {
        return 2;
    }
    else if(blue_back_3 == nullptr)
    {
        return 3;
    }
    else if(blue_back_4 == nullptr)
    {
        return 4;
    }
    else if(blue_back_5 == nullptr)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

int Game::check_red_front()
{
    if(red_front_1 == nullptr)
    {
        return 1;
    }
    else if(red_front_2 == nullptr)
    {
        return 2;
    }
    else if(red_front_3 == nullptr)
    {
        return 3;
    }
    else if(red_front_4 == nullptr)
    {
        return 4;
    }
    else if(red_front_5 == nullptr)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

int Game::check_red_back()
{
    if(red_back_1 == nullptr)
    {
        return 1;
    }
    else if(red_back_2 == nullptr)
    {
        return 2;
    }
    else if(red_back_3 == nullptr)
    {
        return 3;
    }
    else if(red_back_4 == nullptr)
    {
        return 4;
    }
    else if(red_back_5 == nullptr)
    {
        return 5;
    }
    else
    {
        return 0;
    }
}

void Game::slot_blue_draw_cards(int size)
{
    SHOW_DEBUG_INFO;
    m_need_blue_draw = size;
    qDebug() << "need blue draw cards" << m_need_blue_draw;
    emit begin_blue_draw_cards(size);
}

void Game::end_blue_draw_cards(int size)
{
    Q_UNUSED(size)
    SHOW_DEBUG_INFO;
}

void Game::slot_red_draw_cards(int size)
{
    SHOW_DEBUG_INFO;
    m_need_red_draw = size;
    qDebug() << "need red draw cards" << m_need_red_draw;
    emit begin_red_draw_cards(size);
}

void Game::end_red_draw_cards(int size)
{
    Q_UNUSED(size)
    SHOW_DEBUG_INFO;
}

void Game::slot_record_save()
{
    SHOW_DEBUG_INFO;
    emit begin_record_save(m_record);
}

void Game::slot_record_load(QStringList list)
{
    SHOW_DEBUG_INFO;
    m_record = list;
    m_is_recording = true;

    slot_record_next();
}

void Game::slot_record_next()
{
    QString record_line = m_record.takeFirst();
    QStringList record_line_list = record_line.split(',');
    QString slot = record_line_list.first();
    qDebug() << slot;
    if(slot == "slot_move_card")
    {
        int card_sn = QString(record_line_list.at(1)).toInt();
        QString from_area = record_line_list.at(2);
        int from_index = QString(record_line_list.at(3)).toInt();
        QString to_area = record_line_list.at(4);
        int to_index = QString(record_line_list.at(5)).toInt();
        QMetaObject::invokeMethod(this, "slot_move_card", Q_ARG(int, card_sn), Q_ARG(QString, from_area), Q_ARG(int, from_index), Q_ARG(QString, to_area), Q_ARG(int, to_index));
    }
    else if(slot == "slot_effect_card")
    {
        int card_sn = QString(record_line_list.at(1)).toInt();
        QString from_area = record_line_list.at(2);
        int from_index = QString(record_line_list.at(3)).toInt();
        QMetaObject::invokeMethod(this, "slot_effect_card", Q_ARG(int, card_sn), Q_ARG(QString, from_area), Q_ARG(int, from_index));
    }
    else if(slot == "slot_try_card")
    {
        int card_sn = QString(record_line_list.at(1)).toInt();
        QString from_area = record_line_list.at(2);
        int from_index = QString(record_line_list.at(3)).toInt();
        QMetaObject::invokeMethod(this, "slot_try_card", Q_ARG(int, card_sn), Q_ARG(QString, from_area), Q_ARG(int, from_index));
    }
    else
    {
        QMetaObject::invokeMethod(this, slot.toUtf8().data());
    }
}

void Game::slot_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index)
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1,%2,%3,%4,%5,%6\n").arg(__func__).arg(card_sn).arg(from_area).arg(from_index).arg(to_area).arg(to_index); }

    qDebug() << card_sn << from_area << from_index << to_area << to_index;
    emit begin_move_card(card_sn, from_area, from_index, to_area, to_index);
}

void Game::end_move_card(int card_sn, QString from_area, int from_index, QString to_area, int to_index)
{
    Q_UNUSED(card_sn)
    Q_UNUSED(from_area)
    Q_UNUSED(from_index)
    Q_UNUSED(to_area)
    Q_UNUSED(to_index)
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_effect_card(int card_sn, QString from_area, int from_index)
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1,%2,%3,%4\n").arg(__func__).arg(card_sn).arg(from_area).arg(from_index); }

    qDebug() << card_sn << from_area << from_index;
    emit begin_effect_card(card_sn, from_area, from_index);
}

void Game::end_effect_card(int card_sn, QString from_area, int from_index)
{
    Q_UNUSED(card_sn)
    Q_UNUSED(from_area)
    Q_UNUSED(from_index)
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_try_card(int card_sn, QString from_area, int from_index)
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1,%2,%3,%4\n").arg(__func__).arg(card_sn).arg(from_area).arg(from_index); }

    qDebug() << card_sn << from_area << from_index;
    emit begin_try_card(card_sn, from_area, from_index);
}

void Game::end_try_card(int card_sn, QString from_area, int from_index)
{
    Q_UNUSED(card_sn)
    Q_UNUSED(from_area)
    Q_UNUSED(from_index)
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
>>>>>>> 16bc7a1 (fix game_finish bug && record_next bug)
}
