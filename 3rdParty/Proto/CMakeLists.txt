# Proto CMake
set(PROTO_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE PATH "")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(PROTO_LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib/libprotobufd.lib" CACHE PATH "")
else()
	set(PROTO_LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib/libprotobuf.lib" CACHE PATH "")
endif()
