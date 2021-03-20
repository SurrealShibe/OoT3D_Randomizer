#pragma once
#include <stdlib.h>
#include <random>
#include <array>

extern void Random_Init(unsigned int seed);
extern unsigned int Random(int min, int max);

template <typename T>
T RandomElement(std::vector<T> &vector, bool erase) {
    int idx = Random(0, vector.size());
    T selected = vector[idx];
    if(erase) {
        vector.erase(vector.begin() + idx);
    }
    return selected;
}

template <typename T, std::size_t size>
T RandomElement(std::array<T, size> arr) {
    return arr[Random(0, arr.size())];
}

template <typename T>
void Shuffle(std::vector<T> &vector) {
    for (uint i = 0; i + 1 < vector.size(); i++)
    {
        std::swap(vector[i], vector[Random(i, vector.size())]);
    }
}

template <typename T, std::size_t size>
void Shuffle(std::array<T, size> &arr) {
    for (uint i = 0; i + 1 < arr.size(); i++)
    {
        std::swap(arr[i], arr[Random(i, arr.size())]);
    }
}