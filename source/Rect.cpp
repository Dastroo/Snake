//
// Created by dawid on 23.11.2019.
//


#include "../headers/Rect.h"


Rect::Rect(int width, int height)
        : width(width), height(height) {
}

Rect::Rect(int positionX, int positionY, int width, int height)
        : positionX(positionX), positionY(positionY), width(width), height(height) {
}

Rect::~Rect() {

}

void Rect::setColor(const int *color) {
    r = color[0];
    g = color[1];
    b = color[2];
}

void Rect::setTransparency(int transparency) {
    this->transparency = transparency;
}

void Rect::draw() {
    rect = {positionX, positionY, width, height};

    if (SDL_SetRenderDrawBlendMode(Window::renderer, SDL_BLENDMODE_BLEND) == -1)
        cerr << "Rect::draw -> failed to set blend mode.\n";
    if (SDL_SetRenderDrawColor(Window::renderer, r, g, b, transparency) == -1)
        cerr << "Rect::draw -> failed to set rect color.\n";
    if (SDL_RenderFillRect(Window::renderer, &rect) == -1)
        cerr << "Rect::draw -> failed to render rect.\n";
}

void Rect::setPosition(int positionX, int positionY) {
    this->positionX = positionX;
    this->positionY = positionY;
}

void Rect::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}

int Rect::getWidth() {
    return width;
}

void Rect::pollEvents(SDL_Event &event) {

}
