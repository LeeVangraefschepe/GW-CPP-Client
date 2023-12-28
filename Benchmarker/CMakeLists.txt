# Benchmarker cmake
add_executable(Benchmarker
	"main.cpp"
	"Packets/JsonPacket.cpp"
	"Packets/XmlPacket.cpp"
	"Benchmarks/Json.cpp"
	"Benchmarks/Xml.cpp")

target_include_directories(Benchmarker PUBLIC ${RAPIDJSON_DIR} ${RAPIDXML_DIR})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_include_directories(Benchmarker PUBLIC ${VLD_INCLUDE_DIR})
	target_link_libraries(Benchmarker PUBLIC ${VLD_LIBRARY_DIR})
endif()