//
// Created by dawid on 26.11.2019.
//

#include "../headers/Field.h"

Field::Field(int fieldSize, int id)
        : Rect(fieldSize, fieldSize), id(id) {
    setFieldTo(EMPTY);
}

Field::~Field() {

}

void Field::setFieldTo(int FLAG) {

    int white[3] = {255, 255, 255};
    int black[3] = {0, 0, 0};
    int red[3] = {255, 0, 0};

    switch (FLAG) {
        case EMPTY:
            type = FLAG;
            setColor(black);
            break;
        case SNAKE:
            type = FLAG;
            setColor(white);
            break;
        case APPLE:
            type = FLAG;
            setColor(red);
            break;
        case WALL:
            type = FLAG;
            setColor(white);
            break;
        default:
            std::cerr << "Field::setFieldTo -> failed at setting type.\n";
    }
}

int Field::getType() {
    return type;
}

int Field::getId() {
    return id;
}
