add_library(CreatureModel)

target_sources(CreatureModel
    PRIVATE
    Creature.cpp
    Move.cpp

    PUBLIC
    FILE_SET HEADERS
    FILES
        Creature.h
        Move.h)

target_sources(CreatureModel
    PUBLIC
    FILE_SET creatureEnums
    TYPE HEADERS
    FILES
        Enum/CreatureStatEnum.h
        Enum/CreatureTypeEnum.h
        Enum/MoveTypeEnum.h)
