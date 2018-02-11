#include "stdafx.h"
#include "Random.h"

using namespace pure; using namespace std;

Random::Random():
	m_rd(),
	m_mez(m_rd())
{
}


Random::~Random()
{
}

double Random::operator()(float min, float max)
{
	uniform_real_distribution<> rand(min, max);
	return rand(m_mez);
}

int Random::operator()(int min, int max)
{
	uniform_int_distribution<> rand(min, max);
	return rand(m_mez);
}
