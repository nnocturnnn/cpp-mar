#include "Player.h"

size_t Player::posX() const {
    return m_posX;
}

size_t Player::posY() const {
    return m_posY;
}

char Player::getIdentifier() const {
    return 'P';
}

void Player::movePlayer(MoveManager::Direction dir) {
    if (dir == MoveManager::Direction::Up) {
        m_posY -= 1;
    } else if (dir == MoveManager::Direction::Down) {
        m_posY += 1;
    } else if (dir == MoveManager::Direction::Right) {
        m_posX += 1;
    } else if (dir == MoveManager::Direction::Left) {
        m_posX -= 1;
    }
}
