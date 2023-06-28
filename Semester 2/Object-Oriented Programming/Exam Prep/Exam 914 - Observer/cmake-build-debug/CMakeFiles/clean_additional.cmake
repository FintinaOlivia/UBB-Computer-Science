# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ExamPrep914_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ExamPrep914_autogen.dir\\ParseCache.txt"
  "ExamPrep914_autogen"
  )
endif()
