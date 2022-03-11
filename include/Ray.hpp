#ifndef __RAY_HPP__
#define __RAY_HPP__

#include <glm/glm.hpp>

using glm::vec4;

class Ray {
public:
	Ray(const vec4& orig, const vec4& dir);
	vec4 at(float t);
	Ray reflected(vec4 N, float t);

private:
	vec4 orig;
	vec4 dir;
};

#endif // !__RAY_HPP__
