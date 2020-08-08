//
// Created by dawid on 23.11.2019.
//

#ifndef SNAKE_TEXT_H
#define SNAKE_TEXT_H


#include "Rect.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>


using String = std::string;
using std::cerr;


class Text : public Rect {

private:
    String text = "Text";
    String fontPath = "res/Ubuntu-M.ttf";
    int fontSize = 24;
    SDL_Color color = {255, 255, 255, 255};

    SDL_Texture *texture = nullptr;
    SDL_Surface *surface = nullptr;
    TTF_Font *font = nullptr;


public:
    Text();

    explicit Text(String text);

    virtual ~Text() override;

    void draw() override;

    String getText();

    void setText(String text);

    void setFontPath(String fontPath);

    void setFontSize(int fontSize);

    void setTextColor(SDL_Color color);

private:
    void createNewTexture();
};


#endif //SNAKE_TEXT_H
