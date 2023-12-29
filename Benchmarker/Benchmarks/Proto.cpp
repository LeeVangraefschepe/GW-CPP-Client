#include "Proto.h"
#include "../Packets/Proto/Chunk.pb.h"
#include "../Packets/Proto/ChatMessage.pb.h"
#include "../Packets/Proto/Input.pb.h"
#include "../Packets/Proto/BlockUpdate.pb.h"
#include "../Packets/Proto/PlayerUpdate.pb.h"
#include "../Packets/Proto/PlayerJoin.pb.h"
#include <vector>

#include "Benchmarker.h"

void unag::benchmark::Proto::FullChunk()
{
	packet::ChunkData packet{};
	const std::vector value
	(
		16, std::vector
		(
			384, std::vector<short>(16, 100)
		)
	);

	auto test = [&packet, &value]()
		{
			packet = packet::ChunkData{};
			packet.set_packetid(20);
			packet.mutable_position()->set_x(0);
			packet.mutable_position()->set_y(0);
			packet.set_biome(0);

			for (const auto& rowVector : value)
			{
				packet::ChunkData::ChunkRow* row = packet.add_chunk();
				for (const auto& sliceVector : rowVector)
				{
					packet::ChunkData::ChunkSlice* slice = row->add_slices();
					slice->mutable_values()->Add(sliceVector.begin(), sliceVector.end());
				}
			}
			packet.SerializeAsString();
		};

	Benchmarker benchmarker{};
	auto result = benchmarker.AutoBench(test, 1000);

	std::string text{ packet.SerializeAsString() };
	std::cout << "Size: " << text.size() << "\n";
	std::cout << "Time run encoding: " << result << " ms\n";

	result = FullChunk(text);
	std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Proto::Input()
{
	packet::Input packet{};
	auto test = [&packet]()
		{
			packet = packet::Input{};
			packet.set_packetid(12);
			packet.set_playerid(1564815618);
			packet.set_inputtype(58);
			packet.set_inputaction(2);
			packet.SerializeAsString();
		};

	Benchmarker benchmarker{};
	auto result = benchmarker.AutoBench(test, 1000);

	std::string text{ packet.SerializeAsString() };
	std::cout << "Size: " << text.length() << "\n";
	std::cout << "Time run encoding: " << result << " ms\n";

	result = Input(text);
	std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Proto::BlockUpdate()
{
	packet::BlockUpdate packet{};

	auto test = [&packet]()
		{
			packet = packet::BlockUpdate{};
			packet.set_packetid(11);
			packet.mutable_position()->set_x(100);
			packet.mutable_position()->set_y(72);
			packet.mutable_position()->set_z(-500);
			packet.set_block(1500);
			packet.set_blockdata(4);
			packet.SerializeAsString();
		};

	Benchmarker benchmarker{};
	auto result = benchmarker.AutoBench(test, 10000);

	std::string text{ packet.SerializeAsString() };
	std::cout << "Size: " << text.length() << "\n";
	std::cout << "Time run encoding: " << result << " ms\n";

	result = BlockUpdate(text);
	std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Proto::PlayerUpdate()
{
	packet::PlayerUpdate packet{};

	auto test = [&packet]()
		{
			packet = packet::PlayerUpdate{ };

			packet.set_packetid(10);
			packet.set_playerid(1564815618);
			packet.mutable_position()->set_x(100.f);
			packet.mutable_position()->set_y(72.f);
			packet.mutable_position()->set_z(-500.f);
			packet.set_health(20);
			packet.set_onground(false);
			packet.mutable_rotation()->set_x(20.f);
			packet.mutable_rotation()->set_y(50.f);
			packet.mutable_rotation()->set_z(180.f);
			packet.mutable_headrotation()->set_x(20.f);
			packet.mutable_headrotation()->set_y(50.f);
			packet.mutable_headrotation()->set_z(180.f);

			packet.SerializeAsString();
		};

	Benchmarker benchmarker{};
	auto result = benchmarker.AutoBench(test, 10000);

	std::string text{ packet.SerializeAsString() };
	std::cout << "Size: " << text.length() << "\n";
	std::cout << "Time run encoding: " << result << " ms\n";

	result = PlayerUpdate(text);
	std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Proto::PlayerJoin()
{
	packet::PlayerJoin packet{};
	auto test = [&packet]()
		{
			packet = packet::PlayerJoin{};
			packet.set_playerid(13);
			packet.set_playerid(1564815618);
			packet.set_message("lee_vgs123457890");
			packet.mutable_position()->set_x(100.f);
			packet.mutable_position()->set_y(72.f);
			packet.mutable_position()->set_z(-500.f);
			packet.SerializeAsString();
		};

	Benchmarker benchmarker{};
	auto result = benchmarker.AutoBench(test, 10000);

	std::string text{ packet.SerializeAsString() };
	std::cout << "Size: " << text.length() << "\n";
	std::cout << "Time run encoding: " << result << " ms\n";

	result = PlayerJoin(text);
	std::cout << "Time run decoding: " << result << " ms\n";
}

void unag::benchmark::Proto::ChatMessage()
{
	packet::ChatMessage packet{};
	auto test = [&packet]()
		{
			packet = packet::ChatMessage{};
			packet.set_playerid(14);
			packet.set_playerid(1564815618);
			packet.set_message("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis arcu ex, fermentum et faucibus facilisis, eleifend eget lacus. Mauris ex tortor, efficitur sit amet blandit ut, lacinia ultrices ante. Integer condimentum in.");
			packet.SerializeAsString();
		};

	Benchmarker benchmarker{};
	auto result = benchmarker.AutoBench(test, 10000);

	std::string text{ packet.SerializeAsString() };
	std::cout << "Size: " << text.length() << "\n";
	std::cout << "Time run encoding: " << result << " ms\n";

	result = ChatMessage(text);
	std::cout << "Time run decoding: " << result << " ms\n";
}

double unag::benchmark::Proto::FullChunk(std::string& data)
{
	std::vector<std::vector<std::vector<int16_t>>> threeDArray;
	int x{}, y{}, packetId{};
	char biome{};

	packet::ChunkData packet{};

	auto test = [&packet, &data, &threeDArray, &x, &y, &biome, &packetId]()
		{
			packet.ParseFromString(data);
			packetId = packet.packetid();
			x = packet.position().x();
			y = packet.position().y();
			biome = static_cast<char>(packet.biome());

			std::vector<std::vector<std::vector<int16_t>>> chunk{};
			chunk.reserve(packet.chunk_size());

			for (const auto& row : packet.chunk())
			{
				std::vector<std::vector<int16_t>> row_vector;
				row_vector.reserve(row.slices_size());

				for (const auto& slice : row.slices())
				{
					std::vector<int16_t> slice_vector(slice.values().begin(), slice.values().end());
					row_vector.push_back(std::move(slice_vector));
				}

				chunk.push_back(std::move(row_vector));
			}
			threeDArray = std::move(chunk);
		};

	Benchmarker benchmarker{};
	const auto result = benchmarker.AutoBench(test, 1000);
	std::cout << "Block[0,0,0] " << threeDArray[0][0][0] << "\n";
	std::cout << "Position (" << x << ',' << y << ")\n";
	std::cout << "Biome data " << biome << "\n";
	return result;
}

double unag::benchmark::Proto::Input(std::string& data)
{
	int packetId{}, playerId{}, inputType{}, inputAction{};

	packet::Input packet{};

	auto test = [&packet, &data, &packetId, &playerId, &inputType, &inputAction]()
		{
			packet.ParseFromString(data);
			packetId = packet.packetid();
			playerId = packet.playerid();
			inputType = packet.inputtype();
			inputAction = packet.inputaction();
		};


	Benchmarker benchmarker{};
	const auto result = benchmarker.AutoBench(test, 1000);
	std::cout << "PacketId " << packetId << "\n";
	std::cout << "PlayerId " << playerId << "\n";
	std::cout << "InputType " << inputType << "\n";
	std::cout << "InputAction " << inputAction << "\n";
	return result;
}

double unag::benchmark::Proto::BlockUpdate(std::string& data)
{
	int packetId{}, blockId{}, blockData{}, x{}, y{};

	packet::BlockUpdate packet{};

	auto test = [&packet, &data, &packetId, &x, &y, &blockId, &blockData]()
		{
			packet.ParseFromString(data);

			packetId = packet.packetid();
			x = packet.position().x();
			y = packet.position().y();
			blockId = packet.block();
			blockData = packet.blockdata();
		};


	Benchmarker benchmarker{};
	const auto result = benchmarker.AutoBench(test, 10000);
	std::cout << "PacketId " << packetId << "\n";
	std::cout << "Position (" << x << ',' << y << ")\n";
	std::cout << "BlockId " << blockId << "\n";
	std::cout << "blockData " << blockData << "\n";
	return result;
}

double unag::benchmark::Proto::PlayerUpdate(std::string& data)
{
	int packetId{}, playerId{}, health{};
	bool onGround{};
	std::vector<float> position{}, rotation{}, headRotation{};

	packet::PlayerUpdate packet{};

	auto test = [&packet, &data, &packetId, &position, &playerId, &health, &onGround, &rotation, &headRotation]()
		{
			position.clear();
			rotation.clear();
			headRotation.clear();

			packet.ParseFromString(data);

			packetId = packet.packetid();
			playerId = packet.playerid();

			position.push_back(packet.position().x());
			position.push_back(packet.position().y());
			position.push_back(packet.position().z());

			health = packet.health();
			onGround = packet.onground();

			rotation.push_back(packet.rotation().x());
			rotation.push_back(packet.rotation().y());
			rotation.push_back(packet.rotation().z());

			headRotation.push_back(packet.headrotation().x());
			headRotation.push_back(packet.headrotation().y());
			headRotation.push_back(packet.headrotation().z());
		};


	Benchmarker benchmarker{};
	const auto result = benchmarker.AutoBench(test, 10000);
	std::cout << "PacketId " << packetId << "\n";
	std::cout << "PlayerId " << playerId << "\n";
	std::cout << "Position (" << position[0] << ',' << position[1] << ',' << position[2] << ")\n";
	std::cout << "Health " << health << "\n";
	std::cout << "OnGround " << onGround << "\n";
	std::cout << "Rotation (" << rotation[0] << ',' << rotation[1] << ',' << rotation[2] << ")\n";
	std::cout << "HeadRotation (" << headRotation[0] << ',' << headRotation[1] << ',' << headRotation[2] << ")\n";
	return result;
}

double unag::benchmark::Proto::PlayerJoin(std::string& data)
{
	int packetId{}, playerId{};
	std::vector<float> position{};
	std::string message{};

	packet::PlayerJoin packet{ };

	auto test = [&packet, &data, &packetId, &playerId, &message, &position]()
		{
			position.clear();
			packet = packet::PlayerJoin{};
			packet.ParseFromString(data);

			packetId = packet.packetid();
			playerId = packet.playerid();
			message = packet.message();
			position.push_back(packet.position().x());
			position.push_back(packet.position().y());
			position.push_back(packet.position().z());
		};


	Benchmarker benchmarker{};
	const auto result = benchmarker.AutoBench(test, 10000);
	std::cout << "PacketId " << packetId << "\n";
	std::cout << "PlayerId " << playerId << "\n";
	std::cout << "Message " << message << "\n";
	std::cout << "Position (" << position[0] << ',' << position[1] << ',' << position[2] << ")\n";
	return result;
}

double unag::benchmark::Proto::ChatMessage(std::string& data)
{
	int packetId{}, playerId{};
	std::string message{};

	packet::ChatMessage packet{ };

	auto test = [&packet, &data, &packetId, &playerId, &message]()
		{
			packet = packet::ChatMessage{};
			packet.ParseFromString(data);

			packetId = packet.packetid();
			playerId = packet.playerid();
			message = packet.message();
		};


	Benchmarker benchmarker{};
	const auto result = benchmarker.AutoBench(test, 10000);
	std::cout << "PacketId " << packetId << "\n";
	std::cout << "PlayerId " << playerId << "\n";
	std::cout << "Message " << message << "\n";
	return result;
}