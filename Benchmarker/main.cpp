#include <iostream>
#include <string>
#include "Benchmarks/Json.h"
#include "Benchmarks/Xml.h"
#include "Packets/Proto/Phone.pb.h"

int main()
{
	unag::benchmark::Json benchmark{};

	tutorial::Person test{};
	test.set_number("Hello fking world");
	test.set_id(69);

	const std::string data{ test.SerializeAsString() };

	tutorial::Person test2{};
	test2.ParseFromString(data);
	std::cout << test2.id() << ": " << test.number() << std::endl;


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
