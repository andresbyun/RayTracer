#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <glm/glm.hpp>
#include <Ray.hpp>

using glm::vec3;

class Camera {
public:
	Camera(int width, int height, float focalLen, vec3 eye, vec3 up, vec3 lookAt);
	Ray getRay(float u, float v);

private:
	int width, height;
	float aspectRatio, focalLen;
	vec3 eye, up, lookAt, uAxis, vAxis, wAxis;
};

#endif // !__CAMERA_HPP__
