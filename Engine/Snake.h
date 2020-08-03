#pragma once

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);		// get head location
		void InitBody( Color c_in);					// 
		void Follow( const Segment& next);			// to follow next segment 	
		void MoveBy(const Location& delta_loc);		// for head location
		void Draw(Board& brd) const;		
		Location GetLocation() const;
	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);						// initialize head
	void MoveBy( const Location& delta_loc);		// for head movement
	void Grow();									// call when snake grow
	void Draw(Board& brd) const;					
	Location GetNextHeadLocation(const Location& delta_loc);
	bool IsInTileExceptEnd(const Location& next) const;
	bool IsInTile(const Location& next) const;
private:
	static constexpr Color HeadColor = Colors::White;
	static constexpr int nSegmentMax = 100;
	Segment segments[nSegmentMax];
	int nSegments = 1;
};