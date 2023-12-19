#pragma once
#include "Components/Component.h"
#include "Leap/LeapClient.h"

namespace unag
{
	class ClientNetwork final : public leap::Component
	{
	public:
		ClientNetwork();
		virtual ~ClientNetwork() = default;
		ClientNetwork(const ClientNetwork& other) = delete;
		ClientNetwork(ClientNetwork&& other) = delete;
		ClientNetwork& operator=(const ClientNetwork& other) = delete;
		ClientNetwork& operator=(ClientNetwork&& other) = delete;
	private:
		virtual void Update() override;
		virtual void OnGUI() override;

		inline static constexpr int MAX_BUFFER = 65535;
		leap::networking::LeapClient m_Client{ 7777, "127.0.0.1", MAX_BUFFER, 20 };
	};
}
