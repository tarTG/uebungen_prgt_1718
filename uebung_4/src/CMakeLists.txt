SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

#generate an executable
add_executable( uebung_4
main.cpp
Paddle.cpp
Ball.cpp
IGameObject.cpp
Observed.cpp)

target_link_libraries(uebung_4  ${SFML_LIBRARIES}) 
