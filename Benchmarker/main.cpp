#include <iostream>
#include <string>
#include "Benchmarks/Json.h"
#include "Benchmarks/Xml.h"
#include "Packets/Proto/Chunk.pb.h"

int main()
{
	unag::benchmark::Json benchmark{};

	ChunkData data{};
	data.set_packet_id(123);  // Assuming 123 is your desired packet ID
	data.mutable_position()->set_x(456);
	data.mutable_position()->set_y(789);
	data.set_biome(5);

	std::vector value
	(
		16, std::vector
		(
			48, std::vector<short>(16, 100)
		)
	);

	for (const auto& rowVector : value)
	{
		ChunkData::ChunkRow* row = data.add_chunk();
		for (const auto& sliceVector : rowVector)
		{
			ChunkData::ChunkSlice* slice = row->add_slices();
			// Append the entire row at once using add_values
			slice->mutable_values()->Add(sliceVector.begin(), sliceVector.end());
		}
	}

	std::cout << "Packet size: " << data.SerializeAsString().size() << "\n";

	std::string line{};
	while (true)
	{
		std::getline(std::cin, line);
		if (line.find("stop") != std::string::npos) break;

		if (line.find("chunk") != std::string::npos) benchmark.FullChunk();
		if (line.find("input") != std::string::npos) benchmark.Input();
		if (line.find("block update") != std::string::npos) benchmark.BlockUpdate();
		if (line.find("player update") != std::string::npos) benchmark.PlayerUpdate();
		if (line.find("player join") != std::string::npos) benchmark.PlayerJoin();
		if (line.find("chat message") != std::string::npos) benchmark.ChatMessage();

		std::cout << "\n\n\n";
	}

	return 0;
}
