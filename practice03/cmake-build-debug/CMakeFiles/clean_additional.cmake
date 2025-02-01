# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "._autogen"
  "CMakeFiles\\._autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\._autogen.dir\\ParseCache.txt"
  )
endif()
