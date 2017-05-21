#include "Rock.h"

void Rock::Draw( Board& brd ) const
{
	if( isSpawned )
	{
		brd.DrawCell( loc,c );
	}
}

void Rock::Respawn( std::mt19937& rng,const Board& brd,const Snake& snake )
{
	std::uniform_int_distribution<int> xDist( 0,brd.GetGridWidth() - 1 );
	std::uniform_int_distribution<int> yDist( 0,brd.GetGridHeight() - 1 );

	Location newLoc;
	do
	{
		newLoc.x = xDist( rng );
		newLoc.y = yDist( rng );
	} while( snake.IsInTile( newLoc ) );

	loc = newLoc;
}

const Location& Rock::GetLocation() const
{
	return loc;
}

void Rock::SetSpawned( bool value )
{
	isSpawned = value;
}
