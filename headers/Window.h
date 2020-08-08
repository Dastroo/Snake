//
// Created by dawid on 23.11.2019.
//

#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>


using String = std::string;
using std::cerr;
using std::cout;


class Window {

public:
    static SDL_Renderer *renderer;

private:
    String title = "";
    int width = 800;
    int height = 600;

    bool closed = true;

    SDL_Window *window = nullptr;


public:
    Window(const String &title, int width, int height);

    virtual ~Window();

    void pollEvents(SDL_Event &event);

    void clear() const;

    inline bool isClosed() const { return closed; }

    void close() { closed = true; }


private:
    bool create();

    bool init();
};
