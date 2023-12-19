#include "ClientNetwork.h"

#include <iostream>

#include "BaseBenchmark.h"
#include "Leap/LeapPacket.h"
#include "../Packets/JsonPacket.h"
#include "Benchmarker.h"
#include "Json.h"

unag::ClientNetwork::ClientNetwork()
{
    m_Client.Run();
    m_Client.SendUDP(leap::networking::BasePacket{});
    benchmark::Json benchmarker{};
    benchmarker.FullChunk();
}

void unag::ClientNetwork::Update()
{
	networking::JsonPacket recvPacket{};
    while (m_Client.GetPacket(recvPacket))
    {
	    const int id{ recvPacket.ReadHeaderId() };
        benchmark::Json benchmarker{};


        std::cout << "Received packet with id: " << id << "\n";
        const auto result = benchmarker.TestPacket(id, recvPacket);
        std::cout << "Average time to read out id: " << result << "ms\n\n";
    }
}