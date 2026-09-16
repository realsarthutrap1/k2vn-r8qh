// COMSC-210 | Lab 9 | Sarthak Pani
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
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

    array<int, DAYS> backup = aqi;
    aqi.fill(0);
    cout << "after fill, front: " << aqi.front() << endl;
    aqi.swap(backup);
    cout << "after swap, front: " << aqi.front() << endl;

    cout << endl << "San Ramon AQI using std::vector" << endl;
    vector<int> aqiVec;
    aqiVec.reserve(DAYS);
    ifstream in2("aqi.txt");
    int val;
    while (in2 >> val) {
        aqiVec.push_back(val);
    }
    in2.close();

    cout << "vector size: " << aqiVec.size() << endl;
    cout << "vector capacity: " << aqiVec.capacity() << endl;
    cout << "vector empty: " << aqiVec.empty() << endl;
    cout << "vector front: " << aqiVec.front() << endl;
    cout << "vector back: " << aqiVec.back() << endl;
    cout << "vector at(14): " << aqiVec.at(14) << endl;

    int vSum = 0;
    int vMax = aqiVec.front();
    for (int i = 0; i < static_cast<int>(aqiVec.size()); i++) {
        vSum += aqiVec[i];
        if (aqiVec[i] > vMax) {
            vMax = aqiVec[i];
        }
    }
    cout << "vector max: " << vMax << endl;
    cout << "vector avg: " << (vSum / static_cast<int>(aqiVec.size())) << endl;

    aqiVec.pop_back();
    cout << "after pop_back, size: " << aqiVec.size() << endl;

    return 0;
}

// array half uses size, max_size, empty, at, [], front, back, fill, swap, data via front
// vector half uses reserve, push_back, size, capacity, empty, front, back, at, pop_back
