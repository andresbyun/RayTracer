/* Include statements */
#include <main.hpp>

#include <iostream>
#include <fstream>
#include <regex>
#include <Ray.hpp>

/* Using statements */
using std::cout;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::vector;
using glm::vec3;
using glm::vec4;
using glm::mat4;
using glm::normalize;
using std::string;

/* Main function */
int main(int argc, char** argv) {
	cout << "Hello, RayTracer" << endl;

	// Generate the ppm
	Camera eye(256, 256, 1, vec3(0, 0, 1), vec3(0, 1, 0), vec3(0));
	save_ppm(eye);

	// Convert ppm to png
	string pyCmd = "python3 scripts/fileGen.py";
	system(pyCmd.c_str());
	cout << "File generation completed!" << endl;

	return 0;
}

/* Create the output ppm
 * Saves it as "tmp/out.ppm"
 */
void save_ppm(Camera eye) {
	string name("tmp/out.ppm");
	ofstream file(name, ios_base::out | ios_base::binary);

	int width = eye.getWidth();
	int height = eye.getHeight();

	file << "P6\n"
		<< width << ' ' << height << '\n'
		<< 255 << '\n';

	for (int j = height - 1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			vec3 color = raytrace(eye.getRay(i, j)) * 255.999f;
			file << (char) color.r << (char) color.g << (char) color.b;
		}
	}

	file.close();
}

/* Return the color of the pixel */
vec3 raytrace(Ray r) {
	vec3 direction = normalize(r.at(1) - r.at(0));
	float t = 0.5 * (direction.y + 1.0);
	vec3 color = (1.0f - t) * vec3(1) + t * vec3(0, 1, 0);

	return color;
}

/* Return a vector containing the tokens */
vector<string> tokenize_line(string str) {
	const std::regex re(R"(\s+)");

	std::sregex_token_iterator it{ str.begin(), str.end(), re, -1 };
	vector<string> tokens{ it, {} };

	// Delete empty strings
	tokens.erase(
		std::remove_if(
			tokens.begin(),
			tokens.end(),
			[](string const& s) {
				return s.size() == 0;
			}),
		tokens.end()
	);

	return tokens;
}
