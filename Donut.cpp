#include <iostream>
#include <string>
#include <cmath>
#include <thread>
#include <chrono>
#include <vector>
#include <conio.h>

using namespace std;

// Function to set the color based on user input
string setColor(string color) {
    if (color == "red") {
        return "\033[31m";
    }
    else if (color == "green") {
        return "\033[32m";
    }
    else if (color == "yellow") {
        return "\033[33m";
    }
    else if (color == "blue") {
        return "\033[34m";
    }
    else if (color == "magenta") {
        return "\033[35m";
    }
    else if (color == "cyan") {
        return "\033[36m";
    }
    else if (color == "white") {
        return "\033[37m";
    }
    // Default to white if no valid color is chosen
    return "\033[37m";
}

int main() {
    float A = 0, B = 0, i, j;
    float size;
    string colorInput;
    cout << "Enter size (1-10): ";
    cin >> size;
    cout << "Enter color (e.g., red, green, blue): ";
    cin >> colorInput;

    string color = setColor(colorInput); // Set color

    float multiplier{ size / 5.0f };
    float sizeMultiplier{ multiplier < 1 ? 1.0f : multiplier };
    int length{ 80 }, width{ 24 };
    int scale{ static_cast<int>(length * width * sizeMultiplier * sizeMultiplier) };
    vector<char> b(scale, ' ');
    vector<float> z(scale, 0);
    cout << "\x1b[2J" << color;
    for (;;) {
        if (_kbhit()) {             
            char key = _getch();    
            if (key == 27) {        
                break;              
            }
        }
        fill(b.begin(), b.end(), ' ');
        fill(z.begin(), z.end(), 0);
        for (j = 0; 6.28 > j; j += 0.07)
            for (i = 0; 6.28 > i; i += 0.02) {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j),
                    g = cos(A), h = d + 2, D = 1 / (c * h * e + f * g + 5),
                    l = cos(i), m = cos(B), n = sin(B),
                    t = c * h * g - f * e;
                int x = (length / 2 * sizeMultiplier) + 30 * multiplier * D * (l * h * m - t * n),
                    y = (width / 2 * sizeMultiplier) + 15 * multiplier * D * (l * h * n + t * m),
                    o = x + static_cast<int>(80 * sizeMultiplier) * y,
                    N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (width * sizeMultiplier > y && y >= 0 && x >= 0 && length * sizeMultiplier > x && o >= 0 && o < scale && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        cout << "\x1b[H";

        std::string output{};
        output.reserve(scale + width * sizeMultiplier);
        for (int k = 0; (scale) > k; k++) {
            output += b[k];
            if ((k + 1) % static_cast<int>(length * sizeMultiplier) == 0) {
                output += '\n';
            }
        }
        std::cout << output << std::flush;
        A += 0.04;
        B += 0.02;
        std::this_thread::sleep_for(std::chrono::milliseconds (10));
    }
    return 0;
}




