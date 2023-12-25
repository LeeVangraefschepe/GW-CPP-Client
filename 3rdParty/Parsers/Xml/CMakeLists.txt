#ThirdPartyHeaderOnly

file(GLOB Headers "*.h")

add_library(RapidXml INTERFACE ${Headers})

Set(RAPIDXML_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE PATH "")