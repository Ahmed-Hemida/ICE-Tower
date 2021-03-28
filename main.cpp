#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Menu.h"
#include"Option.h"
#include"player_character.h"
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;
using namespace sf;

bool colision(Sprite& player_sprite, Sprite& platform_sprite, bool colision, int& jump_hieght);
void platform_gravity(Sprite& platform_sprite, int score, bool contact);
void player_lose(RenderWindow& window, Music& music, bool& open, int& volume, int& high, int& low,bool& m, bool& carc, Music& lse, Music& jump, int& volume_s, int& high_s, int& low_s,int lose, int width,int hight);
void moveup(int& menuselected,Text main[]);
void movedown( int& menuselected,Text main[]);
void opt(RenderWindow& window, Music& music, bool& open, int& volume, int& high, int& low,bool& m, bool& carc, Music& lse,Music& jump, int& volume_s, int& high_s, int& low_s);
void men(RenderWindow& window, Music& music, bool& open, int& volume, int& high, int& low,bool& m, bool& carc, Music& lse, Music& jump, int& volume_s, int& high_s, int& low_s);
void play(RenderWindow& window, Music& music, bool& open, int& volume, int& high, int& low,bool& m, bool& carc, Music& lse, Music& jump, int& volume_s, int& high_s, int& low_s);



int main()
{
    bool m = false;
    bool open = false;
    bool c=false;
    int volume=100;
    int high = 10;
    int low = 9;
    int volume_s = 100;
    int high_s = 10;
    int low_s = 9;
    Music jump;
    RenderWindow window(VideoMode(800,500), "ICE TOWER");
    Music music;
    Music lose;
    music.openFromFile("music.ogg");
    music.play();
    men(window, music, open, volume, high, low, m, c,lose,jump,volume_s,high_s,low_s);
}


