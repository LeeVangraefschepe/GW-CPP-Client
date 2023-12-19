#pragma once
#include "BaseBenchmark.h"
#include "../Packets/JsonPacket.h"

namespace unag::benchmark
{
	class Json final : public BaseBenchmark<networking::JsonPacket>
	{
	public:
		Json() = default;
		~Json() = default;
		Json(const Json& other) = delete;
		Json(Json&& other) = delete;
		Json& operator=(const Json& other) = delete;
		Json& operator=(Json&& other) = delete;

		void FullChunk();

	private:
		double FullChunk(networking::JsonPacket& packet) override;
	};
}