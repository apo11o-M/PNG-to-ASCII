# PNG-to-ASCII
---
## Convert Image to ASCII Art

## What is this?
PNG-to-ASCII is a small C++ program that can convert png images into a text output
that resembles the input image using characters from the ASCII table.


## How do I use it?
There are two ways of running this program.

**The easy/lazy way:**
- Clone this repository.
- Locate the repo in the windows terminal.
- Run the executable, and pass the image path as the parameter. Like so:
  `.\PNG-to-ASCII.exe "C:\Users\Name\Desktop\target_image.png"`.
- The program will print the result in the `result.txt` file located in the same
  directory as the executable.

**Or if you want to compile the program yourself:**
- Close the repository
- navigate to the repo's directory,
- compile the file like so: `g++ -I Dependencies\CImg-2.9.5_pre122220 PNG-to-ASCI.cpp
  -lgdi32 -o PNG-to-ASCII`, be sure to add the search path to the CImg library
  header files located in the `Dependencies` folder.
- Run the program as stated above.


## How does it work?
PNG-to-ASCII is quite simple on how it works, here's the basic idea & steps

- Resize the image to a smaller dimension, but also maintaining the aspect ratio
- Convert the image to grayscale, so each pixel can be represented as numbers (0
  ~ 255) for the intensity.
- Create a list of special characters, and categorize each of them to a range of
  the intensity.
- Create a 2D vector filled with the special characters with each of the elements
  represent as pixels
- Print the 2D vector in a txt file (result.txt)
- Profit!!
