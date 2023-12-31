#pragma once
#include "BaseBenchmark.h"
#include "../Packets/JsonPacket.h"

namespace unag::benchmark
{
	class Json final : public BaseBenchmark<networking::JsonPacket>
	{
	public:
		Json() = default;
		virtual ~Json() = default;
		Json(const Json& other) = delete;
		Json(Json&& other) = delete;
		Json& operator=(const Json& other) = delete;
		Json& operator=(Json&& other) = delete;

		void FullChunk() override;
		void Input() override;
		void BlockUpdate() override;
		void PlayerUpdate() override;
		void PlayerJoin() override;
		void ChatMessage() override;

	private:
		double FullChunk(networking::JsonPacket& packet) override;
		double Input(networking::JsonPacket& packet) override;
		double BlockUpdate(networking::JsonPacket& packet) override;
		double PlayerUpdate(networking::JsonPacket& packet) override;
		double PlayerJoin(networking::JsonPacket& packet) override;
		double ChatMessage(networking::JsonPacket& packet) override;
	};
}