//
// Created by dawid on 24.11.2019.
//

#ifndef SNAKE_GAMEOVER_H
#define SNAKE_GAMEOVER_H

#include "Snake.h"
#include "TextView.h"
#include "NewGameInterface.h"

class GameOver {

public:

private:
    TextView *scoreTV;
    TextView *newGameTV;
    TextView *quitTV;
    NewGameInterface *listener;

public:
    GameOver(NewGameInterface &listener);

    virtual ~GameOver();

public:
    void draw();

    void pollEvents(SDL_Event &event);

    void update(int score);
};


#endif //SNAKE_GAMEOVER_H
