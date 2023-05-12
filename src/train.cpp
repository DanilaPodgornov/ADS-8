// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}

void Train::addCage(bool light) {
    if (nullptr == first) {
        first = new Cage;
        first->light = light;
        first->next = nullptr;
        first->prev = nullptr;
    } else if (nullptr == first->next && nullptr == first->prev) {
        first->next = new Cage;
        first->next->light = light;
        first->next->prev = first;
        first->next->next = first;
        first->prev = first->next;
    } else {
        Cage* tail = first->prev;
        tail->next = new Cage;
        tail->next->light = light;
        tail->next->prev = tail;
        tail->next->next = first;
        first->prev = tail->next;
    }
}

int Train::getLength() {
    Cage* currentCage = first;
    currentCage->light = true;
    int result = 0;
    bool temp = true;
    int steps = 0;
    while (temp) {
        steps = 0;
        do {
            currentCage = currentCage->next;
            countOp++;
            steps++;
        } while (true != currentCage->light);
        currentCage->light = false;
        for (int i = steps; i > 0; i--) {
            currentCage = currentCage->prev;
            countOp++;
        }
        temp = currentCage->light;
    }
    return steps;
}

int Train::getOpCount()
{
    return countOp;
}
