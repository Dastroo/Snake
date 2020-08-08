//
// Created by dawid on 26.11.2019.
//

#include <SDL2/SDL_events.h>
#include "../headers/Snake.h"

Snake::Snake() {

    size = 2;
    snake = new int[size];

    //  snake starting coordinates
    headX = 29;
    headY = 29;

    //  snake head and tail
    head = snake[0];
    tail = snake[size - 1];

}

Snake::~Snake() {
    delete snake;
}

int Snake::getSnakeCell(int cell) {
    return snake[cell];
}

int Snake::getHead() {
    return head;
}

int Snake::getTail() {
    return tail;
}

int Snake::getSize() {
    return size;
}

void Snake::grow() {

    ++size;
    int *backup = new int[size];
    backup[0] = head;
    for (int i = 0; i < size - 1; ++i) {
        backup[i + 1] = snake[i];
    }
    delete snake;
    snake = backup;

    //  set new tail
    tail = snake[size - 1];
}

void Snake::move() {

    //  set new tail
    tail = snake[size - 1];

    int *backup = new int[size];
    backup[0] = head;
    for (int i = 0; i < size - 1; ++i) {
        backup[i + 1] = snake[i];
    }
    delete snake;
    snake = backup;
}

void Snake::pollEvents(SDL_Event &event) {

    if (event.type == SDL_KEYDOWN)
        switch (event.key.keysym.sym) {

            case SDLK_w:
            case SDLK_UP:
                input = UP;

                cout << "Snake::pollEvents -> 'w'.\n";
                break;

            case SDLK_s:
            case SDLK_DOWN:
                input = DOWN;

                cout << "Snake::pollEvents -> 's'.\n";
                break;

            case SDLK_a:
            case SDLK_LEFT:
                input = LEFT;

                cout << "Snake::pollEvents -> 'a'.\n";
                break;

            case SDLK_d:
            case SDLK_RIGHT:
                input = RIGHT;

                cout << "Snake::pollEvents -> 'd'.\n";
                break;

            default:
                break;
        }
}

void Snake::updateDirection() {

    //  check if input isn't opposite to the of the moving snake
    switch (input) {
        case UP:
            if (direction != DOWN)
                direction = input;
            break;
        case DOWN:
            if (direction != UP)
                direction = input;
            break;
        case LEFT:
            if (direction != RIGHT)
                direction = input;
            break;

        case RIGHT:
            if (direction != LEFT)
                direction = input;
            break;

        default:
            break;
    }
}

void Snake::updatePosition() {

    int xCount = 59;
    int yCount = 59;

    switch (direction) {
        case UP:
            headY = --headY;
            if (headY < 0)
                headY = yCount;
            head = map[headY][headX];

            cout << "Snake::updatePosition -> up.\n";
            break;

        case DOWN:
            headY = ++headY;
            if (headY > yCount)
                headY = 0;
            head = map[headY][headX];

            cout << "Snake::updatePosition -> down.\n";
            break;

        case LEFT:
            headX = --headX;
            if (headX < 0)
                headX = xCount;
            head = map[headY][headX];

            cout << "Snake::updatePosition -> left.\n";
            break;

        case RIGHT:
            headX = ++headX;
            if (headX > yCount)
                headX = 0;
            head = map[headY][headX];

            cout << "Snake::updatePosition -> right.\n";
            break;

        default:
            std::cerr << "Snake::updatePosition -> failed to calculate new position.\n";
    }
}

void Snake::setListener(DirectionChangeListener &listener) {
    this->listener = &listener;
}

void Snake::attachToMap(int **map) {
    this->map = map;
}

void Snake::reset() {
    size = 2;
}
