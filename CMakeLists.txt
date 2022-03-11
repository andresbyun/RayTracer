project(RayTracer)

# Compile external dependencies 
add_subdirectory(include/glm)

include_directories(
	include/
	include/glm/
)

# Copy scripts to the executable's directory
file(COPY ./scripts DESTINATION "${CMAKE_BINARY_DIR}")

add_executable(RayTracer
	src/main.cpp
)
