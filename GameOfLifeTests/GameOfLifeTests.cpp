#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include "../GameOfLife/World.h"

SCENARIO("World", "[world]")
{
	GIVEN("Creating the world")
	{
		// Создаём пустой мир
		CWorld world(4, 4);
		// ни у одной клетуи нет соседей
		WHEN("No one has any neighbors.")
		{
			CHECK(world.CalculateNeighbors(2, 2) == 0);
			CHECK(world.CalculateNeighbors(0, 0) == 0);
			CHECK(world.CalculateNeighbors(3, 3) == 0);
		}
	}
}
