
#include <iostream>
#include <iomanip> // for std::setprecision and std::fixed

int main()
{
    double a = 0.1;
    double b = 0.2;
    double c = 0.3;

    if (a + b == c)
        std::cout << "true";
    else
        std::cout << "false";
    std::cout << "\n\n";

    float a1 = 3.14f;
    // float b1 = 1e20f;
    float b1 = 1e22f;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "(a1 + b1) - b1 = " << (a1 + b1) - b1 << '\n';

    std::cout << "16777224.0f == 16777225.0f ? "
              << (16777224.0f == 16777225.0f ? "true" : "false")
              << '\n';

    return 0;
}

// #include <iostream>
// #include <iomanip>
// #include <cmath> // for round()

// // Simple fixed-point type: fixed<16, 8> (8 bits for fraction)
// class FixedPoint {
// private:
//     int value;               // stored integer value
//     static const int scale = 1 << 8; // 2^8 = 256

// public:
//     FixedPoint() : value(0) {}
//     FixedPoint(float f) { value = std::round(f * scale); }

//     float toFloat() const { return static_cast<float>(value) / scale; }

//     // arithmetic operators
//     FixedPoint operator+(const FixedPoint& other) const {
//         FixedPoint result;
//         result.value = this->value + other.value;
//         return result;
//     }

//     FixedPoint operator-(const FixedPoint& other) const {
//         FixedPoint result;
//         result.value = this->value - other.value;
//         return result;
//     }

//     FixedPoint operator*(const FixedPoint& other) const {
//         FixedPoint result;
//         long temp = static_cast<long>(this->value) * other.value;
//         result.value = static_cast<int>(temp / scale);
//         return result;
//     }

//     FixedPoint operator/(const FixedPoint& other) const {
//         FixedPoint result;
//         long temp = (static_cast<long>(this->value) * scale) / other.value;
//         result.value = static_cast<int>(temp);
//         return result;
//     }
// };

// // Utility to print values side by side
// void printComparison(float a, float b, const std::string& label)
// {
//     std::cout << std::fixed << std::setprecision(6);
//     std::cout << label << ": " << a << " (float), " << b << " (fixed)\n";
// }

// int main()
// {
//     // --- Floating point arithmetic ---
//     float f1 = 2.5f;
//     float f2 = 1.25f;
//     float f_sum = f1 + f2;
//     float f_mul = f1 * f2;

//     // --- Fixed point arithmetic ---
//     FixedPoint x1(2.5f);
//     FixedPoint x2(1.25f);
//     FixedPoint x_sum = x1 + x2;
//     FixedPoint x_mul = x1 * x2;

//     // --- Print comparison ---
//     printComparison(f_sum, x_sum.toFloat(), "Sum  (2.5 + 1.25)");
//     printComparison(f_mul, x_mul.toFloat(), "Mult (2.5 * 1.25)");

//     // --- Precision test ---
//     FixedPoint small(0.003f);
//     FixedPoint big(10000.0f);
//     FixedPoint result = big + small;

//     std::cout << "\nPrecision test:\n";
//     std::cout << "10000.0f + 0.003f = "
//               << (10000.0f + 0.003f) << " (float)\n";
//     std::cout << "10000 + 0.003 = "
//               << result.toFloat() << " (fixed)\n";

//     return (0);
// }
