#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

enum class CarDirection
{
	Left,
	Right
};

struct Car
{
	Car( SDL_Rect pos_, int speed_, CarDirection dir_ )
	{
		pos = pos_;
		speed = speed_;
		dir = dir_;
	}

	SDL_Rect pos;
	int speed;
	CarDirection dir;
};

std::vector< Car > cars;

#endif // CAR_H_INCLUDED
