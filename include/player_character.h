
#define PLAYER_CHARACTER_H
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
class player_character
{
    public:
        player_character();
        virtual ~player_character();



    private :
            Clock clock;
        float move_speed = .7;



     public:
    void move_right(Sprite &player_sprite , IntRect &intrect);
    void move_left(Sprite &player_sprite , IntRect &intrect);
    void move_jump(Sprite &player_sprite , IntRect &intrect);
    void gravity(Sprite &player_sprite ,int window_height,bool gravity,bool colision);


};


