SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

#generate an executable
add_executable( uebung_7
main.cpp
Paddle.cpp
Ball.cpp
IGameObject.cpp
Observed.cpp
Collision.cpp
Border.cpp
GUI.cpp
RNG.cpp)

target_link_libraries(uebung_7  ${SFML_LIBRARIES}) 
