#include "Map.h"
#include "Player.h"

Map::Map(size_t width, size_t height, std::shared_ptr<Player> &player)
    : m_width(width), m_height(height), m_player(player), m_map(new char[m_height * m_width]) {
    generateMap();
}

void Map::generateMap() {
    for (size_t i = 0; i < m_width * m_height; ++i) {
        int element = rand() % 3;
        if (element == 0) {
            m_map[i] = '.';
        } else if (element == 1) {
            m_map[i] = '@';
        } else if (element == 2) {
            m_map[i] = 'T';
        }
    }
}

void Map::outputMap() const {
    for (size_t i = 0; i < m_height * m_width; ++i) {
        if (i % m_width == 0 && i != 0) {
            std::cout << std::endl;
        }
        if (i == m_player->posX() + m_player->posY() * m_width) {
            std::cout << m_player->getIdentifier() << " ";
        } else {
            std::cout << m_map[i] << " ";
        }
    }
    std::cout << std::endl;
}

size_t Map::width() const {
    return m_width;
}

size_t Map::height() const {
    return m_height;
}
