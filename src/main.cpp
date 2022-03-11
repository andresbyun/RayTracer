/* Include statements */
#include <main.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <glm/glm/glm.hpp>

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

	save_ppm();

	/* TODO: CONVERT THE PPM INTO A REASONABLE FILE FORMAT */
	string pyCmd = "python3 scripts/fileGen.py";
	
	for (int i = 1; i < argc; i++) {
		pyCmd += ' ';
		pyCmd.append(argv[i]);
	}

	system(pyCmd.c_str());
	
	return 0;
}

/* Create the output ppm */
void save_ppm() {
	string name("out.ppm");
	ofstream file(name, ios_base::out | ios_base::binary);

	int width = 256;
	int height = 256;

	file << "P3\n"
		<< width << ' ' << height << '\n'
		<< "255\n";

	for (int j = height - 1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			vec3 color(
				float(i) / (width - 1), 
				float(j) / (height - 1),
				0.25
			);

			color *= 255.999;

			file << (int) color.r << ' ' << (int) color.g << ' ' << (int) color.b << '\n';
		}
	}

	file.close();
}