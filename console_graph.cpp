#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


float f(auto x) {
    return sin(x);
}


vector<vector<string>> createAxis(vector<vector<string>>& plane, int radius) {
    plane[radius / 2] = vector<string>(radius, "-");
    for (size_t i = 0; i < plane.size(); i++) {
        plane[i][radius / 2] = "|";
    }
    plane[radius / 2][radius / 2] = "+";
    return plane;
}

void plotGraph(int accuracy, vector<vector<string>>& plane, int radius, int scale) {
    for (int x = -radius / 2; x <= radius / 2; x++) {
        for (int y = -radius / 2; y <= radius / 2; y++) {
            try {
                if (abs(y / scale - f(x/scale)) <= 1.0 / accuracy) {
                    plane[y + radius / 2][x + radius / 2] = "$";
                }
            } catch (...) {
                // Ignore any exceptions
            }
        }
    }
    for (auto it = plane.rbegin(); it != plane.rend(); it++) {
        for (const auto& element : *it) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int radius = 21;
    int accuracy = 2;
    int scale = 1;
    vector<vector<string>> plane(radius, vector<string>(radius, "."));
    vector<vector<string>> axis(createAxis(plane, radius));
    plotGraph(accuracy, axis, radius, scale);
    return 0;
}