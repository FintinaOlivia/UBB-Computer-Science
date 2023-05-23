# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\W12_Test_Attempt_Bills_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\W12_Test_Attempt_Bills_autogen.dir\\ParseCache.txt"
  "W12_Test_Attempt_Bills_autogen"
  )
endif()
