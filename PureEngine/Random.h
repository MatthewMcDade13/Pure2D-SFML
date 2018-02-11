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
		float operator()(float min, float max) const;
		// Gets a random real number between 0 and given max.
		float operator()(float max) const;

		// Gets a random real number between given min and max.
		double operator()(double min, double max) const;
		// Gets a random real number between 0 and given max.
		double operator()(double max) const;

		// Gets a random integer between given min and max.
		int operator()(int min, int max) const;
		// Gets a random integer between 0 and given max.
		int operator()(int max) const;

	private:
		std::random_device m_rd;
		mutable std::mt19937 m_mez;
	};
}



