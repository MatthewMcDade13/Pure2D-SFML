#pragma once

#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "Printable.h"
#include "VecToString.h"

namespace pure
{
	namespace debug
	{
		// prints given arg to stdout
		template <typename T>
		typename std::enable_if<std::is_integral<T>::value>::type print(const T& s) 
		{ std::cout << s; }

		template <typename T>
		typename std::enable_if<std::is_floating_point<T>::value>::type print(const T& s) 
		{ std::cout << s; }

		template<typename T>
		void print(const sf::Vector2<T>& vec) { std::cout << (vecToString(vec)); }

		inline void print(const Printable& obj) { std::cout << (obj.toString()); }

		inline void print(const char* s) { std::cout << s; }

		// sends newline and flushes stdout
		inline void cLog() { std::cout << std::endl; }

		// prints all args to stdout and then flushes it
		template <typename T, typename... Args>
		void cLog(const T& s, const Args&... args)
		{
			print(s);
			cLog(args...);
		}
	}
}

#ifndef NDEBUG
#define dbLog(...) pure::debug::cLog(__VA_ARGS__)
#else
#define dbLog(...)
#endif


