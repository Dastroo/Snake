//
// Created by dawid on 24.11.2019.
//

#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H


#include "View.h"
#include "Field.h"
#include "Snake.h"

class Map {

public:

private:
    Field *map[3600];


public:
    Map();

    virtual ~Map();

public:
    void updateMap(int *array, int FLAG);

    void updateMap(int i, int FLAG);

    Field *getMapOn(int fieldId);

    void generateNewApple();

    int random(int min, int max);

    void draw();

private:

};


#endif //SNAKE_MAP_H
