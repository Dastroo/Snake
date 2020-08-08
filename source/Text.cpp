//
// Created by dawid on 23.11.2019.
//

#include "../headers/Text.h"


Text::Text()
        : Rect(0, 0) {
    createNewTexture();
}

Text::Text(String text)
        : Rect(0, 0), text(text) {

    createNewTexture();
}

Text::~Text() {
    SDL_DestroyTexture(texture);
}

String Text::getText() {
    return text;
}

void Text::setText(String text) {
    this->text = text;

    createNewTexture();
}

void Text::setTextColor(SDL_Color color) {
    this->color = color;

    createNewTexture();
}

void Text::setFontSize(int fontSize) {
    this->fontSize = fontSize;

    createNewTexture();
}

void Text::setFontPath(String fontPath) {
    this->fontPath = fontPath;

    createNewTexture();
}

void Text::draw() {
    Rect::draw();

    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) == -1) {
        cerr << "Text::draw -> failed to query texture.\n";
    }

    SDL_RenderCopy(Window::renderer, texture, nullptr, &this->rect);
}

void Text::createNewTexture() {

    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font)
        cerr << "Text::createNewTexture -> failed to load font.\n";

    surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface)
        cerr << "Text::createNewTexture -> failed to create text surface.\n";

    if (texture)
        SDL_DestroyTexture(texture);

    texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    if (!texture)
        cerr << "Text::createNewTexture -> failed to create text texture.\n";

    TTF_CloseFont(font);
    SDL_FreeSurface(surface);
}