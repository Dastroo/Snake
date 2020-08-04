//
// Created by dawid on 01.12.2019.
//

#ifndef SNAKE_DIRECTIONCHANGELISTENER_H
#define SNAKE_DIRECTIONCHANGELISTENER_H

class DirectionChangeListener {

public:
    virtual void onChanged(int direction) = 0;
};

#endif //SNAKE_DIRECTIONCHANGELISTENER_H
