//
// Created by dawid on 26.11.2019.
//

#include <SDL2/SDL_events.h>
#include "../headers/Snake.h"

Snake::Snake() {

    size = 2;
    snake = new int[size];

    //  snake starting coordinates
    headX = 30;
    headY = 30;

    //  snake head and tail
    head = snake[0];
    tail = snake[size - 1];

}

Snake::~Snake() {
    delete snake;
}

int Snake::getSnake(int SnakePart) {
    return snake[SnakePart];
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
                direction = UP;

                cout << "Game -> 'w'.\n";
                break;

            case SDLK_s:
            case SDLK_DOWN:
                direction = DOWN;

                cout << "Game -> 's'.\n";
                break;

            case SDLK_a:
            case SDLK_LEFT:
                direction = LEFT;

                cout << "Game -> 'a'.\n";
                break;

            case SDLK_d:
            case SDLK_RIGHT:
                direction = RIGHT;

                cout << "Game -> 'd'.\n";
                break;

            default:
                break;
        }

    listener->onChanged(direction);
}

void Snake::updateDirection(int direction) {

    //  check if direction isn't opposite to the of the moving snake
    switch (direction) {
        case UP:
            if (movingDirection != DOWN)
                movingDirection = direction;
            break;
        case DOWN:
            if (movingDirection != UP)
                movingDirection = direction;
            break;
        case LEFT:
            if (movingDirection != RIGHT)
                movingDirection = direction;
            break;

        case RIGHT:
            if (movingDirection != LEFT)
                movingDirection = direction;
            break;

        default:
            std::cerr << "dupa\n";
    }
}

void Snake::updatePosition() {

    int xCount = 59;
    int yCount = 59;

    switch (movingDirection) {
        case UP:
            headY = --headY;
            if (headY < 0)
                headY = yCount;
            head = map[headY][headX];

            cout << "snakeMove -> up.\n";
            break;

        case DOWN:
            headY = ++headY;
            if (headY > yCount)
                headY = 0;
            head = map[headY][headX];

            cout << "snakeMove -> down.\n";
            break;

        case LEFT:
            headX = --headX;
            if (headX < 0)
                headX = xCount;
            head = map[headY][headX];

            cout << "snakeMove -> left.\n";
            break;

        case RIGHT:
            headX = ++headX;
            if (headX > yCount)
                headX = 0;
            head = map[headY][headX];

            cout << "snakeMove -> right.\n";
            break;

        default:
            std::cerr << "Game -> failed to calculate new position.\n";
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
