#include <algorithm>
#include <iostream>
#include "AbstractObservable.h"


void AbstractObservable::addObserver(Observer *observer) {
    observers.push_back(observer);
}

void AbstractObservable::removeObserver(Observer *observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void AbstractObservable::notifyObserver(Message& message) {
    //std::cout<<"here"<<std::endl;
    for (auto & observer : observers) {
        observer->handleEvent(message);
    }
}
