#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

enum class EnemyDirection
{
	Left,
	Right
};

struct Enemy
{
	Enemy( SDL_Rect pos_, int speed_, EnemyDirection dir_ )
	{
		pos = pos_;
		speed = speed_;
		dir = dir_;
	}

	SDL_Rect pos;
	int speed;
	EnemyDirection dir;
};

std::vector< Enemy > enemies;

int AddEnemy(int lastEnemyPosition)
{
	if ( ( rand() % 2 ) == 0 )
	{
		enemies.push_back( Enemy( { rand() % 300, lastEnemyPosition, 20, 20 }, 1, EnemyDirection::Right )  );
	}
	else
	{
		enemies.push_back( Enemy( { rand() % 300, lastEnemyPosition, 20, 20 }, 1, EnemyDirection::Left )  );
	}

	lastEnemyPosition += 25;

	return lastEnemyPosition;
}

#endif // ENEMY_H_INCLUDED
