# Benchmarker cmake
add_executable(Benchmarker
	"main.cpp"
	"Packets/JsonPacket.cpp"
	"Packets/XmlPacket.cpp"
	"Benchmarks/Json.cpp"
	"Benchmarks/Xml.cpp"
	"Packets/Proto/Chunk.pb.cc"
	"Packets/Proto/ChatMessage.pb.cc"
	"Packets/Proto/Input.pb.cc"
	"Packets/Proto/BlockUpdate.pb.cc"
	"Packets/Proto/PlayerUpdate.pb.cc"
	"Packets/Proto/PlayerJoin.pb.cc"
	"Benchmarks/Proto.cpp")

target_include_directories(Benchmarker PUBLIC ${RAPIDJSON_DIR} ${RAPIDXML_DIR} ${PROTO_INCLUDE})
target_link_libraries(Benchmarker PUBLIC ${PROTO_LIB})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_include_directories(Benchmarker PUBLIC ${VLD_INCLUDE_DIR})
	target_link_libraries(Benchmarker PUBLIC ${VLD_LIBRARY_DIR})
endif()