#ifndef __RAY_HPP__
#define __RAY_HPP__

#include <glm/glm.hpp>

class Ray {
public:
	Ray(const glm::vec4& orig, const glm::vec4& dir);
	glm::vec4 at(float t);
	Ray reflected(glm::vec4 N, float t);

private:
	glm::vec4 orig;
	glm::vec4 dir;
};

#endif // !__RAY_HPP__
