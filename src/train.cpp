// Copyright 2021 NNTU-CS
#include "train.h"
#include <iostream>

Train::Train() {
    countOp = 0;
    Cage{ false, nullptr, nullptr };
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

void Train::addCage(bool l) {
	if (!first) {
		first = new Cage;
		first->light = l;
		first->prev = first;
		first->next = first;
	} else {
		Cage* c = first;
		while (c->next != first)
			c = c->next;
		Cage* newCage = new Cage;
		newCage->light = l;
		newCage->prev = newCage->next = nullptr;
		newCage->prev = c;
		c->next = newCage;
		newCage->next = first;
		first->prev = newCage;
	}
}

int Train::getLength() {
    if (!first) {
        return 0;
    }
    int count_steps = 0;
    Cage* current = first;
    if (!current->light) {
        current->light = true;
        count_steps++;
        current = current->next;
        while (!current->light) {
            current->light = true;
            count_steps++;
            current = current->next;
        }
    } else {
        current->light = false;
        count_steps++;
        current = current->next;
        while (current->light) {
            current->light = false;
            count_steps++;
            current = current->next;
        }
    }
    countOp = count_steps * 2;
    return count_steps;
}

int Train::getOpCount() {
    return countOp;
}

