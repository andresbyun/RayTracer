cmake_minimum_required(VERSION 3.20)
project(RayTracer)

# Include directories
include_directories(
	include/
	include/glm/
)

# Copy directories to the executable's directory
file(COPY ./scripts DESTINATION "${CMAKE_BINARY_DIR}")

# Generate directory at build system generation
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/tmp")

# Add to executable
add_executable(RayTracer
	src/main.cpp
	src/Ray.cpp
	src/Camera.cpp
 )
