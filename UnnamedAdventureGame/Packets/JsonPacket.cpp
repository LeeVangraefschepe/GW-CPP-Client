#include "JsonPacket.h"
#include <RapidJson/writer.h>
#include <Debug.h>
#include <sstream>

unag::networking::JsonPacket::JsonPacket(int headerId) : m_HeaderId(headerId)
{
	m_Document.SetObject();
	rapidjson::Value newKey{ "PacketId" };
	rapidjson::Value newValue{ m_HeaderId };
	m_Document.AddMember(newKey, newValue, m_Document.GetAllocator());
}

void unag::networking::JsonPacket::SetData(std::vector<char>& data)
{
	m_Document = rapidjson::Document{};
	if (m_Document.Parse(data.data()).HasParseError())
	{
		std::stringstream ss{};
		ss << "Parsing error: " << m_Document.GetParseError() << '\n';
		leap::Debug::LogError(ss.str());
	}
}

void unag::networking::JsonPacket::SetData(rapidjson::Document doc)
{
	m_Document = std::move(doc);
	rapidjson::Value newKey{ "PacketId" };
	rapidjson::Value newValue{ m_HeaderId };
	m_Document.AddMember(newKey, newValue, m_Document.GetAllocator());
}

char* unag::networking::JsonPacket::GetData()
{
	//Todo: Add document to string
	return m_Data.data();
}

rapidjson::Document& unag::networking::JsonPacket::GetDocument()
{
	return m_Document;
}

int unag::networking::JsonPacket::ReadHeaderId()
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

void unag::networking::JsonPacket::Write(rapidjson::Value key, rapidjson::Value& value)
{
	m_Document.AddMember(key, value, m_Document.GetAllocator());
}

void unag::networking::JsonPacket::Write(rapidjson::Value key, const std::vector<int>& value)
{
	rapidjson::Value jsonArray(rapidjson::kArrayType);
	for (const auto& number : value)
	{
		jsonArray.PushBack(number, m_Document.GetAllocator());
	}
	Write(std::move(key), jsonArray);
}

void unag::networking::JsonPacket::GenerateString()
{
	rapidjson::StringBuffer buffer;
	rapidjson::Writer writer{ buffer };
	m_Document.Accept(writer);
	m_Data = std::vector<char>{ buffer.GetString(), buffer.GetString() + buffer.GetSize() };
}

rapidjson::Value& unag::networking::JsonPacket::Read(const char* key)
{
	if (m_Document.HasMember(key))
	{
		return m_Document[key];
	}

	leap::Debug::LogError("Failed to read packet key");
	return m_Empty;
}

rapidjson::Value& unag::networking::JsonPacket::ReadArray(const char* key, int& size)
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