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
add_subdirectory(CreatureModel)
add_subdirectory(Battle)
add_subdirectory("Request-Response")

# Add source to this project's executable.
add_executable (CreatureBattler)
target_sources(CreatureBattler
	PRIVATE
	"CreatureBattler.cpp"
	"CreatureBattler.h"
	"include/rng/RandomManager.cpp")

#add_library(struct_mapping)
#target_sources(struct_mapping
#	PUBLIC
#	"include/struct_mapping/*.h"
#	"include/struct_mapping/options/*.h")

target_link_libraries(CreatureBattler
	PRIVATE
	#struct_mapping
	CreatureModel
	RequestResponseObjects
	Battle)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CreatureBattler PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
