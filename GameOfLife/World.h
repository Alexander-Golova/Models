#pragma once
#include <vector>



class CWorld
{
public:
	CWorld(size_t height, size_t width);

private:
	size_t CalculateNeighbors(const size_t row, size_t col) const;


	// Ширина и высота (в пикселях) ячейки
	size_t m_cellSize = 1;

	size_t m_width;
	size_t m_height;

	std::vector<std::vector<bool>> m_cellMap;
	 
};
