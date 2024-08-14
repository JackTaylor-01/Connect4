#include "player.h"

Player::Player(std::string name, Token token) : name(name), token(token) {}

std::string Player::getName() const {
    return name;
}

Token Player::getToken() const {
    return token;
}