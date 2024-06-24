# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QML-DragDrop-Example_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QML-DragDrop-Example_autogen.dir\\ParseCache.txt"
  "QML-DragDrop-Example_autogen"
  )
endif()
