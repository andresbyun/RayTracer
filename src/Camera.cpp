#include <Camera.hpp>

using glm::vec4;
using glm::cross;
using glm::normalize;

/* Constructor */
Camera::Camera(int width, int height, float focalLen, vec3 eye, vec3 up, vec3 lookAt) :
	width(width), height(height), focalLen(focalLen), eye(normalize(eye)), up(normalize(up)), lookAt(normalize(lookAt)) {
	aspectRatio = float(width) / float(height);
	
	wAxis = normalize(lookAt - eye);
	vAxis = normalize(up);
	uAxis = normalize(cross(wAxis, vAxis));
}

/* Return the ray shot through a pixel with coordinates (u, v) */
Ray Camera::getRay(float u, float v) {
	float H = 1;
	float W = H * aspectRatio;

	vec3 dir =
		(-focalLen * wAxis) +
		(W * (((2 * u) / width) - 1) * uAxis) +
		(H * (((2 * v) / height) - 1) * vAxis);

	return Ray(
		vec4(eye, 1),
		vec4(dir, 0)
	);
}
