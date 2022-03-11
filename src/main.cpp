/* Include statements */
#include <main.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

	// Generate the ppm
	save_ppm();

	// Convert ppm to png
	string pyCmd = "python3 scripts/fileGen.py";
	for (int i = 1; i < argc; i++) {
		pyCmd += ' ';
		pyCmd.append(argv[i]);
	}
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
