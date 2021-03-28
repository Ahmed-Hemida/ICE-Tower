#include "player_character.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;



player_character::player_character()
{
}
player_character::~player_character()
{
}




void player_character::move_left(Sprite &player_sprite, IntRect &intrect)
{


    player_sprite.move(-move_speed,0);

     if (clock.getElapsedTime().asSeconds() > .50f)
    {
        if(intrect.left<= 33*13)
        {
            intrect.left=33.75*15;
        }
        else
        {
            intrect.left-=33;
        }
        player_sprite.setTextureRect(intrect);
       clock.restart();
    }
}


void player_character::move_right(Sprite &player_sprite, IntRect &intrect)
{


   player_sprite.move(move_speed,0);

   if (clock.getElapsedTime().asSeconds() > .50f)
    {

        if(intrect.left>= 33*4)
        {
            intrect.left=33;
        }
        else
        {
            intrect.left+=33;
        }
        player_sprite.setTextureRect(intrect);
        clock.restart();
    }


}


void player_character::move_jump(Sprite &player_sprite, IntRect &intrect)
{




     player_sprite.move(0,-2);
    intrect.left=34*8;
    player_sprite.setTextureRect(intrect);
}


void player_character::gravity(Sprite &player_sprite,int window_height ,bool gravity,bool colision)
{

    if((player_sprite.getPosition().y)<window_height &&
       gravity==false&&
       colision==false)
    {
       //for(int i=0 ; i<2;i++)
            player_sprite.move(0,1);
       // player_sprite.move(0,.01);
    }
    if (player_sprite.getPosition().x<120)
    {
        player_sprite.setPosition(693,player_sprite.getPosition().y) ;
    }
    if (player_sprite.getPosition().x>693)
    {
        player_sprite.setPosition(120,player_sprite.getPosition().y) ;
    }

}
