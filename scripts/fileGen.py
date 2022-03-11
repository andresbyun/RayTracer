
"""
Python script made to handle image file generation
"""

import sys
import os
from PIL import Image

# Convert the ppm file into a png
def main(argv):
    print("Generating png...")

    if not os.path.isdir('Output'):
        os.mkdir('Output')

    im = Image.open("tmp/out.ppm")
    im.save("Output/" + "out.png")

    os.remove("tmp/out.ppm")

if __name__ == "__main__":
    main(sys.argv)