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

    cout << "San Ramon AQI using std::array" << endl;
    cout << "size: " << aqi.size() << endl;
    cout << "max_size: " << aqi.max_size() << endl;
    cout << "empty: " << aqi.empty() << endl;
    cout << "front: " << aqi.front() << endl;
    cout << "back: " << aqi.back() << endl;

    int minV = aqi.front();
    int maxV = aqi.front();
    int sum = 0;
    int unhealthy = 0;
    for (int i = 0; i < static_cast<int>(aqi.size()); i++) {
        int v = aqi[i];
        sum += v;
        if (v < minV) {
            minV = v;
        }
        if (v > maxV) {
            maxV = v;
        }
        if (v > 100) {
            unhealthy++;
        }
    }

    cout << "min: " << minV << endl;
    cout << "max: " << maxV << endl;
    cout << "avg: " << (sum / static_cast<int>(aqi.size())) << endl;
    cout << "days over 100 AQI: " << unhealthy << endl;

    return 0;
}
