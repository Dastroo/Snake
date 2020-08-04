//
// Created by dawid on 24.11.2019.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <thread>
#include "Window.h"
#include "Map.h"
#include "GameOver.h"
#include "Snake.h"
#include "DirectionChangeListener.h"
#include "NewGameInterface.h"

using std::this_thread::sleep_for;
using Millisec = std::chrono::milliseconds;
using String = std::string;
using std::cout;

class Game : public DirectionChangeListener, public NewGameInterface {

public:

private:
    Window *window;
    GameOver *gameOverScreen = nullptr;
    Map *snakeMap = nullptr;
    Snake snake;

    int** map;
    int snakeSpeed = 20;
    int frameCount = 0;
    int moving;

    bool over = false;

public:
    Game();
    virtual ~Game();

public:
    void launchGame();

private:
    void gameLoop();

    void pollEvents();

    void update();

    void updateSnakePosOnMap();

    void checkTargetFieldType();

    void render();

    void gameOver();

    void onChanged(int input) override;

    void newGame() override;

};


#endif //SNAKE_GAME_H
