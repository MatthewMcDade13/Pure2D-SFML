# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CmakeModules" ${CMAKE_MODULE_PATH})

# find_package(SFML 2 COMPONENTS system window graphics REQUIRED)
# include_directories(${SFML_INCLUDE_DIR})
# add_library()(
#     PureEngineLib
#     Conversions.cpp
#     CreateVertSquare.cpp
#     Entity.cpp
#     FlattenStrings.cpp
#     Game.cpp
#     GetConsoleInput.cpp
#     Player.cpp
#     Random.cpp
#     SplitString.cpp
#     State.cpp
#     StateManager.cpp
#     StringToCase.cpp
#     ToString.cpp
# )
# target_link_libraries(PureEngineLib ${SFML_LIBRARIES})

# install(TARGETS PureEngineLib DESTINATION "${CMAKE_SOURCE_DIR}/build")

cmake_minimum_required(VERSION 2.8)
project(PureEngine)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CmakeModules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_subdirectory(PureEngine)
