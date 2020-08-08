//
// Created by dawid on 26.11.2019.
//

#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H

#include "Rect.h"

class Field : public Rect {

public:
    static const int EMPTY = 0;
    static const int SNAKE = 1;
    static const int APPLE = 2;
    static const int WALL = 3;

private:
    int id;
    int type = EMPTY;


public:
    Field(int fieldSize, int id);
    ~Field() override;

    void setFieldTo(int FLAG);

    int getId();
    int getType();
};

#endif //SNAKE_FIELD_H
