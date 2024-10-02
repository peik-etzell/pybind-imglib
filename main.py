#!/usr/bin/env python3

from build.imglib import change_image
from PIL import Image


def main():
    im = Image.open("test.jpg")
    print("Image:", im.format, im.size, im.mode)

    print("Showing before")
    im.show()
    change_image(im)
    print("Showing after")
    im.show()

    # change_image(["hello world"]) # Invalid argument


if __name__ == "__main__":
    main()
