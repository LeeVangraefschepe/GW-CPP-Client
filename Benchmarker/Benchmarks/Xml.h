#pragma once
#include "BaseBenchmark.h"
#include "../Packets/XmlPacket.h"

namespace unag::benchmark
{
	class Xml final : public BaseBenchmark<networking::XmlPacket>
	{
	public:
		Xml() = default;
		virtual ~Xml() = default;
		Xml(const Xml& other) = delete;
		Xml(Xml&& other) = delete;
		Xml& operator=(const Xml& other) = delete;
		Xml& operator=(Xml&& other) = delete;

		void FullChunk() override;
		void Input() override;
		void BlockUpdate() override;
		void PlayerUpdate() override;
		void PlayerJoin() override;
		void ChatMessage() override;

	private:
		double FullChunk(networking::XmlPacket& packet) override;
		double Input(networking::XmlPacket& packet) override;
		double BlockUpdate(networking::XmlPacket& packet) override;
		double PlayerUpdate(networking::XmlPacket& packet) override;
		double PlayerJoin(networking::XmlPacket& packet) override;
		double ChatMessage(networking::XmlPacket& packet) override;
	};
}