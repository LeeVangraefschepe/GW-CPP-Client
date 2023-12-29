#include "BaseBenchmark.h"
#include <string>

namespace unag::benchmark
{
	class Proto final : public BaseBenchmark<std::string>
	{
	public:
		Proto() = default;
		virtual ~Proto() = default;
		Proto(const Proto& other) = delete;
		Proto(Proto&& other) = delete;
		Proto& operator=(const Proto& other) = delete;
		Proto& operator=(Proto&& other) = delete;

		void FullChunk() override;
		void Input() override;
		void BlockUpdate() override;
		void PlayerUpdate() override;
		void PlayerJoin() override;
		void ChatMessage() override;

	private:
		double FullChunk(std::string& packet) override;
		double Input(std::string& packet) override;
		double BlockUpdate(std::string& packet) override;
		double PlayerUpdate(std::string& packet) override;
		double PlayerJoin(std::string& packet) override;
		double ChatMessage(std::string& packet) override;
	};
}