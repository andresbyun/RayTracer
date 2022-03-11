#ifndef __MAIN__
#define __MAIN__

#include <string>
#include <vector>
#include <Camera.hpp>
#include <glm/glm.hpp>

/* Function definitions */
int main(int argc, char** argv);
void save_ppm(Camera eye);
std::vector<std::string> tokenize_line(std::string str);
glm::vec3 raytrace(Ray r);

#endif
