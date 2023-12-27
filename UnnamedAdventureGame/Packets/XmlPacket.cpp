#include "XmlPacket.h"

#include <iostream>
#include <iterator>
#include <sstream>
#include <RapidXml/rapidxml.hpp>
#include <RapidXml/rapidxml_print.hpp>

#include "Debug.h"

unag::networking::XmlPacket::XmlPacket(int headerId)
{
    // Create the root element
    rapidxml::xml_node<>* root = m_Document.allocate_node(rapidxml::node_element, "data");
    m_Document.append_node(root);

    // Add PacketId element with an integer value
    rapidxml::xml_node<>* packetIdNode = m_Document.allocate_node(rapidxml::node_element, "PacketId");
    packetIdNode->value(m_Document.allocate_string(std::to_string(headerId).c_str()));
    root->append_node(packetIdNode);
}

void unag::networking::XmlPacket::SetData(std::vector<char>& data)
{
    m_Document.remove_all_nodes();
    m_Document.parse<0>(data.data());
}

void unag::networking::XmlPacket::SetData(const std::string& data)
{
    m_Document.remove_all_nodes();
    try {
        m_Document.parse<0>(const_cast<char*>(data.c_str()));
    }
    catch (const rapidxml::parse_error& e) {
        std::cerr << "XML parsing error: " << e.what() << std::endl;
        // Handle parsing error
        return;
    }
}

char* unag::networking::XmlPacket::GetData()
{
    print(std::back_inserter(m_Data), m_Document, 0);
    return m_Data.data();
}

rapidxml::xml_document<>& unag::networking::XmlPacket::GetDocument()
{
    return m_Document;
}

int unag::networking::XmlPacket::ReadHeaderId() const
{
	const auto root = m_Document.first_node("data");
    std::istringstream valueStream(root->first_node("PacketId")->value());
    int id;
    valueStream >> id;
    return id;
}

void unag::networking::XmlPacket::SetUChar(char value, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* packetIdNode = m_Document.allocate_node(rapidxml::node_element, key);
    packetIdNode->value(m_Document.allocate_string(std::to_string(value).c_str()));
    root->append_node(packetIdNode);
}

void unag::networking::XmlPacket::SetInt32(int value, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* packetIdNode = m_Document.allocate_node(rapidxml::node_element, key);
    packetIdNode->value(m_Document.allocate_string(std::to_string(value).c_str()));
    root->append_node(packetIdNode);
}

void unag::networking::XmlPacket::SetInt16(short value, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* packetIdNode = m_Document.allocate_node(rapidxml::node_element, key);
    packetIdNode->value(m_Document.allocate_string(std::to_string(value).c_str()));
    root->append_node(packetIdNode);
}

void unag::networking::XmlPacket::SetFloat3(float x, float y, float z, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* newNode = m_Document.allocate_node(rapidxml::node_element, key);
    rapidxml::xml_attribute<>* xAttr = m_Document.allocate_attribute("x", m_Document.allocate_string(std::to_string(x).c_str()));
    rapidxml::xml_attribute<>* yAttr = m_Document.allocate_attribute("y", m_Document.allocate_string(std::to_string(y).c_str()));
    rapidxml::xml_attribute<>* zAttr = m_Document.allocate_attribute("z", m_Document.allocate_string(std::to_string(z).c_str()));
    newNode->append_attribute(xAttr);
    newNode->append_attribute(yAttr);
    newNode->append_attribute(zAttr);
    root->append_node(newNode);
}

void unag::networking::XmlPacket::SetBoolean(bool value, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* packetIdNode = m_Document.allocate_node(rapidxml::node_element, key);
    packetIdNode->value(m_Document.allocate_string(std::to_string(value).c_str()));
    root->append_node(packetIdNode);
}

void unag::networking::XmlPacket::SetIVec2(int x, int y, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* newNode = m_Document.allocate_node(rapidxml::node_element, key);
    rapidxml::xml_attribute<>* xAttr = m_Document.allocate_attribute("x", m_Document.allocate_string(std::to_string(x).c_str()));
    rapidxml::xml_attribute<>* yAttr = m_Document.allocate_attribute("y", m_Document.allocate_string(std::to_string(y).c_str()));
    newNode->append_attribute(xAttr);
    newNode->append_attribute(yAttr);
    root->append_node(newNode);
}

void unag::networking::XmlPacket::SetIVec3(int x, int y, int z, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* newNode = m_Document.allocate_node(rapidxml::node_element, key);
    rapidxml::xml_attribute<>* xAttr = m_Document.allocate_attribute("x", m_Document.allocate_string(std::to_string(x).c_str()));
    rapidxml::xml_attribute<>* yAttr = m_Document.allocate_attribute("y", m_Document.allocate_string(std::to_string(y).c_str()));
    rapidxml::xml_attribute<>* zAttr = m_Document.allocate_attribute("z", m_Document.allocate_string(std::to_string(z).c_str()));
    newNode->append_attribute(xAttr);
    newNode->append_attribute(yAttr);
    newNode->append_attribute(zAttr);
    root->append_node(newNode);
}

void unag::networking::XmlPacket::SetString(const char* value, const char* key)
{
    const auto root = m_Document.first_node("data");
    rapidxml::xml_node<>* packetIdNode = m_Document.allocate_node(rapidxml::node_element, key);
    packetIdNode->value(m_Document.allocate_string(value));
    root->append_node(packetIdNode);
}

