#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <glm/glm.hpp>
#include <Ray.hpp>

class Camera {
public:
	Camera(int width, int height, float focalLen, glm::vec3 eye, glm::vec3 up, glm::vec3 lookAt);
	Ray getRay(float u, float v);
	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	int width, height;
	float aspectRatio, focalLen;
	glm::vec3 eye, up, lookAt, uAxis, vAxis, wAxis;
};

#endif // !__CAMERA_HPP__
