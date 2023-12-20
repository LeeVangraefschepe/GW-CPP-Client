#include "ClientNetwork.h"

#include <iostream>

#include "BaseBenchmark.h"
#include "Leap/LeapPacket.h"
#include "../Packets/JsonPacket.h"
#include "Benchmarker.h"
#include "Json.h"
#include <ImGui/imgui.h>

unag::ClientNetwork::ClientNetwork()
{
    m_Client.Run();
    m_Client.SendUDP(leap::networking::BasePacket{});
    
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

void unag::ClientNetwork::OnGUI()
{
    benchmark::Json benchmarker{};

    ImGui::Begin("Benchmarking");
    if (ImGui::Button("Chunk", ImVec2{200,30}))
    {
        std::cout << "\n\nBenchmarking chunk:\n";
        benchmarker.FullChunk();
    }
    if (ImGui::Button("Input", ImVec2{ 200,30 }))
    {
        std::cout << "\n\nBenchmarking input:\n";
        benchmarker.Input();
    }
    if (ImGui::Button("BlockUpdate", ImVec2{ 200,30 }))
    {
        std::cout << "\n\nBenchmarking block update:\n";
        benchmarker.BlockUpdate();
    }
    ImGui::End();
}
