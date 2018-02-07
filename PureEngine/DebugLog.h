#pragma once

#include <iostream>

namespace pure
{
	// prints given arg to stdout
	template <typename T>
	void print(const T& s)
	{
		std::cout << s;
	}

	// sends newline and flushes stdout
	void cLog() { std::cout << std::endl; }

	// prints all args to stdout and then flushes it
	template <typename T, typename... Args>
	void cLog(const T& s, const Args&... args)
	{
		print(s);
		cLog(args...);
	}
}

#ifndef NDEBUG
#define dbLog(...) pure::cLog(__VA_ARGS__)
#else
#define dbLog(...)
#endif
