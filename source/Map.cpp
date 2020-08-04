//
// Created by dawid on 24.11.2019.
//

#include <random>
#include "../headers/Map.h"
#include "../headers/Snake.h"

Map::Map() {

    //  set map parameters
    int fieldSize = 10;
    int marginLeft = 0;
    int marginTop = 0;

    int fieldID = 0;
    for (int i = 0; i < 60; ++i) {
        for (int j = 0; j < 60; ++j) {

            //  create game field
            auto field = new Field(fieldSize, fieldID);

            //  set position
            int positionX = j * fieldSize + marginLeft;
            int positionY = i * fieldSize + marginTop;
            field->setPosition(positionX, positionY);

            //  put set object into array
            map[fieldID] = field;
            fieldID++;
        }
    }
    generateNewApple();
}

Map::~Map() {
    //  delete whole map
    for (int i = 0; i < 3600; ++i) {
        delete map[i];
    }
}

void Map::updateMap(int *array, int FLAG) {

    for (int i = 0; i < sizeof(array); ++i) {

        map[array[i]]->setFieldTo(FLAG);
    }
}

void Map::updateMap(int i, int FLAG) {
    map[i]->setFieldTo(FLAG);
}

void Map::draw() {
    //  draw whole map
    for (int i = 0; i < 3600; ++i) {
        map[i]->draw();
    }
}

Field *Map::getMapOn(int fieldId) {
    return map[fieldId];
}

void Map::generateNewApple() {
    int position = random(0, 3599);

    if (map[position]->getType() != Field::EMPTY) {
        generateNewApple();
        return;
    }

    updateMap(position, Field::APPLE);
}

int Map::random(int min, int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);

    return distr(eng);
}




