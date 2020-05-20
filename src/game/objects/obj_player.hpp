#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include "object.hpp"

namespace rpg::objects
{
    class Player : public Object
    {
    private:
        REGISTER_DEC_TYPE(Player);

    public:
        virtual void ObjectInitFromFile(std::ifstream &fileIn) override;
        Player();

        // Add components where it so fits, by AddComponent(new ... {});
    };
} // namespace rpg::objects

#endif // GAME_PLAYER_HPP