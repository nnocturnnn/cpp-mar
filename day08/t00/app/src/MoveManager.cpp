#include "MoveManager.h"
#include "Player.h"
#include "Map.h"

MoveManager::MoveManager(std::shared_ptr<Player> &player,
                         std::shared_ptr<Map> &map) {
    m_player = player;
    m_map = map;
}

void MoveManager::processInputAndMove(const std::string &inputStr) {
    if (inputStr == "u") {
        if (checkMove(Direction::Up)) {
            m_player->movePlayer(Direction::Up);
        }
    } else if(inputStr == "d") {
        if (checkMove(Direction::Down)) {
            m_player->movePlayer(Direction::Down);
        }
    } else if(inputStr == "r") {
        if (checkMove(Direction::Right)) {
            m_player->movePlayer(Direction::Right);
        }
    } else if(inputStr == "l") {
        if (checkMove(Direction::Left)) {
            m_player->movePlayer(Direction::Left);
        }
    }
    m_map->outputMap();
}

bool MoveManager::checkMove(Direction dir) const {
    auto player = m_player.get();
    auto map = m_map.get();
    bool flag = false;
    int pposition = player->posX() + player->posY() * map->width();

    if (dir == Direction::Up && static_cast<int>(pposition) - static_cast<int>(map->height()) > 0) {
        flag = true;
    } else if (dir == Direction::Down && pposition + map->height() < map->height() * map->width()) {
        flag = true;
    } else if (dir == Direction::Right && player->posX() < map->height() - 1) {
        flag = true;
    } else if (dir == Direction::Left && player->posX() > 0) {
        flag = true;
    }
    if (!flag) {
        std::cout << "Invalid direction" << std::endl;
    }
    return flag;
}