void play(RenderWindow& window, Music& music, bool& open, int& volume, int& high, int& low,bool& m, bool& carc, Music& lse, Music& jump, int& volume_s, int& high_s, int& low_s)
{
    jump.openFromFile("jump.ogg");
    open = false;
    music.pause();

    Texture player;
    player.loadFromFile("Images_project/characher3.png");
    Texture player2;
    player2.loadFromFile("Images_project/carch.png");
    Sprite player_sprite;
    if (carc == true)
    {
        player_sprite.setTexture(player);
    }
    else
    {
        player_sprite.setTexture(player2);
    }
    player_sprite.setPosition(300, 400);
    IntRect rect(0, 0, 33, 80);
    player_sprite.setTextureRect(rect);
    player_character opject_player;

    //platform_0
    Texture plat_form;
    plat_form.loadFromFile("Images_project/platform.png");
    Sprite sprite_platforn[5];
    sprite_platforn[0].setTexture(plat_form);
    sprite_platforn[0].setPosition(100, 0);
    //platform_1

    sprite_platforn[1].setTexture(plat_form);
    sprite_platforn[1].setPosition(400, 100);
    //platform_2

    sprite_platforn[2].setTexture(plat_form);
    sprite_platforn[2].setPosition(200, 200);
    //platform_3

    sprite_platforn[3].setTexture(plat_form);
    sprite_platforn[3].setPosition(300, 300);
    //platform_4

    sprite_platforn[4].setTexture(plat_form);
    sprite_platforn[4].setPosition(500, 400);

//backgroung_1
    Texture texture;
    texture.loadFromFile("Images_project/background.jpg");
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    //backgroung_2
    Texture text;
    text.loadFromFile("Images_project/backgroud.png");
    Sprite back;
    back.setTexture(text);
    back.setPosition(0, 0);
    Clock clock;
    //gravaty
    bool gravity = true;
    bool colied = true;
    // jump
    int jump_height = 0;
    int score =0;
    sf::Font s;
    s.loadFromFile("Blackbird.ttf");
    sf::Text txt;
    stringstream sscore;
    sscore << "Score: " ;
    txt.setFont(s);
    txt.setCharacterSize(45);
    txt.setFillColor(sf::Color::Black);
    txt.setPosition(0,0);
    txt.setString(sscore.str());
   // bool space_realesed=true;
   // bool space_pressed = true;
    bool ply=true ;
    int z = 5;
    int i = 0;


    string c;

    sf::Text ss;
    stringstream lose;
    lose << c << score ;
    ss.setFont(s);
    ss.setCharacterSize(45);
    ss.setFillColor(sf::Color::Yellow);
    ss.setPosition(300, 250);
    ss.setString(sscore.str());
    //  Music lse;
    lse.openFromFile("Lose.ogg");
    //MUNE_PAUSE
    bool pause = false;
    Texture pause_end;
    pause_end.loadFromFile("end.png");
    Sprite end;
    end.setTexture(pause_end);
    int pauseselected = 0;
    Text Pause[3];
    Pause[0].setFont(s);
    Pause[0].setString("Resume");
    Pause[0].setCharacterSize(50);
    Pause[0].setFillColor(sf::Color::Red);
    Pause[0].setPosition(300, 175);
    Pause[1].setFont(s);
    Pause[1].setString("Main Menu");
    Pause[1].setCharacterSize(50);
    Pause[1].setFillColor(sf::Color::Black);
    Pause[1].setPosition(300, 250);



    while (window.isOpen())
    {


        Event event;
        if(pause==false)
        {

            if (Keyboard::isKeyPressed(Keyboard::Key::A) || Keyboard::isKeyPressed(Keyboard::Key::Left))
            {
                opject_player.move_left(player_sprite, rect);

            }

            if (Keyboard::isKeyPressed(Keyboard::Key::D) || Keyboard::isKeyPressed(Keyboard::Key::Right))
            {
                opject_player.move_right(player_sprite, rect);

            }
            if (Keyboard::isKeyPressed(Keyboard::Key::W) ||  Keyboard::isKeyPressed(Keyboard::Key::Space))
            {
               // space_pressed = false;
                jump_height++;
              if (jump_height <= 150)
                {
                    opject_player.move_jump(player_sprite, rect);
                    gravity = false;
                }
            }


            sscore.str("");
            sscore << "Score " << score;
            txt.setString(sscore.str());


            if (colision(player_sprite, sprite_platforn[0], colied, jump_height) == true ||
                colision(player_sprite, sprite_platforn[1], colied, jump_height) == true ||
                colision(player_sprite, sprite_platforn[2], colied, jump_height) == true ||
                colision(player_sprite, sprite_platforn[3], colied, jump_height) == true ||
                colision(player_sprite, sprite_platforn[4], colied, jump_height) == true)
            {
                colied = true;

            }
            else
            {
                colied = false;

            }
            if (colision(player_sprite, sprite_platforn[4], colied, jump_height) == true &&z==5)
            {

                if (score <= 10*(i))
                {
                    z = 1;
                    score += 10;
                    i++;
                }

            }
            if (colision(player_sprite, sprite_platforn[3], colied, jump_height) == true &&z==1)
            {

                if (score <= 10*(i))
                {
                    z = 2;
                    score += 10;
                    i++;
                }

            }
            if (colision(player_sprite, sprite_platforn[2], colied, jump_height) == true &&z==2)
            {

                if (score <= 10*(i))
                {
                    z = 3;
                    score += 10;
                    i++;
                }

            }
            if (colision(player_sprite, sprite_platforn[1], colied, jump_height) == true &&z==3)
            {

                if (score <= 10*(i))
                {
                    z = 4;
                    score += 10;
                    i++;
                }

            }
            if (colision(player_sprite, sprite_platforn[0], colied, jump_height) == true &&z==4)
            {

                if (score <= 10*(i))
                {
                    z = 5;
                    score += 10;
                    i++;
                }
            }
            if (player_sprite.getPosition().y + 40 == sprite_platforn[1].getPosition().y && z ==5)
            {

                if (score >= 10*(i-1))
                {
                    z = 4;
                    score -= 10;
                    i--;
                }
            }

            else if (player_sprite.getPosition().y + 40 == sprite_platforn[0].getPosition().y && z == 1)
            {

                if (score >= 10*(i - 1))
                {
                    z = 5;
                    score -= 10;
                    i--;
                }
            }

            else if (player_sprite.getPosition().y + 40 == sprite_platforn[4].getPosition().y && z == 2)
            {

                if (score >= 10*(i - 1))
                {
                    z = 1;
                    score -= 10;
                    i--;
                }
            }

            else if (player_sprite.getPosition().y + 40 == sprite_platforn[3].getPosition().y && z == 3)
            {

                if (score >= 10*(i - 1))
                {
                    z = 2;
                    score -= 10;
                    i--;
                }
            }

            else if (player_sprite.getPosition().y + 40 == sprite_platforn[2].getPosition().y && z == 4)
            {

                if (score >= 10*(i - 1))
                {
                    z = 3;
                    score -= 10;
                    i--;
                }
            }

            platform_gravity(sprite_platforn[0],score, colied);
            platform_gravity(sprite_platforn[1],score, colied);
            platform_gravity(sprite_platforn[2],score, colied);
            platform_gravity(sprite_platforn[3],score, colied);
            platform_gravity(sprite_platforn[4],score, colied);
            opject_player.gravity(player_sprite, 500, gravity, colied);
            if (player_sprite.getPosition().y>=500)
            {
                lse.play();
                player_lose(window, music, open, volume, high, low, m, carc, lse, jump, volume_s, high_s, low_s,score,800,500);
            }


            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case  Event::Closed:
                    window.close();
                    break;

                case Event::KeyReleased:

                    rect.left = 0;
                    player_sprite.setTextureRect(rect);
                    break;
                case Event::KeyPressed:
                    if (Keyboard::isKeyPressed(Keyboard::Key::Space))
                        jump.play();


                }
                if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
                {
                    pause = true;
                }


            }
            window.draw(sprite);
            for (int i = 0; i < 5; i++)
            {
                window.draw(sprite_platforn[i]);
            }

            window.draw(back);
            window.draw(player_sprite);
            window.draw(txt);
            window.display();
        }




        else
        {

            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case  Event::Closed:
                    window.close();
                    break;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
                {
                    moveup(pauseselected,Pause);

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
                {
                    movedown(pauseselected,Pause);

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
                {
                    if (pauseselected == 0)
                    {
                        pause = false;
                    }

                    if (pauseselected == 1)
                    {
                        men(window, music, open, volume, high, low, m, carc, lse,jump,volume_s,high_s,low_s);
                        m = true;
                    }
                }

            }

            for (int i = 0; i < 2; i++)
            {
                window.draw(Pause[i]);
            }
            window.display();
        }
    }
}






