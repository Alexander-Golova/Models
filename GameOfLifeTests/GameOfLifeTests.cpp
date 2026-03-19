#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <catch/catch.hpp>

#include "../GameOfLife/World.h"

SCENARIO("World", "[world]")
{
	GIVEN("Creating the world")
	{
		// Создаём пустой мир
		CWorld world(4, 4);
		// ни у одной клетки нет соседей
		WHEN("No one has any neighbors")
		{
			CHECK(world.CalculateNeighbors(2, 2) == 0);
			CHECK(world.CalculateNeighbors(0, 0) == 0);
			CHECK(world.CalculateNeighbors(3, 3) == 0);
		}
		// добавляем живую клетку
		WHEN("Adding a live cell")
		{
			world.SetLife(2, 2);
			CHECK(world.CalculateNeighbors(2, 1) == 1);
			CHECK(world.CalculateNeighbors(1, 2) == 1);
			CHECK(world.CalculateNeighbors(1, 1) == 1);

			world.SetLife(2, 1);
			CHECK(world.CalculateNeighbors(2, 1) == 1);
			CHECK(world.CalculateNeighbors(1, 2) == 2);
			CHECK(world.CalculateNeighbors(1, 1) == 2);

			world.SetLife(2, 0);
			CHECK(world.CalculateNeighbors(1, 1) == 3);
		}
	}
	// создаём новое поколение
	GIVEN("Creating a new generation")
	{
		CWorld world(3, 3);	
		// добавляем живые клетки
		WHEN("Adding live cells")
		{
			world.SetLife(1, 0);
			world.SetLife(1, 1);
			world.SetLife(1, 2);
			CHECK(world.CalculateNeighbors(0, 0) == 2);
			CHECK(world.CalculateNeighbors(0, 1) == 3);
			CHECK(world.CalculateNeighbors(0, 2) == 2);
			CHECK(world.CalculateNeighbors(1, 0) == 1);
			CHECK(world.CalculateNeighbors(1, 1) == 2);
			CHECK(world.CalculateNeighbors(1, 2) == 1);
			CHECK(world.CalculateNeighbors(2, 0) == 2);
			CHECK(world.CalculateNeighbors(2, 1) == 3);
			CHECK(world.CalculateNeighbors(2, 2) == 2);			
			
			THEN("A new generation can be generated")
			{
				world.NextGeneration();
				CHECK(world.CalculateNeighbors(0, 0) == 2);
				CHECK(world.CalculateNeighbors(0, 1) == 1);
				CHECK(world.CalculateNeighbors(0, 2) == 2);
				CHECK(world.CalculateNeighbors(1, 0) == 3);
				CHECK(world.CalculateNeighbors(1, 1) == 2);
				CHECK(world.CalculateNeighbors(1, 2) == 3);
				CHECK(world.CalculateNeighbors(2, 0) == 2);
				CHECK(world.CalculateNeighbors(2, 1) == 1);
				CHECK(world.CalculateNeighbors(2, 2) == 2);	

			}
		}
	}
}
