#include <CImg.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace cimg_library;

// g++ -I Dependencies\CImg-2.9.5_pre122220 PNG-to-ASCII.cpp -lgdi32 -o PNG-to-ASCII
// .\PNG-to-ASCII.exe "C:\Path\image.png"

// The list of all the symbols, 70 total.
string symbolList = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"; 

// Convert the intensity (int) to the relative symbol
char intensityToChar(int intensity);


int main(int argc, char* argv[]) {
    cout << "Program running..." << endl;

    if (argc != 2) {
        cout << "Missing arguments: image path" << endl;
        cout << "Ex: PNG-to-ASCII.exe \"C:\\Users\\Name\\Desktop\\image.png\"" << endl;
        return 1;
    }
    
    CImg<unsigned char> image(argv[1]);
    
    int w = image.width();
    int h = image.height();
    // stores the symbol for each pixel
    vector<vector<char>> arr; 
    int lit = 0;
    char symb;

    // convert each pixel to an intensity int, and put the relative symbol into the vector.
    for (int j = 0; j < h; j++) {
        arr.push_back(vector<char>());
        for (int i = 0; i < w; i++) {
            arr.at(j).push_back(intensityToChar(image(i, j)));
        }
    }

    // setup the result.txt file
    ofstream resultFile;
    resultFile.open("result.txt");
    if (!resultFile.is_open()) {
        cout << "result.txt not opened" << endl;
        return 1;
    }

    // write the result vector elements into the result.txt 
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            resultFile << arr.at(j).at(i);
        }
        resultFile << "\n";
    } 
    cout << endl;

    cout << "Finished." << endl;
    resultFile.close();

    return 0;
} 


// convert the intensity value (int) into it's relative symbol
char intensityToChar(int input) {
    char result = ' ';

    input /= 3.642857;

    if (input < 70) {
        result = symbolList.at(input);
    } else if (input == 70) {
        result = symbolList.at(69);
    } else {
        cout << "unknown intensity value: " << input << endl;
    }

    return result;
}