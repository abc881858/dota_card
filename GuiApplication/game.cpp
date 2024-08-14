#include "game.h"
#include <QDebug>

#define SHOW_DEBUG_INFO qDebug() << QString("%1").arg(metaObject()->className()) << __func__

Game::Game(QObject *parent)
    : QObject{parent}
{
}

void Game::slot_game_start()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    //init players

    //init cards
    Card *card1 = new Card;
    card1->id = ++m_sn;
    card1->name = "melee_creep_radiant";//天辉
    card1->description = "【天使族】\\n我一般见谁不顺眼就打谁的";
    card1->level = 3;
    card1->atk = 1300;
    card1->def = 1200;
    card1->attribute = Card::AttributeLight;
    card1->type = Card::TypeWarrior;
    card1->kind = Card::KindNormalMonster;
    card1->area = Card::AreaBlueDeck;
    card1->position = true;
    card1->faceup = false;

    Card *card2 = new Card;
    card2->id = ++m_sn;
    card2->name = "melee_creep_dire";
    card2->description = "【恶魔族】\\n我最大的梦想就是把夜魇的枯树换成天辉的";
    card2->level = 3;
    card2->atk = 1300;
    card2->def = 1200;
    card2->attribute = Card::AttributeDark;
    card2->type = Card::TypeWarrior;
    card2->kind = Card::KindNormalMonster;
    card2->area = Card::AreaBlueDeck;
    card2->position = true;
    card2->faceup = false;

    Card *card3 = new Card;
    card3->id = ++m_sn;
    card3->name = "ranged_creep_radiant";
    card3->description = "【天使族】\\n我们踏过青草与玫瑰，走向血河以北，用呐喊搭建虚构的耀武扬威。我们明白没有凯旋而归，明白死亡总是无声而纯粹。我们拔出刀剑，今夜再不能饮醉，天辉万岁";
    card3->level = 3;
    card3->atk = 1200;
    card3->def = 1300;
    card3->attribute = Card::AttributeLight;
    card3->type = Card::TypeWarrior;
    card3->kind = Card::KindNormalMonster;
    card3->area = Card::AreaBlueDeck;
    card3->position = true;
    card3->faceup = false;

    Card *card4 = new Card;
    card4->id = ++m_sn;
    card4->name = "ranged_creep_dire";
    card4->description = "【恶魔族】\\n英雄之所以为英雄，是因为他们沐浴在圣光中诞生。他们可以拿起武器，穿上盔甲，大杀四方。即便死了，他们也可以在圣泉中重生。而我们只不过是没有灵魂的躯壳罢了";
    card4->level = 3;
    card4->atk = 1200;
    card4->def = 1300;
    card4->attribute = Card::AttributeDark;
    card4->type = Card::TypeWarrior;
    card4->kind = Card::KindNormalMonster;
    card4->area = Card::AreaBlueDeck;
    card4->position = true;
    card4->faceup = false;

    Card *card5 = new Card;
    card5->id = ++m_sn;
    card5->name = "zeus";
    card5->description = "【魔法师族·效果】\\n①当自己场上有其他怪兽时，这张卡可以从手牌特殊召唤。\\n②一回合一次，丢弃一张手牌发动，破坏对方场上一只怪兽\\n③一回合一次，丢弃两张手牌发动，对方场上怪兽守备力降低1000点，怪兽守备力降至0的场合破坏怪兽。若这张卡装备了[阿哈利姆神杖]则改为降低2000点守备力";
    card5->level = 2;
    card5->atk = 500;
    card5->def = 350;
    card5->attribute = Card::AttributeLight;
    card5->type = Card::TypeSpellcaster;
    card5->kind = Card::KindEffectMonster;
    card5->area = Card::AreaBlueDeck;
    card5->position = true;
    card5->faceup = false;

    Card *card6 = new Card;
    card6->id = ++m_sn;
    card6->name = "axe";
    card6->description = "【兽战士族·效果】\\n①对方进入战斗流程时，这张卡可以变为表侧守备表示且守备力上升1500，强制对方所有怪兽变为表侧攻击表示[翻转效果不发动]且必须对这张卡发动攻击。\\n②这张卡受到怪兽攻击时，降低对方500攻·防。\\n③一回合一次，丢弃一张手牌，选择对方场上一只表侧表示的怪兽，若该怪兽守备力大于1000则降低700点防御力，否则破坏此怪兽并抽一张卡，若成功破坏了怪兽，此效果可以再次使用。若装备了[阿哈利姆神杖]则改为大于1500";
    card6->level = 7;
    card6->atk = 1900;
    card6->def = 1400;
    card6->attribute = Card::AttributeEarth;
    card6->type = Card::TypeBeastWarrior;
    card6->kind = Card::KindEffectMonster;
    card6->area = Card::AreaBlueDeck;
    card6->position = true;
    card6->faceup = false;

    Card *card7 = new Card;
    card7->id = ++m_sn;
    card7->name = "ogremagi";
    card7->description = "【兽族·效果】\\n①自己场上没有怪兽而对方场上有怪兽时，这张卡可以从手牌特殊召唤。\\n②一回合一次，指定对方场上一只怪兽攻·守下降700，之后丢三枚硬币，每有一枚为正则额外下降700点攻·守，若因此效果降至0则破坏该怪兽。若这张卡装备了[阿哈利姆神杖]则此效果一回合可以使用两次";
    card7->level = 4;
    card7->atk = 1400;
    card7->def = 2000;
    card7->attribute = Card::AttributeFire;
    card7->type = Card::TypeBeast;
    card7->kind = Card::KindEffectMonster;
    card7->area = Card::AreaBlueDeck;
    card7->position = true;
    card7->faceup = false;

    Card *card8 = new Card;
    card8->id = ++m_sn;
    card8->name = "meepo";
    card8->description = "【兽族·效果】\\n①把自己1张手牌送去墓地才能发动。从手牌·卡组把1只[米波]特殊召唤。[米波]从场上离开的场合这张卡破坏";
    card8->level = 3;
    card8->atk = 1300;
    card8->def = 1300;
    card8->attribute = Card::AttributeEarth;
    card8->type = Card::TypeBeast;
    card8->kind = Card::KindEffectMonster;
    card8->area = Card::AreaBlueDeck;
    card8->position = true;
    card8->faceup = false;

    Card *card9 = new Card;
    card9->id = ++m_sn;
    card9->name = "melee_creep_radiant";//天辉
    card9->description = "【天使族】\\n我一般见谁不顺眼就打谁的";
    card9->level = 3;
    card9->atk = 1300;
    card9->def = 1200;
    card9->attribute = Card::AttributeLight;
    card9->type = Card::TypeWarrior;
    card9->kind = Card::KindNormalMonster;
    card9->area = Card::AreaBlueDeck;
    card9->position = true;
    card9->faceup = false;

    Card *card10 = new Card;
    card10->id = ++m_sn;
    card10->name = "melee_creep_dire";
    card10->description = "【恶魔族】\\n我最大的梦想就是把夜魇的枯树换成天辉的";
    card10->level = 3;
    card10->atk = 1300;
    card10->def = 1200;
    card10->attribute = Card::AttributeDark;
    card10->type = Card::TypeWarrior;
    card10->kind = Card::KindNormalMonster;
    card10->area = Card::AreaBlueDeck;
    card10->position = true;
    card10->faceup = false;

    Card *card11 = new Card;
    card11->id = ++m_sn;
    card11->name = "ranged_creep_radiant";
    card11->description = "【天使族】\\n我们踏过青草与玫瑰，走向血河以北，用呐喊搭建虚构的耀武扬威。我们明白没有凯旋而归，明白死亡总是无声而纯粹。我们拔出刀剑，今夜再不能饮醉，天辉万岁";
    card11->level = 3;
    card11->atk = 1200;
    card11->def = 1300;
    card11->attribute = Card::AttributeLight;
    card11->type = Card::TypeWarrior;
    card11->kind = Card::KindNormalMonster;
    card11->area = Card::AreaBlueDeck;
    card11->position = true;
    card11->faceup = false;

    Card *card12 = new Card;
    card12->id = ++m_sn;
    card12->name = "ranged_creep_dire";
    card12->description = "【恶魔族】\\n英雄之所以为英雄，是因为他们沐浴在圣光中诞生。他们可以拿起武器，穿上盔甲，大杀四方。即便死了，他们也可以在圣泉中重生。而我们只不过是没有灵魂的躯壳罢了";
    card12->level = 3;
    card12->atk = 1200;
    card12->def = 1300;
    card12->attribute = Card::AttributeDark;
    card12->type = Card::TypeWarrior;
    card12->kind = Card::KindNormalMonster;
    card12->area = Card::AreaBlueDeck;
    card12->position = true;
    card12->faceup = false;

    Card *card13 = new Card;
    card13->id = ++m_sn;
    card13->name = "zeus";
    card13->description = "【魔法师族·效果】\\n①当自己场上有其他怪兽时，这张卡可以从手牌特殊召唤。\\n②一回合一次，丢弃一张手牌发动，破坏对方场上一只怪兽\\n③一回合一次，丢弃两张手牌发动，对方场上怪兽守备力降低1000点，怪兽守备力降至0的场合破坏怪兽。若这张卡装备了[阿哈利姆神杖]则改为降低2000点守备力";
    card13->level = 2;
    card13->atk = 500;
    card13->def = 350;
    card13->attribute = Card::AttributeLight;
    card13->type = Card::TypeSpellcaster;
    card13->kind = Card::KindEffectMonster;
    card13->area = Card::AreaBlueDeck;
    card13->position = true;
    card13->faceup = false;

    Card *card14 = new Card;
    card14->id = ++m_sn;
    card14->name = "axe";
    card14->description = "【兽战士族·效果】\\n①对方进入战斗流程时，这张卡可以变为表侧守备表示且守备力上升1500，强制对方所有怪兽变为表侧攻击表示[翻转效果不发动]且必须对这张卡发动攻击。\\n②这张卡受到怪兽攻击时，降低对方500攻·防。\\n③一回合一次，丢弃一张手牌，选择对方场上一只表侧表示的怪兽，若该怪兽守备力大于1000则降低700点防御力，否则破坏此怪兽并抽一张卡，若成功破坏了怪兽，此效果可以再次使用。若装备了[阿哈利姆神杖]则改为大于1500";
    card14->level = 7;
    card14->atk = 1900;
    card14->def = 1400;
    card14->attribute = Card::AttributeEarth;
    card14->type = Card::TypeBeastWarrior;
    card14->kind = Card::KindEffectMonster;
    card14->area = Card::AreaBlueDeck;
    card14->position = true;
    card14->faceup = false;

    Card *card15 = new Card;
    card15->id = ++m_sn;
    card15->name = "ogremagi";
    card15->description = "【兽族·效果】\\n①自己场上没有怪兽而对方场上有怪兽时，这张卡可以从手牌特殊召唤。\\n②一回合一次，指定对方场上一只怪兽攻·守下降700，之后丢三枚硬币，每有一枚为正则额外下降700点攻·守，若因此效果降至0则破坏该怪兽。若这张卡装备了[阿哈利姆神杖]则此效果一回合可以使用两次";
    card15->level = 4;
    card15->atk = 1400;
    card15->def = 2000;
    card15->attribute = Card::AttributeFire;
    card15->type = Card::TypeBeast;
    card15->kind = Card::KindEffectMonster;
    card15->area = Card::AreaBlueDeck;
    card15->position = true;
    card15->faceup = false;

    Card *card16 = new Card;
    card16->id = ++m_sn;
    card16->name = "meepo";
    card16->description = "【兽族·效果】\\n①把自己1张手牌送去墓地才能发动。从手牌·卡组把1只[米波]特殊召唤。[米波]从场上离开的场合这张卡破坏";
    card16->level = 3;
    card16->atk = 1300;
    card16->def = 1300;
    card16->attribute = Card::AttributeEarth;
    card16->type = Card::TypeBeast;
    card16->kind = Card::KindEffectMonster;
    card16->area = Card::AreaBlueDeck;
    card16->position = true;
    card16->faceup = false;

    //init board
    blue_deck << card1 << card2 << card3 << card4 << card5 << card6 << card7 << card8;
    red_deck << card9 << card10 << card11 << card12 << card13 << card14 << card15 << card16;

    //猜先
    //init rule
    emit begin_game_start();
}

