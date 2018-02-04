#pragma once

#include <thread>
#include <vector>
#include <future>
#include <atomic>


template <typename F>
void parallelFor(int begin, int end, F func)
{
	using namespace std;

	int numThread = thread::hardware_concurrency();
	vector<future<void>> futures(numThread);
	atomic<int> offset;
	offset = begin;

	for (size_t i = 0; i < futures.size(); i++)
	{
		futures[i] = async(launch::async,
			[i, &offset, end, &func]() {
			while (true)
			{
				int ind = offset++;
				if (ind >= end) break;
				func(ind);
			}
		});
	}

	for (size_t i = 0; i < futures.size(); i++)
	{
		futures[i].get();
	}

}