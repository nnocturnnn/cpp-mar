set(SOURCE_EXE main.cpp)
include_directories(src)

add_subdirectory(src)
add_executable(serializer ${SOURCE_EXE})
target_link_libraries(serializer libserializer)
