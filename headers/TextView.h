//
// Created by dawid on 23.11.2019.
//

#ifndef SNAKE_TEXTVIEW_H
#define SNAKE_TEXTVIEW_H


#include "View.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>


using String = std::string;
using std::cerr;


class TextView : public View {

private:
    String text = "TextView";
    String fontPath = "res/Ubuntu-M.ttf";
    int fontSize = 24;
    SDL_Color color = {255, 255, 255, 255};

    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = nullptr;
    TTF_Font *font = nullptr;


public:
    TextView();

    explicit TextView(String text);

    virtual ~TextView() override;

    void draw() override;

    String getText();

    void setText(String text);

    void setFontPath(String fontPath);

    void setFontSize(int fontSize);

    void setTextColor(SDL_Color color);

private:
    void createNewTexture();
};


#endif //SNAKE_TEXTVIEW_H
