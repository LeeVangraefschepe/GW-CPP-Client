#include "JsonPacket.h"
#include <RapidJson/writer.h>
#include <Debug.h>
#include <sstream>

vox::networking::JsonPacket::JsonPacket(int headerId) : m_HeaderId(headerId)
{
	m_Document.SetObject();
	rapidjson::Value newKey{ "PacketId" };
	rapidjson::Value newValue{ m_HeaderId };
	m_Document.AddMember(newKey, newValue, m_Document.GetAllocator());
}

void vox::networking::JsonPacket::SetData(std::vector<char>& data)
{
	m_Document = rapidjson::Document{};
	if (m_Document.Parse(data.data()).HasParseError())
	{
		std::stringstream ss{};
		ss << "Parsing error: " << m_Document.GetParseError() << '\n';
		leap::Debug::LogError(ss.str());
	}
}

void vox::networking::JsonPacket::SetData(rapidjson::Document doc)
{
	m_Document = std::move(doc);
	rapidjson::Value newKey{ "PacketId" };
	rapidjson::Value newValue{ m_HeaderId };
	m_Document.AddMember(newKey, newValue, m_Document.GetAllocator());
}

char* vox::networking::JsonPacket::GetData()
{
	return m_Data.data();
}

rapidjson::Document& vox::networking::JsonPacket::GetDocument()
{
	return m_Document;
}

int vox::networking::JsonPacket::ReadHeaderId()
{
    if (m_Document.HasMember("PacketId"))
	{
	    if (const rapidjson::Value& addedValue = m_Document["PacketId"]; addedValue.IsInt())
		{
            return  addedValue.GetInt();
        }
    }

	leap::Debug::LogError("Failed to read packet header");
	return -1;
}

void vox::networking::JsonPacket::Write(rapidjson::Value key, rapidjson::Value& value)
{
	m_Document.AddMember(key, value, m_Document.GetAllocator());
}

void vox::networking::JsonPacket::Write(rapidjson::Value key, const std::vector<int>& value)
{
	rapidjson::Value jsonArray(rapidjson::kArrayType);
	for (const auto& number : value)
	{
		jsonArray.PushBack(number, m_Document.GetAllocator());
	}
	Write(std::move(key), jsonArray);
}

rapidjson::Value& vox::networking::JsonPacket::Read(const char* key)
{
	if (m_Document.HasMember(key))
	{
		return m_Document[key];
	}

	leap::Debug::LogError("Failed to read packet key");
	return m_Empty;
}

rapidjson::Value& vox::networking::JsonPacket::ReadArray(const char* key, int& size)
{
	if (m_Document.HasMember(key) && m_Document[key].IsArray())
	{
		auto& value = m_Document[key];
		size = static_cast<int>(value.Size());
		return value.GetArray();
	}

	leap::Debug::LogError("Failed to read packet key");
	return m_Empty;
}