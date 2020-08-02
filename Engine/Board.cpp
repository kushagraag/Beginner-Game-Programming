#include "Board.h"
#include <assert.h>
Board::Board(Graphics& gfx)
	:
	gfx( gfx )
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 20);
	assert(loc.x < width);
	assert(loc.y >= 20);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

int Board::GetBoardWidth()
{
	return width;
}

int Board::GetBoardHeight()
{
	return height;
}
