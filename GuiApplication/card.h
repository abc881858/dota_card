#pragma once

#include <QObject>

class Card : public QObject
{
    Q_OBJECT
public:
    explicit Card(QObject *parent = nullptr);
    enum Attribute {
        AttributeNo,
        AttributeEarth,//地
        AttributeWater,//水
        AttributeFire,//火
        AttributeWind,//风
        AttributeLight,//光
        AttributeDark//暗
    };
    Q_ENUM(Attribute)

    //Dragon（龙族）、Spellcaster（魔法使族）、Zombie（不死族）、Warrior（战士族）、
    //BeastWarrior（兽战士族）、Beast（兽族）、WingedBeast（鸟兽族）、Fiend（恶魔族）、
    //Fairy（天使族）、Insect（昆虫族）、Dinosaur（恐龙族）、Reptile（爬虫族）、Fish（鱼族）、
    //SeaSerpent（海龙族）、Machine（机械族）、Thunder（雷族）、Aqua（水族）、Pyro（炎族）、
    //Rock（岩石族）、Plant（植物族）
    enum Type
    {
        TypeNo,
        TypeDragon,
        TypeSpellcaster,
        TypeZombie,
        TypeWarrior,
        TypeBeastWarrior,
        TypeBeast,
        TypeWingedBeast,
        TypeFiend,
        TypeFairy,
        TypeInsect,
        TypeDinosaur,
        TypeReptile,
        TypeFish,
        TypeSeaSerpent,
        TypeMachine,
        TypeThunder,
        TypeAqua,
        TypePyro,
        TypeRock,
        TypePlant
    };
    Q_ENUM(Type)

    enum Kind
    {
        KindNo,
        KindNormalMonster,
        KindEffectMonster,
        KindNormalSpell,
        KindContinuousSpell,
        KindEquipSpell,
        KindQuicklyplaySpell,
        KindFieldSpell,
        KindNormalTrap,
        KindContinuousTrap,
        KindCounterTrap
    };
    Q_ENUM(Kind)

    enum Area
    {
        AreaNo,
        AreaBlueDeck,
        AreaBlueHand,
        AreaBlueFront1,
        AreaBlueFront2,
        AreaBlueFront3,
        AreaBlueFront4,
        AreaBlueFront5,
        AreaBlueBack1,
        AreaBlueBack2,
        AreaBlueBack3,
        AreaBlueBack4,
        AreaBlueBack5,
        AreaBlueGrave,
        AreaRedDeck,
        AreaRedHand,
        AreaRedFront1,
        AreaRedFront2,
        AreaRedFront3,
        AreaRedFront4,
        AreaRedFront5,
        AreaRedBack1,
        AreaRedBack2,
        AreaRedBack3,
        AreaRedBack4,
        AreaRedBack5,
        AreaRedGrave
    };
    Q_ENUM(Area)

    int id;
    QString name;
    QString description;
    int level;
    int atk;
    int def;
    Attribute attribute;
    Type type;
    Kind kind;
    Area area;
    bool position;//攻击 防守
    bool faceup;//表侧 里侧
};
