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
    //init phase
    emit begin_start_game();
}

void Game::end_start_game()
{
    SHOW_DEBUG_INFO
    //change phase
    //do shuffle_blue_deck
    // emit begin_shuffle_blue_deck();
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
    SHOW_DEBUG_INFO
    //over
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
    //do shuffle_red_deck
    // emit begin_shuffle_red_deck();
}

void Game::slot_shuffle_red_deck()
{
    SHOW_DEBUG_INFO
    //do shuffle red deck
    emit begin_shuffle_red_deck();
}

void Game::end_shuffle_red_deck()
{
    SHOW_DEBUG_INFO
    //change phase
    //do draw_blue
    // emit begin_draw_blue();
}
