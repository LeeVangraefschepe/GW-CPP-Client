# Benchmarker cmake
add_executable(Benchmarker
	"main.cpp"
	"Packets/JsonPacket.cpp"
	"Packets/XmlPacket.cpp"
	"Benchmarks/Json.cpp"
	"Benchmarks/Xml.cpp"
	"Packets/Proto/Phone.pb.cc")

target_include_directories(Benchmarker PUBLIC ${RAPIDJSON_DIR} ${RAPIDXML_DIR} ${PROTO_INCLUDE})
target_link_libraries(Benchmarker PUBLIC ${PROTO_LIB})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_include_directories(Benchmarker PUBLIC ${VLD_INCLUDE_DIR})
	target_link_libraries(Benchmarker PUBLIC ${VLD_LIBRARY_DIR})
endif()

file(GLOB_RECURSE SRC_DIR "Packets/Proto/*.cc" "Packets/Proto/*.h")

set_source_files_properties(
  ${SRC_DIR}
  PROPERTIES
  COMPILE_FLAGS "-w"
)