//
// Created by dawid on 24.11.2019.
//

#include <random>
#include "../headers/Game.h"

Game::Game() {

    int size = 60;

    map = new int *[size];
    for (int i = 0; i < size; ++i)
        map[i] = new int[size];

    int iterator = 0;
    for (int i = 0; i < 60; ++i) {
        for (int j = 0; j < 60; ++j) {
            map[i][j] = iterator;
            iterator++;
        }
    }

    snake = new Snake();
    snake->attachToMap(map);
    snake->setListener(*this);
}

Game::~Game() {

    delete gameOverScreen;
    delete snakeMap;
    delete window;
}

void Game::launchGame() {

    //  create window object
    window = new Window("Snake", 600, 600);

    newGame();
}

void Game::newGame() {
    over = false;

    //  create new score board
    if (gameOverScreen)
        delete gameOverScreen;
    gameOverScreen = new GameOver(*this);

    //  create new map
    if (snakeMap)
        delete snakeMap;
    snakeMap = new Map();

    gameLoop();
}

void Game::gameLoop() {

    while (!window->isClosed()) {

        pollEvents();

        if (!over)
            if (++frameCount == snakeSpeed) {
                frameCount = 0;
                update();
            }

        render();

        Millisec timespan(2);
        sleep_for(timespan);
    }
}

void Game::pollEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {

        //  pull events for window
        window->pollEvents(event);

        if (over)
            gameOverScreen->pollEvents(event);
        else
            //  get input for snake
            snake->pollEvents(event);
    }
}

void Game::update() {

    snake->updateDirection();
    snake->updatePosition();

    checkTargetFieldType();
    updateSnakePosOnMap();
}

void Game::checkTargetFieldType() {

    int snakeHeadPosition = snake->getHead();

    auto field = snakeMap->getMapOn(snakeHeadPosition);
    switch (field->getType()) {
        case Field::EMPTY:
            snake->move();
            break;

        case Field::APPLE:
            snake->grow();
            snakeMap->generateNewApple();
            break;

        case Field::SNAKE:
        case Field::WALL:
            gameOver();
            break;

        default:
            std::cerr << "Game::checkTargetFieldType -> unknown field type.\n";
    }
}

void Game::updateSnakePosOnMap() {
    snakeMap->updateMap(snake->getHead(), Field::SNAKE);
    snakeMap->updateMap(snake->getTail(), Field::EMPTY);
}

void Game::render() {
    if (over)
        gameOverScreen->draw();
    else
        snakeMap->draw();

    window->clear();
}

void Game::onChanged(int input) {

}

void Game::gameOver() {
    over = true;
    gameOverScreen->update(snake->getSize());
}

void Game::quitGame() {
    window->close();
}






