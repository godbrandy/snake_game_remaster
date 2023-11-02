#pragma once
#include "Graphics.h"
#include "Location.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth() const { return width; };
	int GetGridHeight() const { return height; };
	bool IsInsideBoard(const Location& loc) const;
private:
	Graphics& gfx;
	static constexpr int dimension{ 20 };
	const int width;
	const int height;
};