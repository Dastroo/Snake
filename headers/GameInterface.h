//
// Created by dawid on 01.12.2019.
//

#ifndef SNAKE_GAMEINTERFACE_H
#define SNAKE_GAMEINTERFACE_H

class GameInterface {

public:
    virtual void newGame() = 0;

    virtual void quitGame() = 0;
};


#endif //SNAKE_GAMEINTERFACE_H
