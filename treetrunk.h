#ifndef TREETRUNK_H_INCLUDED
#define TREETRUNK_H_INCLUDED

enum class TreeTrunkDirection
{
	Left,
	Right
};

struct TreeTrunk
{
    TreeTrunk( SDL_Rect pos_, int speed_, TreeTrunkDirection dir_)
    {
        pos = pos_;
        speed = speed_;
        dir = dir_;
    }

    SDL_Rect pos;
    int speed;
    TreeTrunkDirection dir;
};

std::vector< TreeTrunk > treetrunks;

#endif // TREETRUNK_H_INCLUDED
