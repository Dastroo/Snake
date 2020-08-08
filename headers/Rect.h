//
// Created by dawid on 23.11.2019.
//

#ifndef SNAKE_RECT_H
#define SNAKE_RECT_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include "../headers/Window.h"

class Rect {

public:

protected:
    SDL_Rect rect;

    int width, height;
    int positionX, positionY;

private:
    int r = 255, g = 255, b = 255, transparency = 255;

public:
    Rect(int width, int height);

    Rect(int positionX, int positionY, int width, int height);

    virtual ~Rect();

    virtual void draw();

    int getWidth();

    virtual void setColor(const int color[3]);

    virtual void setTransparency(int transparency);

    virtual void setPosition(int positionX, int positionY);

    virtual void setSize(int width, int height);

    virtual void pollEvents(SDL_Event &event);
};


#endif //SNAKE_RECT_H