bool colision(Sprite& player_sprite, Sprite& platform_sprite, bool colision, int& jump_hieght)
{
    if (player_sprite.getPosition().x >= platform_sprite.getPosition().x &&
            player_sprite.getPosition().x <= platform_sprite.getPosition().x + 250 &&
            player_sprite.getPosition().y + 40 == platform_sprite.getPosition().y)
    {
        colision = true;
        jump_hieght = 0;


    }


    else
    {
        colision = false;
    }


    return colision;

}
void platform_gravity(Sprite& platform_sprite, int score,bool contact)
{



    if (platform_sprite.getPosition().y > 500)
    {
        platform_sprite.setPosition(platform_sprite.getPosition().x + 75, 0);

    }
    if (platform_sprite.getPosition().x + 200 > 693)
    {
        platform_sprite.setPosition(120, platform_sprite.getPosition().y);
    }
    /*if (score>100)
        contact =true;*/
   if (contact == true)
        //for(int i=0 ; i<2;i++)
        platform_sprite.move(0,1);



}
void player_lose(RenderWindow& window, Music& music, bool& open, int& volume, int& high, int& low,bool& m, bool& carc, Music& lse, Music& jump, int& volume_s, int& high_s, int& low_s,int lose, int width,int hight)
{

    Event event;
    //frist_line
    Font font_lose;
    font_lose.loadFromFile("Blackbird.ttf");
    Text lose_line[2];
    lose_line[0].setOrigin(300,70);
    lose_line[0].setFont(font_lose);
    lose_line[0].setFillColor(sf::Color::Red);
    lose_line[0].setString("Sorry ! You are lose");
    lose_line[0].setCharacterSize(70);
    lose_line[0].setOutlineThickness(4);
    lose_line[0].setOutlineColor(sf::Color::Black);
    lose_line[0].setPosition(sf::Vector2f( width/2,0));
    //secound_line
    lose_line[1].setOrigin(300,70);
    lose_line[1].setFont(font_lose);
    lose_line[1].setFillColor(sf::Color::Red);
    lose_line[1].setString("Enter Your Name : ");
    lose_line[1].setCharacterSize(50);
    lose_line[1].setOutlineThickness(4);
    lose_line[1].setOutlineColor(sf::Color::Black);
    lose_line[1].setPosition(sf::Vector2f( width/2, hight/5*3));
    //username_frist_letter
    char user_name[]= {'_','_','_'};

    sf::Text username;
    username.setFont(font_lose);
    username.setCharacterSize(45);
    username.setFillColor(sf::Color::Yellow);
    username.setPosition(400, 400);
    //username_second_letter
    sf::Text username_1;
    username_1.setFont(font_lose);
    username_1.setCharacterSize(45);
    username_1.setFillColor(sf::Color::Yellow);
    username_1.setPosition(400+50, 400);
    //username_third_letter
    sf::Text username_2;
    username_2.setFont(font_lose);
    username_2.setCharacterSize(45);
    username_2.setFillColor(sf::Color::Yellow);
    username_2.setPosition(400+100, 400);
    //score
    sf::Text score ;
    score.setFont(font_lose);
    score.setCharacterSize(45);
    score.setFillColor(sf::Color::Yellow);
    score.setPosition(300, 300);
    score.setString("SCORE : ");

    //score
    int i=0;
    string c;
    stringstream sco;
    sco << c << lose;


    sf::Text score_fact ;
    score_fact.setFont(font_lose);
    score_fact.setCharacterSize(45);
    score_fact.setFillColor(sf::Color::Yellow);
    score_fact.setPosition(300+200, 300);
    score_fact.setString(sco.str());


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {

            switch (event.type)
            {
            case  Event::Closed:
                window.close();
                break;
            case  Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
                {
                    i++;
                    cout<<i<<"ss"<<endl;
                }

                break;
            }
        }


        if (Keyboard::isKeyPressed(Keyboard::Key::A))
        {
            user_name[i]='A';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::B))
        {
            user_name[i]='B';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::C))
        {
            user_name[i]='C';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D))
        {
            user_name[i]='D';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::E))
        {
            user_name[i]='E';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::F))
        {
            user_name[i]='F';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::G))
        {
            user_name[i]='G';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::H))
        {
            user_name[i]='H';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::I))
        {
            user_name[i]='I';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::J))
        {
            user_name[i]='J';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::K))
        {
            user_name[i]='K';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::L))
        {
            user_name[i]='L';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::M))
        {
            user_name[i]='M';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::N))
        {
            user_name[i]='N';
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::O))
        {
            user_name[i]='O';
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::P))
        {
            user_name[i]='P';
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::Q))
        {
            user_name[i]='Q';
        }
        if(Keyboard::isKeyPressed(Keyboard::Key::R))
        {
            user_name[i]='R';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S))
        {
            user_name[i]='S';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::T))
        {
            user_name[i]='T';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::U))
        {
            user_name[i]='U';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::V))
        {

            user_name[i]='V';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::W))
        {
            user_name[i]='W';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::X))
        {
            user_name[i]='X';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Y))
        {
            user_name[i]='Y';
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Z))
        {
            user_name[i]='Z';
        }

        if(lose_line[0].getPosition().y<=(hight/5*2))
        {
            lose_line[0].move(0,.2);
        }
        if(i>=3)
        men(window, music, open, volume, high, low, m, carc, lse, jump, volume_s, high_s, low_s);





        username.setString(user_name[0]);
        username_1.setString(user_name[1]);
        username_2.setString(user_name[2]);



        window.clear();
        window.draw(lose_line[0]);
        window.draw(lose_line[1]);
        window.draw(score);
        window.draw(username);
        window.draw(username_1);
        window.draw(username_2);
        window.draw(score_fact);
        window.display();

    }
}



