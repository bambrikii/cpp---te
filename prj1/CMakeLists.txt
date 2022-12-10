cmake_minimum_required(VERSION 3.0)

project("prj1")

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --save-temps")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


### prj1
set(SOURCE_FILES main.cpp multiply.cpp)
add_executable("prj1" ${SOURCE_FILES})

### prj2
project("prj2")
set(SOURCE_FILES2 main2.cpp multiply.cpp)
add_executable("prj2" ${SOURCE_FILES2})

### prj-collections
project("prj-collections")
set(SOURCE_FILES_COLLECTIONS
 collections/main.cpp
 collections/ListEg.cpp
 collections/VectorEg.cpp
)
add_executable("prj-collections" ${SOURCE_FILES_COLLECTIONS})

### prj-stackheap
project("prj-stackheap")
set(SOURCE_FILES_STACKHEAP
 heap/constructors.cpp
 heap/main.cpp
)
add_executable("prj-stackheap" ${SOURCE_FILES_STACKHEAP})
