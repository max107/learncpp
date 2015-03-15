#include <sstream>

#include "fps.hpp"

namespace Fastcraft
{

	void Fps::setPosition(float m_x, float m_y)
	{
		x = m_x;
		y = m_y;
	}

	string Fps::toString()
	{
		// set the string to display
		float fps = getFPS(fpsclock.restart());
		std::stringstream ss;
		ss.str("");
		ss << fps;
		return ss.str();
	}

	float Fps::getFPS(const Time &time)
	{
		return (1000000.0f / time.asMicroseconds());
	}

}
