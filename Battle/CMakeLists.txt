add_library(Battle)

target_sources(Battle
    PRIVATE
    Battle.cpp
    BattleBuilder.cpp
    CombatMoment.cpp
    Turn.cpp

    PUBLIC
    FILE_SET HEADERS
    FILES
        Battle.h
        BattleBuilder.h
        CombatMoment.h
        Turn.h)
