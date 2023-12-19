#include "Json.h"

#include <iostream>

#include "Benchmarker.h"
#include "vec3.hpp"
#include "RapidJson/document.h"
#include "RapidJson/rapidjson.h"

#pragma region Encoding

void unag::benchmark::Json::FullChunk()
{
    networking::JsonPacket packet{};
    std::vector position{ 0,0 };
    rapidjson::Value biome{ 0 };

    constexpr glm::ivec3 chunkSize{ 16, 48, 16 };
    // Create a 3D vector and initialize all elements to 1
    std::vector value
    (
        chunkSize.x, std::vector
        (
            chunkSize.y, std::vector(chunkSize.z, 100)
        )
    );

    auto test = [&packet, &value, &position, &biome]()
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

            packet.Write(rapidjson::Value{ "Position" }, position);
            packet.Write(rapidjson::Value{"Biome"}, biome);
            packet.Write(rapidjson::Value{ "Chunk" }, jsonArray);

            packet.GenerateString();
        };
    
    Benchmarker benchmarker{};
    const auto result = benchmarker.AutoBench(test, 100);

    std::cout << "Size: " << packet.Length() << "\n";
    std::cout << "Time run: " << result << " ms\n";

    FullChunk(packet);
}

#pragma endregion

#pragma region Decoding

double unag::benchmark::Json::FullChunk(networking::JsonPacket& packet)
{
    std::vector<std::vector<std::vector<int>>> threeDArray;
    int x{}, y{};
    char biome{};
    auto test = [&packet, &threeDArray, &x, &y, &biome]()
        {
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
    const auto result = benchmarker.AutoBench(test, 50);
    std::cout << "Block[0,0,0] " << threeDArray[0][0][0] << "\n";
    std::cout << "Position (" << x << ',' << y << ")\n";
    std::cout << "Biome data " << biome << "\n";
    return result;
}

#pragma endregion