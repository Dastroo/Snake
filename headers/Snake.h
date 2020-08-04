//
// Created by dawid on 26.11.2019.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <iostream>
#include "DirectionChangeListener.h"
#include <SDL2/SDL_events.h>


using std::cout;

class Snake {

public:
    static const int UP = 0;
    static const int DOWN = 1;
    static const int LEFT = 2;
    static const int RIGHT = 3;

private:
    DirectionChangeListener *listener = nullptr;

    int headX;
    int headY;

    int movingDirection = DOWN;
    int direction = DOWN;

    int head;
    int tail;
    int size;

    int *snake;
    int **map;

public:
    Snake();

    virtual ~Snake();

    int getHead();

    int getSnake(int snakePart);

    int getTail();

    void attachToMap(int **map);

    void grow();

    void move();

    void updatePosition();

    int getSize();

    void pollEvents(SDL_Event &event);

    void updateDirection(int direction);

    void reset();

    void setListener(DirectionChangeListener &listener);

};


#endif //SNAKE_SNAKE_H
