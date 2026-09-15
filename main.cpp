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
    if (!in) {
        cout << "Could not open aqi.txt" << endl;
        return 1;
    }

    for (int i = 0; i < DAYS; i++) {
        in >> aqi.at(i);
    }
    in.close();

    cout << "Day 1 AQI: " << aqi.at(0) << endl;
    cout << "Day 15 AQI: " << aqi.at(14) << endl;

    return 0;
}
