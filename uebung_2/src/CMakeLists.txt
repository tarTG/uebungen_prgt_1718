SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

#generate an executable
add_executable( uebung_1
main.cpp
Paddle.cpp
Ball.cpp)

target_link_libraries(uebung_1  ${SFML_LIBRARIES}) 