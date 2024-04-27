// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() {
    countOp = 0;
    first = nullptr;
}

Train::~Train() {
    if (first) {
        Cage *current = first;
        do {
            Cage *next = current->next;
            delete current;
            current = next;
        } while (current != first);
    }
}

void Train::addCage(bool light) {
    Cage *newCage = new Cage();
    newCage->light = light;
    if (!first) {
        first = newCage;
        newCage->next = newCage;
        newCage->prev = newCage;
    } else {
        Cage *last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        first->prev = newCage;
        newCage->next = first;
    }
}

int Train::getLength() {
    if (!first) return 0;
    Cage *current = first;
    int length = 0;
    do {
        length++;
        current = current->next;
        countOp++;
    } while (current != first);
    return length;
}

int Train::getOpCount() {
    return countOp;
}

