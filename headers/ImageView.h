//
// Created by dawid on 23.11.2019.
//

#ifndef SNAKE_IMAGEVIEW_H
#define SNAKE_IMAGEVIEW_H

#include "View.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <iostream>


using String = std::string;
using std::cerr;


class ImageView : public View {

private:
    SDL_Texture *texture;

public:
    ImageView(int width, int height, const String &imagePath);
    ~ImageView() override;

    void pollEvents(SDL_Event &event) override;

    virtual void draw() override;

    virtual void setImage(const String &imagePath);
};


#endif //SNAKE_IMAGEVIEW_H