void opt(RenderWindow& window,Music& music, bool& open,int&volume, int& high, int& low,bool& m,bool& carc, Music& lse, Music& jump, int& volume_s, int& high_s, int& low_s)
{

    Texture carc1;
    carc1.loadFromFile("Images_project/a.png");
    Texture carc2;
    carc2.loadFromFile("Images_project/b.png");
    Sprite car;
    if (carc == false)
    {
        car.setTexture(carc1);
    }
    else
    {
        car.setTexture(carc2);
    }
    car.setPosition(500, 350);
    sf::Texture text;
    text.loadFromFile("Images_project/menu.png");
    sf::Sprite s;
    s.setTexture(text);
    Option opton(800, 500);
    ostringstream muic[2];
    muic[0] << "Music " << volume;
    muic[1] << "Sound " << volume_s;
    Text op[2];
    Font font;
    font.loadFromFile("Blackbird.ttf");
    op[0].setFont(font);
    op[0].setFillColor(sf::Color::Blue);
    op[0].setString(muic[0].str());
    op[0].setCharacterSize(70);
    op[0].setOutlineThickness(4);
    op[0].setOutlineColor(sf::Color::Black);
    op[0].setPosition(sf::Vector2f(800 / 2 - 375, 500 / (option + 1) + 120));
    op[1].setFont(font);
    op[1].setFillColor(sf::Color::Blue);
    op[1].setString(muic[1].str());
    op[1].setCharacterSize(70);
    op[1].setOutlineThickness(4);
    op[1].setOutlineColor(sf::Color::Black);
    op[1].setPosition(sf::Vector2f(800 / 2 - 375, 500 / (option + 2) + 200));
    m = true;
    while(window.isOpen())
    {

        Event event;
        muic[0].str("");
        muic[0] << "Music " << volume;
        op[0].setString(muic[0].str());
        muic[1].str("");
        muic[1] << "Sound " << volume_s;
        op[1].setString(muic[1].str());
        jump.setVolume(volume_s);
        music.setVolume(volume);

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)/*|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)*/)
                {
                    men(window, music, open, volume, high, low, m, carc, lse, jump, volume_s, high_s, low_s);
                }
            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                opton.moveup();

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                opton.movedown();

            }


            if (opton.optionselect == 0)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    if (volume <= 10*(high) - 1 && volume < 100)
                    {
                        volume += 10;
                        high++;
                        low = high - 2;
                    }
                    music.setVolume(volume);
                    lse.setVolume(volume);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                {
                    if (volume >= 10*(low) + 1 && volume > 0)
                    {
                        volume -= 10;
                        low--;
                        high = low + 2;
                    }
                    music.setVolume(volume);
                    lse.setVolume(volume);
                }
            }
            if (opton.optionselect == 1)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    if (volume_s <= 10 * (high_s)-1 && volume_s < 100)
                    {
                        volume_s += 10;
                        high_s++;
                        low_s = high_s - 2;
                    }
                    jump.setVolume(volume_s);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                {
                    if (volume_s >= 10 * (low_s)+1 && volume_s > 0)
                    {
                        volume_s -= 10;
                        low_s--;
                        high_s = low_s + 2;
                    }
                    jump.setVolume(volume_s);
                }
            }

            if (opton.optionselect == 2)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    if (car.getTexture())
                    {
                        car.setTexture(carc2);
                        carc = true;
                    }

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                {
                    if (car.getTexture())
                    {
                        car.setTexture(carc1);
                        carc = false;
                    }
                }
            }


        }

        window.clear();
        window.draw(s);
        for (int i = 0; i < 2; i++)
        {
            window.draw(op[i]);
        }
        window.draw(car);
        opton.Draw(window);
        window.display();

    }


}

