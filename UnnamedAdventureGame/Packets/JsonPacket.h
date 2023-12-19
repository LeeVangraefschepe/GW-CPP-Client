#pragma once
#include <string>

#include "Interfaces/BasePacket.h"
#include <vector>
#include <RapidJson/document.h>

namespace unag::networking
{
	class JsonPacket final : public leap::networking::BasePacket
	{
	public:
        explicit JsonPacket(int headerId = -1);

        void SetData(std::vector<char>& data) override;
        void SetData(const std::string& data);
        void SetData(rapidjson::Document doc);
        char* GetData() override;
        rapidjson::Document& GetDocument();
        int ReadHeaderId();

        void Write(rapidjson::Value key, rapidjson::Value& value);
        void Write(rapidjson::Value key, const std::vector<int>& value);
        std::string GenerateString();
        rapidjson::Value& Read(const char* key);
        rapidjson::Value& ReadArray(const char* key, int& size);
	private:
        int m_HeaderId{};
        rapidjson::Document m_Document{};
        rapidjson::Value m_Empty{};
	};
}