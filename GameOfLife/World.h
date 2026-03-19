#pragma once
#include <vector>



class CWorld
{
public:
	CWorld(size_t height, size_t width);
	size_t CalculateNeighbors(const size_t row, size_t col) const;

	void SetLife(size_t x, size_t y);

private:
	


	// Ширина и высота (в пикселях) ячейки
	size_t m_cellSize = 1;

	size_t m_height;
	size_t m_width;
	

	std::vector<std::vector<bool>> m_cellMap;	
	 
};
