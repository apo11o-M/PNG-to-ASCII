#include <CImg.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace cimg_library;


int main() {
    cout << "Program running..." << endl;

    CImg<unsigned char> image("C:\\Users\\Rick Wang\\OneDrive\\Synced Documents\\ASCII Art\\images\\github_logo_small.png");
    //CImg<unsigned char> image("..images\\testing128x130.png");
    
    int w = image.width();
    int h = image.height();
    vector<vector<int>> arr; 
    
    for (int j = 0; j < h; j++) {
        arr.push_back(vector<int>());
        for (int i = 0; i < w; i++) {
            arr.at(j).push_back((int)image(i, j));
        }
    }

    ofstream resultFile;
    resultFile.open("result.txt");

    if (!resultFile.is_open()) {
        cout << "result.txt not opened" << endl;
        return 1;
    }

    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            resultFile << arr.at(j).at(i) << " ";
        }
        resultFile << "\n";
    } 
    cout << endl;
    cout << "Finished." << endl;

    resultFile.close();

    return 0;
} 