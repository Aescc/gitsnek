#pragma once

#include "Board.h"
#include "Colors.h"
#include "Location.h"
#include "Snake.h"
#include <random>

class Rock
{
public:
	void Draw(Board& brd) const;
	void Respawn( std::mt19937& rng,const Board& brd,const Snake& snake );
	const Location& GetLocation() const;
	void SetSpawned( bool value );
private:
	Location loc;
	Color c =  Colors::LightGray;
	bool isSpawned = false;
};