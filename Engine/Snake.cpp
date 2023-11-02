#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (size_t i{ segments.size() - 1 }; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l{ segments[0].GetLocation() };
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	segments.emplace_back();
	segments[segments.size() - 1].InitBody();
}

void Snake::Draw(Board& brd) const
{
	for (size_t i{ 0 }; i < segments.size(); i++)
	{
		segments[i].Draw(brd);
	}
}

bool Snake::IsInTile(const Location& target) const
{
	for (size_t i{ 0 }; i < segments.size() - 1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& loc)
{
	this->loc = loc;
	c = Snake::head_color;
}

void Snake::Segment::InitBody()
{
	std::uniform_int_distribution<int> green_dist{ 65, 255 };
	std::mt19937 rnd{ std::random_device()() };
	Color body_color( 0, green_dist(rnd), 0 );
	c = body_color;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert((abs(delta_loc.x) + abs(delta_loc.y)) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
