#include "World.h"

CWorld::CWorld(size_t height, size_t width)
	: m_height(height)
	, m_width(width)
	, m_cellMap(height, std::vector<bool>(width, false))
{};

size_t CWorld::CalculateNeighbors(const size_t row, size_t col) const
{
	size_t count = 0;
	const size_t startRow = (row > 0) ? row - 1 : 0;
	const size_t startCol = (col > 0) ? col - 1 : 0;
	const size_t endRow = (row + 1 < m_height) ? row + 1 : m_height - 1;
	const size_t endCol = (col + 1 < m_width) ? col + 1 : m_width - 1;

	for (size_t i = startRow; i <= endRow; ++i)
	{
		for (size_t j = startCol; j <= endCol; ++j)
		{
			if (i == row && j == col)
			{
				continue;
			}

			if (m_cellMap[i][j])
			{
				++count;
			}
		}
	}
	return count;
}

void CWorld::SetLife(size_t x, size_t y)
{
	if ((x < m_width) && (y < m_height))
	{
		m_cellMap[x][y] = true;
	}
}

void CWorld::NextGeneration()
{
	std::vector<std::vector<bool>> newCellMap(m_height, std::vector<bool>(m_width, false));	

	for (size_t row = 0; row < m_width; ++row)
	{
		for (size_t col = 0; col < m_height; ++col)
		{
			if (CalculateNeighbors(row, col) == 3)
			{
				newCellMap[row][col] = true;
			}
			if (CalculateNeighbors(row, col) == 2 && m_cellMap[row][col])
			{
				newCellMap[row][col] = true;
			}
			if (CalculateNeighbors(row, col) < 2 || CalculateNeighbors(row, col) > 3)
			{
				newCellMap[row][col] = false;
			}
		}
	}
	m_cellMap = newCellMap;
}
