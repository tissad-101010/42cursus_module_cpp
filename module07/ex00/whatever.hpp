#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

// Swap function: Swaps the values of two given arguments
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Min function: Returns the smallest of two arguments
template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

// Max function: Returns the greatest of two arguments
template <typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#endif // __WHATEVER_HPP__
