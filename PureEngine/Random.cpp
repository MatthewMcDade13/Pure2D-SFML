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

float Random::operator()(float min, float max) const
{
	uniform_real_distribution<> rand(min, max);
	return (float)rand(m_mez);
}

float Random::operator()(float max) const
{
	uniform_real_distribution<> rand(0, max);
	return (float)rand(m_mez);
}

double Random::operator()(double min, double max) const
{
	uniform_real_distribution<> rand(min, max);
	return rand(m_mez);
}

double Random::operator()(double max) const
{
	uniform_real_distribution<> rand(0, max);
	return rand(m_mez);
}


int Random::operator()(int min, int max) const
{
	uniform_int_distribution<> rand(min, max);
	return rand(m_mez);
}

int Random::operator()(int max) const
{
	uniform_int_distribution<> rand(0, max);
	return rand(m_mez);
}
