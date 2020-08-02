#pragma once

struct Location
{
public:
	void Add(const Location& loc)
	{
		x += loc.x;
		y += loc.y;
	}
	int x;
	int y;
};