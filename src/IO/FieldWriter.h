#ifndef FIELDWRITER_H
#define FIELDWRITER_H


#include "Views/FieldView.h"

#include "Entities/Player/Player.h"

class FieldWriter {
public:
    void PrintField(Field &field);

    explicit FieldWriter(Player &player);
private:
    FieldView *fieldView;
    Player &player;
};


#endif //FIELDWRITER_H
