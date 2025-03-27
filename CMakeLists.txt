cmake_minimum_required(VERSION 3.30)
project(Fwamework)

set(CMAKE_CXX_STANDARD 20)

set (TERMINALUTILS_PATH /usr/local/lib/cpp/terminalUtilities)
include_directories(${TERMINALUTILS_PATH}/include)
find_library(TERMINALUTILS NAMES TerminalUtilities PATHS ${TERMINALUTILS_PATH}/src)

if (NOT TERMINALUTILS)
    MESSAGE(FATAL_ERROR "TerminalUtilities not found!")
endif ()

add_library(Fwamework STATIC
src/Asset.cpp
src/GameState.cpp
src/InputHandlerAsync.cpp
src/Scene.cpp
src/SceneLoader.cpp
src/ScreenRenderer.cpp)

link_libraries(Fwamework PRIVATE ${TERMINALUTILS})

target_include_directories(Fwamework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS Fwamework
        DESTINATION /usr/local/lib/cpp/fwamework/src)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION /usr/local/lib/cpp/fwamework/include)
