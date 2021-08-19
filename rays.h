//
// Created by leach on 7/28/2021.
//
#include <vector>
#include <iostream>
#include <fstream>
#ifndef RAYTRACING_RAYS_H
#define RAYTRACING_RAYS_H

using std::vector;
using std::cout;

struct Pixel {
    size_t size() {
       return 3;
    }
    uint8_t r, g, b;
};
class Rays {
public:
    size_t rows;
    size_t cols;
    std::fstream file;
    vector<vector<Pixel>> pixels;
    Rays(size_t rows, size_t cols)
    : rows(rows), cols(cols) {
        for (int r = 0; r < rows; ++r) {
            pixels.emplace_back(vector<Pixel>(cols));
            for (int c = 0; c < cols; ++c) {
                pixels[r][c] = Pixel{0, 0, 0};
            }
        }
        file.open("testfile.txt", std::fstream::out);
        if(file.is_open()) {
            startingGradient();
            print();
        } else {
            cout << "You're a failure\n";
        }
    }
    void startingGradient() {
        int rIdx = 0;
        int cIdx = 0;
        for (auto& r : pixels) {
            cout << r.size() << "\n";
            for (auto& c : r) {
                cout << c.size() << "\n";
                float rRatio = float(rIdx) / float(rows);
                float cRatio = float(cIdx) / float(cols);
                c.r = int(255.99* rRatio);
                c.g = int(255.99*cRatio);
                c.b = int(0.2 * 255.99);
                cIdx++;
            }
            rIdx++;
        }
    }
    void print() {
        file << "P3\n" << rows << " " << cols << "\n255\n";
        for (auto& r : pixels) {
            for (auto& c : r) {
                file << c.r << " " << c.g << " " << c.b << "\n";
            }
        }
        file.flush();
        file.close();
    }
};


#endif //RAYTRACING_RAYS_H
