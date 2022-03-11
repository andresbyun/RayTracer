#include <Ray.hpp>

/* Constructor */
Ray::Ray(const vec4& orig, const vec4& dir) :
	orig(orig), dir(dir) {}

/* Point of the ray at t */
vec4 Ray::at(float t) {
	return orig + (t * dir);
}

/* Get the reflected ray with the surface Normal and the new origin point t */
Ray Ray::reflected(vec4 N, float t) {
	vec4 P = this->at(t);
	vec4 v = dir - (2 * (glm::dot(N, dir)) * N);

	return Ray(P, v);
}