void unag::networking::XmlPacket::SetChunk(const std::vector<std::vector<std::vector<short>>>& chunk, const char* key)
{
    const auto root = m_Document.first_node("data");

    rapidxml::xml_node<>* newNode = m_Document.allocate_node(rapidxml::node_element, key);
    for (const auto& i : chunk)
    {
        rapidxml::xml_node<>* dim1Element = m_Document.allocate_node(rapidxml::node_element, "dim1");
        for (const auto& j : i)
        {
            rapidxml::xml_node<>* dim2Element = m_Document.allocate_node(rapidxml::node_element, "dim2");
            for (const short k : j)
            {
                rapidxml::xml_node<>* dim3Element = m_Document.allocate_node(rapidxml::node_element, "dim3");
                dim3Element->value(m_Document.allocate_string(std::to_string(k).c_str()));
                dim2Element->append_node(dim3Element);
            }
            dim1Element->append_node(dim2Element);
        }
        newNode->append_node(dim1Element);
    }

    root->append_node(newNode);
}

char unag::networking::XmlPacket::GetUChar(const char* key)
{
    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;
        const char* valueStr = node->value();
        return static_cast<char>(std::stoi(valueStr));
    }

    leap::Debug::LogError("No key found in XML");
    return 0;
}

int unag::networking::XmlPacket::GetInt32(const char* key)
{
    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;
        const char* valueStr = node->value();
        return static_cast<int>(std::stoi(valueStr));
    }

    leap::Debug::LogError("No key found in XML");
    return 0;
}

short unag::networking::XmlPacket::GetInt16(const char* key)
{
    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;
        const char* valueStr = node->value();
        return static_cast<short>(std::stoi(valueStr));
    }

    leap::Debug::LogError("No key found in XML");
    return 0;
}

std::vector<float> unag::networking::XmlPacket::GetFloat3(const char* key)
{
    std::vector<float> result{};

    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;

        const char* xStr = node->first_attribute("x")->value();
        const char* yStr = node->first_attribute("y")->value();
        const char* zStr = node->first_attribute("z")->value();
        result.push_back(std::stof(xStr));
        result.push_back(std::stof(yStr));
        result.push_back(std::stof(zStr));
        break;
    }

    return std::move(result);
}

bool unag::networking::XmlPacket::GetBoolean(const char* key)
{
    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;
        const char* valueStr = node->value();
        return static_cast<bool>(std::stoi(valueStr));
    }

    leap::Debug::LogError("No key found in XML");
    return false;
}

std::vector<int> unag::networking::XmlPacket::GetIVec2(const char* key)
{
    std::vector<int> result{};

    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;

        const char* xStr = node->first_attribute("x")->value();
        const char* yStr = node->first_attribute("y")->value();
        result.push_back(std::stoi(xStr));
        result.push_back(std::stoi(yStr));
        break;
    }

    return std::move(result);
}

std::vector<int> unag::networking::XmlPacket::GetIVec3(const char* key)
{
    std::vector<int> result{};

    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;

        const char* xStr = node->first_attribute("x")->value();
        const char* yStr = node->first_attribute("y")->value();
        const char* zStr = node->first_attribute("z")->value();
        result.push_back(std::stoi(xStr));
        result.push_back(std::stoi(yStr));
        result.push_back(std::stoi(zStr));
        break;
    }

    return std::move(result);
}

char* unag::networking::XmlPacket::GetString(const char* key)
{
    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;
        return node->value();
    }

    leap::Debug::LogError("No key found in XML");
    return nullptr;
}

std::vector<std::vector<std::vector<short>>> unag::networking::XmlPacket::GetChunk(const char* key)
{
    std::vector<std::vector<std::vector<short>>> result;
    const auto root = m_Document.first_node("data");

    for (const rapidxml::xml_node<>* node = root->first_node(); node; node = node->next_sibling())
    {
        if (std::string(node->name()) != key) continue;

        for (const rapidxml::xml_node<>* dim1Node = node->first_node("dim1"); dim1Node; dim1Node = dim1Node->next_sibling())
        {
            std::vector<std::vector<short>> dim1Data;
            for (const rapidxml::xml_node<>* dim2Node = dim1Node->first_node("dim2"); dim2Node; dim2Node = dim2Node->next_sibling())
            {
                std::vector<short> dim2Data;
                for (const rapidxml::xml_node<>* dim3Node = dim2Node->first_node("dim3"); dim3Node; dim3Node = dim3Node->next_sibling())
                {
                    const char* valueStr = dim3Node->value();
                    dim2Data.push_back(static_cast<short>(std::stoi(valueStr)));
                }
                dim1Data.push_back(dim2Data);
            }
            result.push_back(dim1Data);
        }
        break;
    }
    
    return result;
}

const std::string& unag::networking::XmlPacket::GenerateString()
{
    m_Data.clear(); // Clear the existing data

    // Use RapidXML's print function to generate the XML string
    rapidxml::print(std::back_inserter(m_Data), m_Document, 0);

    // Copy the generated data to m_Text
    m_Text = std::string(m_Data.begin(), m_Data.end());

    return m_Text;
}