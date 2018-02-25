add_library(
    PureEngine
    Conversions.cpp
    CreateVertSquare.cpp
    Entity.cpp
    FlattenStrings.cpp
    Game.cpp
    GetConsoleInput.cpp
    Player.cpp
    Random.cpp
    SplitString.cpp
    State.cpp
    StateManager.cpp
    StringToCase.cpp
    ToString.cpp
)

target_link_libraries(PureEngine ${SFML_LIBRARIES})

install(TARGETS PureEngine DESTINATION "${CMAKE_SOURCE_DIR}/lib")

configure_file(pureengine-config.cmake.in "${PROJECT_BINARY_DIR}/pureengine-config.cmake")

# install(TARGETS sqrt DESTINATION lib/)
# install(FILES sqrt.h DESTINATION include/)

install(TARGETS PureEngine DESTINATION lib/)
install(
    FILES
    Constants.h
    Conversions.h
    CreateVertSquare.h
    DebugLog.h
    declspec.h
    Entity.h
    FlattenStrings.h
    Game.h
    GetConsoleInput.h
    ParallelFor.h
    Player.h
    Printable.h
    Random.h
    ResourceHolder.h
    ResourceManager.h
    SplitString.h
    State.h
    StateManager.h
    stdafx.h
    StringToCase.h
    ToString.h
    ToUnderlying.h
    VectorMath.h
    VecToString.h
    DESTINATION include/
)
install(FILES "${PROJECT_BINARY_DIR}/pureengine-config.cmake" DESTINATION lib/cmake/${PROJECT_NAME})