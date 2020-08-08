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
#include "GameInterface.h"

using std::this_thread::sleep_for;
using Millisec = std::chrono::milliseconds;
using String = std::string;
using std::cout;

//  TODO: add audio
//  TODO: optimize by creating the board on the fly instead of all at once
class Game : public DirectionChangeListener, public GameInterface {

public:

private:
    Window *window;
    GameOver *gameOverScreen = nullptr;
    Map *snakeMap = nullptr;
    Snake *snake;

    int** map;
    int snakeSpeed = 40;
    int frameCount = 0;

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

    void quitGame() override;
};


#endif //SNAKE_GAME_H
