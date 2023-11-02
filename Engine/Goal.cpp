#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	Respawn(rng, brd, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	std::uniform_int_distribution<int> x_dist{ 0, brd.GetGridWidth() - 1 };
	std::uniform_int_distribution<int> y_dist{ 0, brd.GetGridHeight() - 1 };

	Location new_loc{};
	do
	{
		new_loc.x = x_dist(rng);
		new_loc.y = y_dist(rng);
	} while (snake.IsInTile(new_loc));

	loc = new_loc;

}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const
{
	return loc;
}
