//
// Created by dawid on 23.11.2019.
//


#include "../headers/View.h"


View::View(int width, int height)
        : width(width), height(height) {
}

View::View(int positionX, int positionY, int width, int height)
        : positionX(positionX), positionY(positionY), width(width), height(height) {
}

View::~View() {

}

void View::setColor(const int *color) {
    r = color[0];
    g = color[1];
    b = color[2];
}

void View::setTransparency(int transparency) {
    this->transparency = transparency;
}

void View::draw() {
    rect = {positionX, positionY, width, height};

    SDL_SetRenderDrawBlendMode(Window::renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(Window::renderer, r, g, b, transparency);
    SDL_RenderFillRect(Window::renderer, &rect);
}

void View::setPosition(int positionX, int positionY) {
    this->positionX = positionX;
    this->positionY = positionY;
}

void View::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}

int View::getWidth() {
    return width;
}

void View::pollEvents(SDL_Event &event) {

}
