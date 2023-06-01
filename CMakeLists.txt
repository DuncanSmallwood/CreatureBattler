# CMakeList.txt : CMake project for CreatureBattler, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CreatureBattler")

# Add source to this project's executable.
add_executable (CreatureBattler "CreatureBattler.cpp" "CreatureBattler.h" "CreatureModel/Creature.cpp" "CreatureModel/Enum/CreatureTypeEnum.cpp" "CreatureModel/Move.h" "CreatureModel/Enum/MoveTypeEnum.cpp" "CreatureModel/Move.cpp" "Battle/Turn.h" "Battle/Turn.cpp" "include/rng/RandomManager.cpp" "Battle/CombatMoment.h" "Battle/CombatMoment.cpp" "Battle/Battle.h" "Battle/Battle.cpp")

# target_link_libraries(struct_mapping PUBLIC)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CreatureBattler PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
