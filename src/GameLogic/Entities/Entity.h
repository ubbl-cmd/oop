#ifndef ENTITY_H
#define ENTITY_H


class Entity {
private:
    int verticalPosition;
    int horizontalPosition;
public:
    int getVerticalPosition() const {
        return verticalPosition;
    }

    void setVerticalPosition(int new_verticalPosition) {
        verticalPosition = new_verticalPosition;
    }

    int getHorizontalPosition() const {
        return horizontalPosition;
    }

    void setHorizontalPosition(int new_horizontalPosition) {
        horizontalPosition = new_horizontalPosition;
    }

    explicit Entity(int verticalPosition=0, int horizontalPosition=0) : verticalPosition(verticalPosition),
                                                           horizontalPosition(horizontalPosition) {}
};


#endif //ENTITY_H
