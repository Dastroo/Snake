//
// Created by dawid on 23.11.2019.
//


#include "../headers/Image.h"


Image::Image(int width, int height, const String &imagePath)
        : Rect(width, height) {

    if (imagePath.empty()) {
        cerr << "Image::Image -> image path empty.\n";
    }

    auto surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        cerr << "Image::Image -> failed to create surface.\n";
        texture = nullptr;
        return;
    }

    texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        cerr << "Image::Image -> failed to create texture.\n";
        return;
    }

    setTransparency(0);
}

Image::Image(int width, int height) : Rect(width, height) {

}

void Image::draw() {
    Rect::draw();
    if (texture)
        if (SDL_RenderCopy(Window::renderer, texture, nullptr, &rect) == -1)
            cerr << "Image::draw -> failed to render image.\n";
}

Image::~Image() {
    SDL_DestroyTexture(texture);
}

void Image::pollEvents(SDL_Event &event) {
    Rect::pollEvents(event);
}

void Image::setImage(const String &imagePath) {
    auto surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        cerr << "Image::setImage -> failed to create surface.\n";
    }

    texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    if (!texture) {
        cerr << "Image::setImage -> failed to create texture.\n";
    }
    SDL_FreeSurface(surface);
}