void Game::end_game_start()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_game_finish()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    //deinit players
    //deinit cards
    //deinit board
    //deinit rule
    //deinit phase
    emit begin_game_finish();
}

void Game::end_game_finish()
{
    SHOW_DEBUG_INFO;
    if (m_is_recording) { m_is_recording = false; }
}

void Game::slot_shuffle_blue_deck()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    //do shuffle blue deck
    emit begin_shuffle_blue_deck();
}

void Game::end_shuffle_blue_deck()
{
    SHOW_DEBUG_INFO;
    if(m_is_recording) { slot_record_next(); }
}

void Game::slot_shuffle_red_deck()
{
    SHOW_DEBUG_INFO;
    if(!m_is_recording) { m_record << QString("%1\n").arg(__func__); }

    //do shuffle red deck
    emit begin_shuffle_red_deck();
}

void Game::end_shuffle_red_deck()
{
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
    if(slot == "slot_move_card")
    {
        int card_sn = QString(record_line_list.at(1)).toInt();
        QString from_area = record_line_list.at(2);
        int from_index = QString(record_line_list.at(3)).toInt();
        QString to_area = record_line_list.at(4);
        int to_index = QString(record_line_list.at(5)).toInt();
        slot_move_card(card_sn, from_area, from_index, to_area, to_index);
    }
    else if(slot == "slot_effect_card")
    {
        int card_sn = QString(record_line_list.at(1)).toInt();
        QString from_area = record_line_list.at(2);
        int from_index = QString(record_line_list.at(3)).toInt();
        slot_effect_card(card_sn, from_area, from_index);
    }
    else if(slot == "slot_try_card")
    {
        int card_sn = QString(record_line_list.at(1)).toInt();
        QString from_area = record_line_list.at(2);
        int from_index = QString(record_line_list.at(3)).toInt();
        slot_try_card(card_sn, from_area, from_index);
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
}
