//
// Created by dawid on 23.11.2019.
//


#include "../headers/ImageView.h"


ImageView::ImageView(int width, int height, const String &imagePath)
        : View(width, height) {

    if (imagePath.empty()) {
        texture = nullptr;
        return;
    }

    auto surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        cerr << "ImageView -> failed to create surface.\n";
        texture = nullptr;
        return;
    }

    texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        cerr << "ImageView -> failed to create texture.\n";
        return;
    }

    setTransparency(0);
}

void ImageView::draw() {
    View::draw();
    if (texture)
        SDL_RenderCopy(Window::renderer, texture, nullptr, &rect);
}

ImageView::~ImageView() {
    SDL_DestroyTexture(texture);
}

void ImageView::pollEvents(SDL_Event &event) {
    View::pollEvents(event);

}

void ImageView::setImage(const String &imagePath) {
    auto surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        cerr << "ImageView -> failed to create surface.\n";
    }

    texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
    if (!texture) {
        cerr << "ImageView -> failed to create texture.\n";
    }
    SDL_FreeSurface(surface);
}
