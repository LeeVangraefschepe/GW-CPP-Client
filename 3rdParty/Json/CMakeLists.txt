#ThirdPartyHeaderOnly

file(GLOB Headers "*.h")

add_library(RapidJson INTERFACE ${Headers})

Set(RAPIDJSON_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "")