/* Include statements */
#include <main.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <glm/glm/glm.hpp>

/* Using statements */
using std::cout;
using std::endl;
using std::vector;
using glm::mat4;
using glm::vec4;
using std::string;

/* Main function */
int main(int argc, char** argv) {
	cout << "Hello, RayTracer" << endl;

	string pyCmd = "python scripts/fileGen.py";
	
	for (int i = 1; i < argc; i++) {
		pyCmd += ' ';
		pyCmd.append(argv[i]);
	}

	system(pyCmd.c_str());
	
	return 0;
}
