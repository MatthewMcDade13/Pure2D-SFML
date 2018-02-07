#pragma once

#include <string>

namespace pure
{
	class Printable
	{
	public:
		virtual ~Printable() { }

		virtual std::string toString() const = 0;
	};
}
