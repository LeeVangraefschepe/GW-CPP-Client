#pragma once
#include <string>

#include "BasePacket.h"
#include <vector>
#include "RapidXml/rapidxml.hpp"

namespace unag::networking
{
	class XmlPacket final : public leap::networking::BasePacket
	{
	public:
		explicit XmlPacket(int headerId = -1);
		void SetData(std::vector<char>& data) override;
        void SetData(const std::string& data);
		char* GetData() override;
		rapidxml::xml_document<>& GetDocument();
		int ReadHeaderId() const;

        void SetUChar(char value, const char* key);
        void SetInt32(int value, const char* key);
        void SetInt16(short value, const char* key);
        void SetFloat3(float x, float y, float z, const char* key);
        void SetBoolean(bool value, const char* key);
        void SetIVec2(int x, int y, const char* key);
        void SetIVec3(int x, int y, int z, const char* key);
        void SetString(const char* value, const char* key);
        void SetChunk(const std::vector<std::vector<std::vector<short>>>& chunk, const char* key);

        char GetUChar(const char* key);
        int GetInt32(const char* key);
        short GetInt16(const char* key);
        void GetFloat3(const char* key, std::vector<float>& data);
        bool GetBoolean(const char* key);
        void GetIVec2(const char* key, std::vector<int>& data);
        void GetIVec3(const char* key, std::vector<int>& data);
        char* GetString(const char* key);
        std::vector<std::vector<std::vector<short>>> GetChunk(const char* key);

        const std::string& GenerateString();

	private:
		rapidxml::xml_document<> m_Document{};
        std::string m_Text{};
	};
}