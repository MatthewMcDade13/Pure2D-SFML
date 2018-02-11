#pragma once

#include <random>

namespace pure
{
	class Random
	{
	public:
		Random();
		~Random();

		double operator()(float min, float max);
		int operator()(int min, int max);

	private:
		std::random_device m_rd;
		std::mt19937 m_mez;
	};
}



