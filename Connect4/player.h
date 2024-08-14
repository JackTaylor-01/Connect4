#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "board.h"

class Player {
public:
    Player(std::string name, Token token);
    std::string getName() const;
    Token getToken() const;

private:
    std::string name;
    Token token;
};

#endif