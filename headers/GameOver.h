//
// Created by dawid on 24.11.2019.
//

#ifndef SNAKE_GAMEOVER_H
#define SNAKE_GAMEOVER_H

#include "Snake.h"
#include "Text.h"
#include "GameInterface.h"

class GameOver {

public:

private:
    Text *scoreTV;
    Text *newGameTV;
    Text *quitTV;
    GameInterface *listener;

public:
    GameOver(GameInterface &listener);

    virtual ~GameOver();

public:
    void draw();

    void pollEvents(SDL_Event &event);

    void update(int score);
};


#endif //SNAKE_GAMEOVER_H
