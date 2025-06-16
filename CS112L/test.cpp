#include <iostream>
#include <windows.h>  // Required for VK_UP and GetAsyncKeyState

using namespace std;

int main() {
    int n = 0;  // Initialize to avoid UB

    // Check if UP arrow key is pressed
    bool con = GetAsyncKeyState(VK_UP) & 0x8000;

    if (con) {
        n = n * 10;
        cout << "Num == " << n << endl;
    }

    return 0;
}