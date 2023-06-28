# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MV_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MV_autogen.dir\\ParseCache.txt"
  "MV_autogen"
  )
endif()
