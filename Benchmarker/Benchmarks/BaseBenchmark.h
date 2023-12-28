#pragma once
#include <iostream>

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
				std::cout << "No benchmark for incoming packet defined\n";
				return 0;
			}
		}

	protected:
		virtual double FullChunk(T& packet) = 0;
		virtual void FullChunk() = 0;
		virtual double Input(T& packet) = 0;
		virtual void Input() = 0;
		virtual double BlockUpdate(T& packet) = 0;
		virtual void BlockUpdate() = 0;
		virtual double PlayerUpdate(T& packet) = 0;
		virtual void PlayerUpdate() = 0;
		virtual double PlayerJoin(T& packet) = 0;
		virtual void PlayerJoin() = 0;
		virtual double ChatMessage(T& packet) = 0;
		virtual void ChatMessage() = 0;
	};
}
