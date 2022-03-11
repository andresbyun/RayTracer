/* Include statements */
#include <main.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <Ray.hpp>
#include <Camera.hpp>
#include <glm/glm.hpp>

/* Using statements */
using std::cout;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::vector;
using glm::vec3;
using glm::vec4;
using glm::mat4;
using std::string;

/* Main function */
int main(int argc, char** argv) {
	cout << "Hello, RayTracer" << endl;

	Camera eye(250, 250, 1, vec3(0, 0, -1), vec3(0, 1, 0), vec3(0));

	// Generate the ppm
	save_ppm();

	// Convert ppm to png
	string pyCmd = "python3 scripts/fileGen.py";
	system(pyCmd.c_str());
	cout << "File generation completed!" << endl;

	return 0;
}

/* Create the output ppm
 * Saves it as "tmp/out.ppm"
 */
void save_ppm() {
	string name("tmp/out.ppm");
	ofstream file(name, ios_base::out | ios_base::binary);

	int width = 256;
	int height = 256;

	file << "P6\n"
		<< width << ' ' << height << '\n'
		<< 255 << '\n';

	for (int j = height - 1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			vec3 color(
				float(i) / 255.0f, 
				float(j) / 255.0f,
				0.25
			);

			color *= 255.999f;
			file << (char) color.r << (char) color.g << (char) color.b;
		}
	}

	file.close();
}

// Returns a vector containing the tokens
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
