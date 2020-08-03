#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetBoardWidth();
	int GetBoardHeight();
	bool IsInsideBoard(const Location loc) const;
	void DrawBorder();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int dimension = 20;
	static constexpr int width = 35;
	static constexpr int height = 25;
	static constexpr int cellPadding = 1;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 45;
	static constexpr int y = 45;

	Graphics& gfx;
};