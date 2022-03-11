project(RayTracer)

# Compile external dependencies 
add_subdirectory(include/glm)

include_directories(
	include/
	include/glm/
)

add_executable(RayTracer
	src/main.cpp
)