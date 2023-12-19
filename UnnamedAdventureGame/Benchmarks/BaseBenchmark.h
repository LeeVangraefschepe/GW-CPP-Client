#pragma once
#include "Debug.h"

namespace unag::benchmark
{
	template <class T>
	class BaseBenchmark
	{
	public:
		double TestPacket(int id, T& packet)
		{
			switch (id)
			{
			case 20:
				return FullChunk(packet);
			default:
				leap::Debug::LogWarning("No benchmark for incoming packet defined");
				return 0;
			}
		}

	protected:
		virtual double FullChunk(T& packet) = 0;
	};
}
