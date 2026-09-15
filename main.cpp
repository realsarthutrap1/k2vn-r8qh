// COMSC-210 | Lab 9 | Sarthak Pani
#include <iostream>
#include <fstream>
#include <array>
using namespace std;

const int DAYS = 31;

int main() {
    // San Ramon CA daily AQI, 31 days
    array<int, DAYS> aqi{};

    ifstream in("aqi.txt");
    for (int i = 0; i < DAYS; i++) {
        in >> aqi[i];
    }

    return 0;
}
