#include <iostream>
#include <string>
#include "Benchmarks/Json.h"
#include "Benchmarks/Xml.h"
#include "Benchmarks/Proto.h"

int main()
{
	unag::benchmark::Proto benchmark{};

	std::string line{};
	int i{};
	while (true)
	{
		std::cout << "Iteration: " << i++ << '\n';
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