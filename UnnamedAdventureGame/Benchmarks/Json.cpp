#include "Json.h"

#include <iostream>

#include "Benchmarker.h"
#include "vec2.hpp"
#include "vec3.hpp"
#include "RapidJson/document.h"
#include "RapidJson/rapidjson.h"

#pragma region Encoding

void unag::benchmark::Json::FullChunk()
{
    networking::JsonPacket packet{};
    std::vector position{ 0,0 };

    constexpr glm::ivec3 chunkSize{ 16, 48, 16 };
    // Create a 3D vector and initialize all elements to 1
    std::vector value
    (
        chunkSize.x, std::vector
        (
            chunkSize.y, std::vector(chunkSize.z, 100)
        )
    );

    auto test = [&packet, &value, &position]()
        {
            packet = networking::JsonPacket{20};

            auto& document = packet.GetDocument();
            rapidjson::Value jsonArray(rapidjson::kArrayType);
            for (const auto& outerVector : value)
            {
                rapidjson::Value outerArray(rapidjson::kArrayType);
                for (const auto& middleVector : outerVector)
                {
                    rapidjson::Value middleArray(rapidjson::kArrayType);
                    for (const auto& number : middleVector)
                    {
                        middleArray.PushBack(number, document.GetAllocator());
                    }
                    outerArray.PushBack(std::move(middleArray), document.GetAllocator());
                }
                jsonArray.PushBack(std::move(outerArray), document.GetAllocator());
            }

            rapidjson::Value biome{ 0};

            packet.Write(rapidjson::Value{ "Position" }, position);
            packet.Write(rapidjson::Value{"Biome"}, biome);
            packet.Write(rapidjson::Value{ "Chunk" }, jsonArray);

            packet.GenerateString();
        };
    
    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = FullChunk(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Json::Input()
{
    networking::JsonPacket packet{};

    auto test = [&packet]()
        {
            packet = networking::JsonPacket{ 12 };

            rapidjson::Value playerId{ 1564815618 };
            packet.Write(rapidjson::Value{ "PlayerId" }, playerId);

            rapidjson::Value type{ 58 };
            packet.Write(rapidjson::Value{ "InputType" }, type);

            rapidjson::Value action{ 2};
            packet.Write(rapidjson::Value{ "InputAction" }, action);

            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 1000);

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = Input(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Json::BlockUpdate()
{
    networking::JsonPacket packet{};
    std::vector position {100, 72, -500};

    auto test = [&packet, &position]()
        {
            packet = networking::JsonPacket{ 11 };

            packet.Write(rapidjson::Value{ "Position" }, position);

            rapidjson::Value type{ 1500 };
            packet.Write(rapidjson::Value{ "BlockId" }, type);

            rapidjson::Value action{ 4 };
            packet.Write(rapidjson::Value{ "BlockData" }, action);

            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 10000);

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = BlockUpdate(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Json::PlayerUpdate()
{
    networking::JsonPacket packet{};
    std::vector position{ 100.f, 72.f, -500.f };
    std::vector rotation{ 20.f, 50.f, 180.f };

    auto test = [&packet, &position, &rotation]()
        {
            packet = networking::JsonPacket{ 10 };

            rapidjson::Value playerId{ 1564815618 };
            packet.Write(rapidjson::Value{ "PlayerId" }, playerId);

            packet.Write(rapidjson::Value{ "Position" }, position);

            rapidjson::Value health{ 20 };
            packet.Write(rapidjson::Value{ "Health" }, health);

            rapidjson::Value onGround{ false };
            packet.Write(rapidjson::Value{ "OnGround" }, onGround);

            packet.Write(rapidjson::Value{ "Rotation" }, rotation);

            packet.Write(rapidjson::Value{ "HeadRotation" }, rotation);

            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 10000);

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = PlayerUpdate(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Json::PlayerJoin()
{
    networking::JsonPacket packet{};
    std::vector position{ 100.f, 72.f, -500.f };

    auto test = [&packet, &position]()
        {
            packet = networking::JsonPacket{ 13 };

            rapidjson::Value playerId{ 1564815618 };
            packet.Write(rapidjson::Value{ "PlayerId" }, playerId);

            rapidjson::Value message{ "lee_vgs123457890" };
            packet.Write(rapidjson::Value{ "Message" }, message);

            packet.Write(rapidjson::Value{ "Position" }, position);

            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 10000);

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = PlayerJoin(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Json::ChatMessage()
{
    networking::JsonPacket packet{};

    auto test = [&packet]()
        {
            packet = networking::JsonPacket{ 14 };

            rapidjson::Value playerId{ 1564815618 };
            packet.Write(rapidjson::Value{ "PlayerId" }, playerId);

            rapidjson::Value message{ "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis arcu ex, fermentum et faucibus facilisis, eleifend eget lacus. Mauris ex tortor, efficitur sit amet blandit ut, lacinia ultrices ante. Integer condimentum in." };
            packet.Write(rapidjson::Value{ "Message" }, message);

            packet.GenerateString();
        };

    Benchmarker benchmarker{};
    auto result = benchmarker.AutoBench(test, 10000);

    const std::string text{ packet.GenerateString() };
    std::cout << "Size: " << text.length() << "\n";
    std::cout << "Time run encoding: " << result << " ms\n";

    result = ChatMessage(packet);
    std::cout << "Time run decoding: " << result << " ms\n";
}

#pragma endregion

#pragma region Decoding

double unag::benchmark::Json::FullChunk(networking::JsonPacket& packet)
{
    std::vector<std::vector<std::vector<int>>> threeDArray;
    int x{}, y{}, packetId{};
    char biome{};

    const auto data = packet.GenerateString();

    auto test = [&packet, &data, &threeDArray, &x, &y, &biome, &packetId]()
        {
            packet = networking::JsonPacket{};
            packet.SetData(data);
            packetId = packet.ReadHeaderId();

			// Read out 3D array
            threeDArray.clear();
            auto& document = packet.GetDocument();
            if (document.HasMember("Chunk") && document["Chunk"].IsArray())
            {
                const rapidjson::Value& chunkArray = document["Chunk"];

                // Reserve space for the threeDArray to avoid unnecessary reallocations
                threeDArray.reserve(chunkArray.Size());

                for (const auto& layer : chunkArray.GetArray())
                {
                    // Vector to store the current layer
                    std::vector<std::vector<int>> currentLayer;
                    currentLayer.reserve(layer.Size());

                    for (const auto& row : layer.GetArray())
                    {
                        // Vector to store the current row
                        std::vector<int> currentRow;
                        currentRow.reserve(row.Size());

                        for (const auto& element : row.GetArray())
                        {
                            currentRow.push_back(element.GetInt());
                        }

                        currentLayer.push_back(std::move(currentRow));
                    }

                    threeDArray.push_back(std::move(currentLayer));
                }
            }

			// Read out position
            if (document.HasMember("Position") && document["Position"].IsArray())
            {
                const rapidjson::Value& jsonArray = document["Position"].GetArray();
                x = jsonArray[0].GetInt();
                y = jsonArray[1].GetInt();
            }

			// Read out biome data
            if (document.HasMember("Biome"))
            {
                biome = static_cast<char>(document["Biome"].GetInt());
            }
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "Block[0,0,0] " << threeDArray[0][0][0] << "\n";
    std::cout << "Position (" << x << ',' << y << ")\n";
    std::cout << "Biome data " << biome << "\n";
    return result;
}

double unag::benchmark::Json::Input(networking::JsonPacket& packet)
{
    int packetId{}, playerId{}, inputType{}, inputAction{};

    const auto data = packet.GenerateString();

    auto test = [&packet, &data, &packetId, &playerId, &inputType, &inputAction]()
        {
            packet = networking::JsonPacket{};
            packet.SetData(data);
            packetId = packet.ReadHeaderId();
            playerId = packet.Read("PlayerId").GetInt();
            inputType = packet.Read("InputType").GetInt();
            inputAction = packet.Read("InputAction").GetInt();
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 1000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "InputType " << inputType << "\n";
    std::cout << "InputAction " << inputAction << "\n";
    return result;
}

double unag::benchmark::Json::BlockUpdate(networking::JsonPacket& packet)
{
    int packetId{}, blockId{}, blockData{};
    glm::ivec2 position{};

    const auto data = packet.GenerateString();

    auto test = [&packet, &data, &packetId, &position, &blockId, &blockData]()
        {
            packet = networking::JsonPacket{};
            packet.SetData(data);
            auto& document = packet.GetDocument();

            packetId = packet.ReadHeaderId();

            const auto positionArray = document["Position"].GetArray();
            position.x = positionArray[0].GetInt();
            position.y = positionArray[1].GetInt();

            blockId = packet.Read("BlockId").GetInt();
            blockData = packet.Read("BlockData").GetInt();
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 10000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "Position (" << position.x << ',' << position.y << ")\n";
    std::cout << "BlockId " << blockId << "\n";
    std::cout << "blockData " << blockData << "\n";
    return result;
}

double unag::benchmark::Json::PlayerUpdate(networking::JsonPacket& packet)
{
    int packetId{}, playerId{}, health{};
    bool onGround{};
    glm::vec3 position{}, rotation{}, headRotation{};

    const auto data = packet.GenerateString();

    auto test = [&packet, &data, &packetId, &position, &playerId, &health, &onGround, &rotation, &headRotation]()
        {
            packet = networking::JsonPacket{};
            packet.SetData(data);
            auto& document = packet.GetDocument();

            packetId = packet.ReadHeaderId();

            playerId = packet.Read("PlayerId").GetInt();

            const auto positionArray = document["Position"].GetArray();
            position.x = positionArray[0].GetFloat();
            position.y = positionArray[1].GetFloat();
            position.z = positionArray[2].GetFloat();

            health = packet.Read("Health").GetInt();
            onGround = packet.Read("OnGround").GetBool();

            const auto rotationArray = document["Rotation"].GetArray();
            rotation.x = rotationArray[0].GetFloat();
            rotation.y = rotationArray[1].GetFloat();
            rotation.z = rotationArray[2].GetFloat();

            const auto headRotationArray = document["HeadRotation"].GetArray();
            headRotation.x = headRotationArray[0].GetFloat();
            headRotation.y = headRotationArray[1].GetFloat();
            headRotation.z = headRotationArray[2].GetFloat();
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 10000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "Position (" << position.x << ',' << position.y << ',' << position.z << ")\n";
    std::cout << "Health " << health << "\n";
    std::cout << "OnGround " << onGround << "\n";
    std::cout << "Rotation (" << rotation.x << ',' << rotation.y << ',' << rotation.z << ")\n";
    std::cout << "HeadRotation (" << headRotation.x << ',' << headRotation.y << ',' << headRotation.z << ")\n";
    return result;
}

double unag::benchmark::Json::PlayerJoin(networking::JsonPacket& packet)
{
    int packetId{}, playerId{};
    glm::vec3 position{};
    std::string message{};

    const auto data = packet.GenerateString();

    auto test = [&packet, &data, &packetId, &position, &playerId, &message]()
        {
            packet = networking::JsonPacket{};
            packet.SetData(data);
            auto& document = packet.GetDocument();

            packetId = packet.ReadHeaderId();

            playerId = packet.Read("PlayerId").GetInt();

            message = std::string{ packet.Read("Message").GetString() };

            const auto positionArray = document["Position"].GetArray();
            position.x = positionArray[0].GetFloat();
            position.y = positionArray[1].GetFloat();
            position.z = positionArray[2].GetFloat();
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 10000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "Message " << message << "\n";
    std::cout << "Position (" << position.x << ',' << position.y << ',' << position.z << ")\n";
    return result;
}

double unag::benchmark::Json::ChatMessage(networking::JsonPacket& packet)
{
    int packetId{}, playerId{};
    std::string message{};

    const auto data = packet.GenerateString();

    auto test = [&packet, &data, &packetId, &playerId, &message]()
        {
            packet = networking::JsonPacket{};
            packet.SetData(data);
            
            packetId = packet.ReadHeaderId();

            playerId = packet.Read("PlayerId").GetInt();

            message = std::string{ packet.Read("Message").GetString() };
        };


    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 10000);
    std::cout << "PacketId " << packetId << "\n";
    std::cout << "PlayerId " << playerId << "\n";
    std::cout << "Message " << message << "\n";
    return result;
}

#pragma endregion
