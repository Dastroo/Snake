cmake_minimum_required(VERSION 3.13.4)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -ISDL")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(Snake source/main.cpp source/Rect.cpp headers/Rect.h source/Window.cpp headers/Window.h source/Image.cpp headers/Image.h source/Text.cpp headers/Text.h source/Game.cpp headers/Game.h source/Map.cpp headers/Map.h source/GameOver.cpp headers/GameOver.h source/Field.cpp headers/Field.h source/Snake.cpp headers/Snake.h headers/DirectionChangeListener.h headers/GameInterface.h)

target_link_libraries(Snake SDL2main SDL2 SDL2_image SDL2_ttf)