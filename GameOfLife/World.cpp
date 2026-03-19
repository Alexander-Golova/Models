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
				continue;

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
	if ((x >= 0) && (y >= 0) && (x <= m_width) && (y << m_height))
	{
		m_cellMap[x][y] = true;
	}
}
