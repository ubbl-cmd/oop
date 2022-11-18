#ifndef ABSTRACTOBSERVABLE_H
#define ABSTRACTOBSERVABLE_H

#include "Observable.h"

#include <vector>

class AbstractObservable: public Observable {
public:
	virtual void addObserver(Observer* observer) override;
	virtual void removeObserver(Observer* observer) override;
	virtual void notifyObserver(Message& message) override;

protected:
    std::vector<Observer*> observers;
};


#endif //ABSTRACTOBSERVABLE_H
