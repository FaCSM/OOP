# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\practice06-server_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\practice06-server_autogen.dir\\ParseCache.txt"
  "practice06-server_autogen"
  )
endif()
