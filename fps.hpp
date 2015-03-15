#include <string>

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace Fastcraft
{

	class Fps
	{
		float x, y;
		Clock fpsclock;
	public:
		void setPosition(float m_x, float m_y);
		string toString();

	private:
		float getFPS(const Time &time);
	};

}
