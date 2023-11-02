#include "Board.h"

Board::Board(Graphics& gfx)
	: gfx{ gfx },
	width{ gfx.ScreenWidth / dimension},
	height{ gfx.ScreenHeight /dimension}
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension - 3, dimension - 3, c);
}

bool Board::IsInsideBoard(const Location& loc) const
{
	return	loc.x >= 0 && 
			loc.x < width && 
			loc.y >= 0 && 
			loc.y < height;
}
