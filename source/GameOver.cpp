//
// Created by dawid on 24.11.2019.
//

#include "../headers/GameOver.h"
#include "../headers/TextView.h"
#include "../headers/Game.h"

GameOver::GameOver(NewGameInterface &listener)
        : listener(&listener) {

    int black[3] = {0, 0, 0};

    scoreTV = new TextView();
    scoreTV->setPosition(200, 200);
    scoreTV->setColor(black);
    newGameTV = new TextView();
    newGameTV->setPosition(200, 235);
    newGameTV->setColor(black);
    quitTV = new TextView();
    quitTV->setPosition(230, 265);
    quitTV->setColor(black);
}

GameOver::~GameOver() {
    delete scoreTV;
    delete newGameTV;
    delete quitTV;
}

void GameOver::draw() {
    scoreTV->draw();
    newGameTV->draw();
    quitTV->draw();
}

void GameOver::update(int score) {

    scoreTV->setText("SCORE: " + std::to_string(score));
    newGameTV->setText("NEW GAME");
    quitTV->setText("QUIT");

//    draw();
}

void GameOver::pollEvents(SDL_Event &event) {

    int mouseX = event.motion.x;
    int mouseY = event.motion.y;

    int NGWidth = newGameTV->getWidth();

    if (event.type == SDL_MOUSEBUTTONUP) {
        if (mouseX >= 200 &&
            mouseX <= 200 + NGWidth &&
            mouseY >= 235 &&
            mouseY <= 235 + 25) {
            listener->newGame();
        }
        if (mouseX >= 230 &&
            mouseX <= 230 + NGWidth &&
            mouseY >= 265 &&
            mouseY <= 265 + 25) {
            //  put menu here

        }
    }

}
