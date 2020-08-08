//
// Created by dawid on 23.11.2019.
//

#ifndef SNAKE_IMAGE_H
#define SNAKE_IMAGE_H

#include "Rect.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <iostream>


using String = std::string;
using std::cerr;


class Image : public Rect {

private:
    SDL_Texture *texture = nullptr;

public:
    Image(int width, int height, const String &imagePath);
    Image(int width, int height);
    ~Image() override;

    void pollEvents(SDL_Event &event) override;

    virtual void draw() override;

    virtual void setImage(const String &imagePath);
};


#endif //SNAKE_IMAGE_H
