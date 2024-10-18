#include <string>
#include <sstream>
#include "Point.h"


std::string point::Point::ToString() const
{
	std::stringstream buffer{};
	buffer << this->x << " " << this->y;

	return buffer.str();
}
