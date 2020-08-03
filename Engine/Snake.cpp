#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	constexpr int nBodyColor = 4;
	constexpr Color bodyColors[] = {
		{10,130,32},
		{10,150,48},
		{10,180,48},
		{10,130,48}
	};

	for (int i = 0; i < nSegmentMax; i++) {
		segments[i].InitBody(bodyColors[i % nBodyColor]);	
	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if(nSegments < nSegmentMax)
	{
		++nSegments;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadLocation(const Location& delta_loc)
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

bool Snake::IsInTileExceptEnd(const Location& next) const
{
	for (int i = 0; i < nSegments - 1 ; i++)
	{
		if (segments[i].GetLocation() == next)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTile(const Location& next) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == next)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::HeadColor;
}

void Snake::Segment::InitBody(Color c_in)
{
	c = c_in;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

Location Snake::Segment::GetLocation() const
{
	return loc;
}
