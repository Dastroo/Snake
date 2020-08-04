//
// Created by dawid on 23.11.2019.
//

#include "../headers/TextView.h"


TextView::TextView()
        : View(0, 0) {
    createNewTexture();
}

TextView::TextView(String text)
        : View(0, 0), text(text) {

    createNewTexture();
}

TextView::~TextView() {
    SDL_DestroyTexture(texture);
}

String TextView::getText() {
    return text;
}

void TextView::setText(String text) {
    this->text = text;

    createNewTexture();
}

void TextView::setTextColor(SDL_Color color) {
    this->color = color;

    createNewTexture();
}

void TextView::setFontSize(int fontSize) {
    this->fontSize = fontSize;

    createNewTexture();
}

void TextView::setFontPath(String fontPath) {
    this->fontPath = fontPath;

    createNewTexture();
}

void TextView::draw() {
    View::draw();

    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) == -1) {
        cerr << "TextView -> failed to query texture.\n";
    }

    SDL_RenderCopy(Window::renderer, texture, nullptr, &this->rect);
}

void TextView::createNewTexture() {

    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font)
        cerr << "TextView -> failed to load font.\n";

    surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface)
        cerr << "TextView -> failed to create text surface.\n";

    if (texture)
        SDL_DestroyTexture(texture);

    texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    if (!texture)
        cerr << "TextView -> failed to create text texture.\n";

    TTF_CloseFont(font);
    SDL_FreeSurface(surface);
}