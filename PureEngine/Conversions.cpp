#include "stdafx.h"
#include "Conversions.h"
#include "Constants.h"

float pure::radians(float deg)
{
	return deg * (pure::PI / 180.f);
}

float pure::degress(float radians)
{
	return radians * (180.f / pure::PI);
}
