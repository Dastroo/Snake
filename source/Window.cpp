//
// Created by dawid on 23.11.2019.
//


#include "../headers/Window.h"


SDL_Renderer *Window::renderer = nullptr;

Window::Window(const String &title, int width, int height)
        : title(title), width(width), height(height) {
    closed = !(init() && create());
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

bool Window::create() {
    //  creates window
    window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            width, height,
            0);

    if (window == nullptr) {
        cerr << "Window -> failed to create window.\n";
        return false;
    }

    //  creates renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cerr << "Window -> failed to create renderer.\n";
        return false;
    }

    return true;
}

bool Window::init() {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "Window -> failed to initialize SDL_video\n";
        return false;
    }

    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        cerr << "Window -> failed to initialize SDL_image.\n";
        return false;
    }

    if (TTF_Init() == -1) {
        cerr << "Window -> failed to initialize SDL_ttf.\n";
        return false;
    }

    //  if everything initialized properly returns true
    return true;
}

void Window::pollEvents(SDL_Event &event) {
    //  looks for user input and performs actions
    switch (event.type) {
        case SDL_QUIT:
            closed = true;
            cout << "Window -> you clicked window \'x\'!\n";
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    cout << "Window -> you clicked \'esc\'!\n";
                    closed = true;
                    break;
                case SDLK_f:
                    cout << "Window -> you clicked \'f\'!\n";
                    break;

                default:
                    break;
            }
        default:
            //  when idle called ~60times/s
            break;
    }
}

void Window::clear() const {
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}