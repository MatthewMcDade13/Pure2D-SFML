#pragma once

#include "declspec.h"
#include <random>

namespace pure
{
	class PUREENGINE_API Random
	{
	public:
		Random();
		~Random();

		// Gets a random real number between given min and max.
		double operator()(float min, float max);
		// Gets a random real number between 0 and given max.
		double operator()(float max);

		// Gets a random integer between given min and max.
		int operator()(int min, int max);
		// Gets a random integer between 0 and given max.
		int operator()(int max);

	private:
		std::random_device m_rd;
		std::mt19937 m_mez;
	};
}



