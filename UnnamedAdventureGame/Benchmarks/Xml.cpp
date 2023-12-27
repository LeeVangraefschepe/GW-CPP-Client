#include "Xml.h"

#include <iostream>

#include "Benchmarker.h"
#include "vec3.hpp"

void unag::benchmark::Xml::FullChunk()
{
    constexpr glm::ivec3 chunkSize{ 16, 48, 16 };
    // Create a 3D vector and initialize all elements to 1
    std::vector value
    (
        chunkSize.x, std::vector
        (
            chunkSize.y, std::vector<short>(chunkSize.z, 100)
        )
    );

    auto test = [&value]()
        {
    		networking::XmlPacket packet {20};
            packet.SetIVec2(0, 0, "Position");
            packet.SetUChar(0, "Biome");
            packet.SetChunk(value, "Chunk");
            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    networking::XmlPacket packet{ 20 };
    packet.SetIVec2(0, 0, "Position");
    packet.SetUChar(0, "Biome");
    packet.SetChunk(value, "Chunk");

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = FullChunk(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Xml::Input()
{
    auto test = []()
        {
            networking::XmlPacket packet{ 12 };
            packet.SetInt32(1564815618, "PlayerId");
            packet.SetUChar(58, "InputType");
            packet.SetUChar(2, "InputAction");
            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    networking::XmlPacket packet{ 12 };
    packet.SetInt32(1564815618, "PlayerId");
    packet.SetUChar(58, "InputType");
    packet.SetUChar(2, "InputAction");

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = Input(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Xml::BlockUpdate()
{
    auto test = []()
        {
            networking::XmlPacket packet{ 11 };
            packet.SetIVec3(100, 72, -500, "Position");
            packet.SetInt16(1500, "BlockId");
            packet.SetUChar(4, "BlockData");
            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    networking::XmlPacket packet{ 11 };
    packet.SetIVec3(100, 72, -500, "Position");
    packet.SetInt16(1500, "BlockId");
    packet.SetUChar(4, "BlockData");

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = BlockUpdate(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Xml::PlayerUpdate()
{
    auto test = []()
        {
            networking::XmlPacket packet{ 11 };
            packet.SetInt32(1564815618, "PlayerId");
            packet.SetFloat3(100.f, 72.f, -500.f, "Position");
            packet.SetUChar(20, "Health");
            packet.SetBoolean(false, "OnGround");
            packet.SetFloat3(20.f, 50.f, 180.f, "Rotation");
            packet.SetFloat3(20.f, 50.f, 180.f, "HeadRotation");
            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    networking::XmlPacket packet{ 11 };
    packet.SetInt32(1564815618, "PlayerId");
    packet.SetFloat3(100.f, 72.f, -500.f, "Position");
    packet.SetUChar(20, "Health");
    packet.SetBoolean(false, "OnGround");
    packet.SetFloat3(20.f, 50.f, 180.f, "Rotation");
    packet.SetFloat3(20.f, 50.f, 180.f, "HeadRotation");

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = PlayerUpdate(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Xml::PlayerJoin()
{
    auto test = []()
        {
            networking::XmlPacket packet{ 13 };
            packet.SetInt32(1564815618, "PlayerId");
            packet.SetString("lee_vgs123457890", "Message");
            packet.SetFloat3(100.f, 72.f, -500.f, "Position");
            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    networking::XmlPacket packet{ 13 };
    packet.SetInt32(1564815618, "PlayerId");
    packet.SetString("lee_vgs123457890", "Message");
    packet.SetFloat3(100.f, 72.f, -500.f, "Position");

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = PlayerJoin(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Xml::ChatMessage()
{
    auto test = []()
        {
            networking::XmlPacket packet{ 13 };
            packet.SetInt32(1564815618, "PlayerId");
            packet.SetString("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis arcu ex, fermentum et faucibus facilisis, eleifend eget lacus. Mauris ex tortor, efficitur sit amet blandit ut, lacinia ultrices ante. Integer condimentum in.", "Message");
            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    networking::XmlPacket packet{ 13 };
    packet.SetInt32(1564815618, "PlayerId");
    packet.SetString("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis arcu ex, fermentum et faucibus facilisis, eleifend eget lacus. Mauris ex tortor, efficitur sit amet blandit ut, lacinia ultrices ante. Integer condimentum in.", "Message");

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = ChatMessage(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

double unag::benchmark::Xml::FullChunk(networking::XmlPacket& packet)
{
    std::vector<std::vector<std::vector<short>>> threeDArray;
    std::vector<int> position;
    char biome{};

    const std::string kankerCPP{ packet.GenerateString() };
    const std::string data{ packet.GenerateString() };

    packet.SetData(data);
    auto test = [&packet, &threeDArray, &position, &biome]()
        {
            threeDArray = packet.GetChunk("Chunk");
            position = packet.GetIVec2("Position");
            biome = packet.GetUChar("Biome");
        };

    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "Block[0,0,0] " << threeDArray[0][0][0] << "\n";
    std::cout << "Position (" << position[0] << ',' << position[1] << ")\n";
    std::cout << "Biome data " << biome << "\n";
    return result;
}

double unag::benchmark::Xml::Input(networking::XmlPacket& packet)
{
    int packetId{}, playerId{}, inputType{}, inputAction{};

    const auto data = packet.GenerateString();

    packet.SetData(data);
    auto test = [&packet, &packetId, &playerId, &inputType, &inputAction]()
        {
    		packetId = packet.ReadHeaderId();
            playerId = packet.GetInt32("PlayerId");
            inputType = packet.GetUChar("InputType");
            inputAction = packet.GetUChar("InputAction");
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "InputType " << inputType << "\n";
    std::cout << "InputAction " << inputAction << "\n";
    return result;
}

double unag::benchmark::Xml::BlockUpdate(networking::XmlPacket& packet)
{
    int packetId{}, blockId{}, blockData{};
    std::vector<int> position{};

    const auto data = packet.GenerateString();

    packet.SetData(data);
    auto test = [&packet, &packetId, &position, &blockId, &blockData]()
        {
            packetId = packet.ReadHeaderId();
            position = packet.GetIVec3("Position");
            blockId = packet.GetInt16("BlockId");
            blockData = packet.GetUChar("BlockData");
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "Position (" << position[0] << ',' << position[1] << ")\n";
    std::cout << "BlockId " << blockId << "\n";
    std::cout << "blockData " << blockData << "\n";
    return result;
}

double unag::benchmark::Xml::PlayerUpdate(networking::XmlPacket& packet)
{
    int packetId{}, playerId{}, health{};
    bool onGround{};
    std::vector<float> position{}, rotation{}, headRotation{};

    const auto data = packet.GenerateString();

    packet.SetData(data);
    auto test = [&packet, &packetId, &playerId, &health, &onGround, &position, &rotation, &headRotation]()
        {
            packetId = packet.ReadHeaderId();
            playerId = packet.GetInt32("PlayerId");
            position = packet.GetFloat3("Position");
            health = packet.GetUChar("Health");
            onGround = packet.GetBoolean("OnGround");
            rotation = packet.GetFloat3("Rotation");
            headRotation = packet.GetFloat3("HeadRotation");
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "Position (" << position[0] << ',' << position[1] << ',' << position[2] << ")\n";
    std::cout << "Health " << health << "\n";
    std::cout << "OnGround " << onGround << "\n";
    std::cout << "Rotation (" << rotation[0] << ',' << rotation[1] << ',' << rotation[2] << ")\n";
    std::cout << "HeadRotation (" << headRotation[0] << ',' << headRotation[1] << ',' << headRotation[2] << ")\n";
    return result;
}

double unag::benchmark::Xml::PlayerJoin(networking::XmlPacket& packet)
{
    int packetId{}, playerId{};
    std::string message{};
    std::vector<float> position{};

    const auto data = packet.GenerateString();

    packet.SetData(data);
    auto test = [&packet, &packetId, &position, &playerId, &message]()
        {
            packetId = packet.ReadHeaderId();
            playerId = packet.GetInt32("PlayerId");
            position = packet.GetFloat3("Position");
            message = packet.GetString("Message");
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "Message " << message << "\n";
    std::cout << "Position (" << position[0] << ',' << position[1] << ',' << position[2] << ")\n";
    return result;
}

double unag::benchmark::Xml::ChatMessage(networking::XmlPacket& packet)
{
    int packetId{}, playerId{};
    std::string message{};

    const auto data = packet.GenerateString();

    packet.SetData(data);
    auto test = [&packet, &packetId, &playerId, &message]()
        {
            packetId = packet.ReadHeaderId();
            playerId = packet.GetInt32("PlayerId");
            message = packet.GetString("Message");
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "Message " << message << "\n";
    return result;
}