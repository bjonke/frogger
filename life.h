#ifndef LIFE_H_INCLUDED
#define LIFE_H_INCLUDED

enum class lifeDirection
{
	Left,
	Right
};

struct Life
{
    Life( SDL_Rect pos_, int speed_, lifeDirection dir_)
    {
        pos = pos_;
        speed = speed_;
        dir = dir_;
    }

    SDL_Rect pos;
    int speed;
    lifeDirection dir;
};

std::vector< Life > lives;

#endif // LIFE_H_INCLUDED
