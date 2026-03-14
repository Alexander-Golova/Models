#include "World.h"

CWorld::CWorld(size_t height, size_t width)
	: m_height(height)
	, m_width(width)
{
	std::vector<std::vector<bool>> m_cellMap(height, std::vector<bool>(width, false));
};

size_t CWorld::CalculateNeighbors(const size_t row, size_t col) const
{
	size_t count = 0;
	for (size_t i = row - 1; i <= row + 1; ++i)
	{
		for (size_t j = col - 1; j <= col + 1; ++j)
		{
			if ((i != row || j != col) && m_cellMap[i][j])
			{
				++count;
			}
		}
	}
	return count;
}
