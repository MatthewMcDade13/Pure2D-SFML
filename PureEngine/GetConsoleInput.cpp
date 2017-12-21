#include "stdafx.h"
#include "GetConsoleInput.h"

using namespace std;

std::string pure::getConsoleInputstr(const std::string & message)
{
	string response;
	cout << message << ": ";
	cin >> response;
	return std::move(response);
}

bool pure::getConsoleInputb(const std::string & message, const std::string & errorMessage)
{
	string response = "";
	string responseCpy = "";

	while (true)
	{
		cout << message << " (y/n): ";
		cin >> response;
		cout << endl;
		responseCpy = response;

		if (responseCpy.compare("yes") != 0 &&
			responseCpy.compare("no") != 0 &&
			responseCpy.compare("n") != 0 &&
			responseCpy.compare("y") != 0)
		{
			if (errorMessage.size() != 0)
				cout << errorMessage << endl;
		}
		else
		{
			break;
		}
	}

	if (response.compare("yes") == 0 || response.compare("y") == 0)
		return true;

	return false;
}

int pure::getConsoleInputi(const std::string & message, const std::string & errorMessage)
{
	string response = "";
	bool bGoodParse = true;
	int result = 0;

	do
	{
		cout << message << ": ";
		cin >> response;
		cout << endl;

		try
		{
			result = std::stoi(response);
			bGoodParse = true;
		}
		catch (...)
		{
			bGoodParse = false;
			if (errorMessage.size() != 0)
				cout << errorMessage << endl;
		}

	} while (!bGoodParse);

	return result;
}

long pure::getConsoleInputl(const std::string & message, const std::string & errorMessage)
{
	string response = "";
	bool bGoodParse = true;
	long result = 0;

	do
	{
		cout << message << ": ";
		cin >> response;
		cout << endl;

		try
		{
			result = std::stol(response);
			bGoodParse = true;
		}
		catch (...)
		{
			bGoodParse = false;
			if (errorMessage.size() != 0)
				cout << errorMessage << endl;
		}

	} while (!bGoodParse);


	return result;
}

long long pure::getConsoleInputll(const std::string & message, const std::string & errorMessage)
{
	string response = "";
	bool bGoodParse = true;
	long long result = 0;

	do
	{
		cout << message << ": ";
		cin >> response;
		cout << endl;

		try
		{
			result = std::stoll(response);
			bGoodParse = true;
		}
		catch (...)
		{
			bGoodParse = false;
			if (errorMessage.size() != 0)
				cout << errorMessage << endl;
		}
	} while (!bGoodParse);


	return result;
}