void men(RenderWindow& window, Music& music,bool& open, int& volume,int&high,int&low,bool& m, bool& carc, Music& lse, Music& jump, int& volume_s, int& high_s, int& low_s)
{

    if (m == true)
    {
        lse.stop();
        music.play();
    }
    sf::Texture text;
    text.loadFromFile("Images_project/menu.png");
    sf::Sprite s;
    s.setTexture(text);
    music.setVolume(volume);
    Menu menu(800,500);
    while (window.isOpen())
    {


        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
                {
                    if (menu.menuselected == 0)
                    {
                        //  if (open == true)
                        play(window, music, open, volume, high, low, m, carc, lse, jump, volume_s, high_s, low_s);

                    }
                    if (menu.menuselected == 1)
                    {
                        opt(window, music, open, volume, high, low, m, carc, lse, jump, volume_s, high_s, low_s);
                    }
                    if (menu.menuselected == 2)
                    {
                          window.close();
                    }

                    if (menu.menuselected == 3)
                    {
                                                  //Highscore(window, music, open, volume, high, low, m, carc, lse, jump, volume_s, high_s, low_s);

                    }

                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            {
                menu.moveup();

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            {
                menu.movedown();

            }
        }



        window.clear();
        window.draw(s);
        menu.Draw(window);
        window.display();
    }
}
void moveup(int& menuselected,Text main[])
{
    //Text main[3];
    if (menuselected - 1 >= -1)
    {
        main[menuselected].setFillColor(sf::Color::Black);

        menuselected--;
        if (menuselected == -1)
        {
            menuselected = 2;
        }
        main[menuselected].setFillColor(sf::Color::Red);

    }

}

void movedown(int& menuselected,Text main[])
{
    // Text main[3];
    if (menuselected + 1 <= 3)
    {
        main[menuselected].setFillColor(sf::Color::Black);

        menuselected++;
        if (menuselected == 3)
        {
            menuselected = 0;
        }
        main[menuselected].setFillColor(sf::Color::Red);

    }
}













