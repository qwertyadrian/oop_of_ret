#pragma once

#ifndef OOP_OF_RET_INT8_H
#define OOP_OF_RET_INT8_H

#include <stdexcept>

/*
 * Классы int8_signed и int8_unsigned из двух short — левой части int и правой части int
 */

class Int8 {
    private:
        short left;
        short right;
    public:
        Int8(int value) {
            left = static_cast<short>(value >> 16);     // 0xFFFF0000
            right = static_cast<short>(value & 0xFFFF); // 0x0000FFFF
        }

        Int8(short left, short right) : left(left), right(right) {}

        Int8(const Int8 &other) = default;

        Int8& operator=(const Int8 & other) {
            if (this != &other) {
                left = other.left;
                right = other.right;
            }
            return *this;
        }

        Int8 operator+(const Int8& other) const {
            unsigned short r1 = static_cast<unsigned short>(right);
            unsigned short r2 = static_cast<unsigned short>(other.right);
            unsigned int newRight = r1 + r2;
            short carry = (newRight > 0xFFFF) ? 1 : 0;
            short newLeft = left + other.left + carry;
            return {newLeft, static_cast<short>(newRight & 0xFFFF)};
        }

        Int8 operator-(const Int8& other) const {
            unsigned short r1 = static_cast<unsigned short>(right);
            unsigned short r2 = static_cast<unsigned short>(other.right);
            unsigned int newRight = r1 - r2;
            short borrow = (r1 < r2) ? 1 : 0;
            short newLeft = left - other.left - borrow;
            return {newLeft, static_cast<short>(newRight & 0xFFFF)};
        }

        Int8 operator*(const Int8& other) const {
            short rLow1 = right & 0xFF;
            short rHigh1 = (right >> 8) & 0xFF;
            short rLow2 = other.right & 0xFF;
            short rHigh2 = (other.right >> 8) & 0xFF;

            int lowPart = rLow1 * rLow2;
            int midPart1 = rLow1 * rHigh2;
            int midPart2 = rHigh1 * rLow2;
            int highPart = rHigh1 * rHigh2;

            unsigned short newRight = (lowPart & 0xFFFF) + ((midPart1 & 0xFF) << 8) + ((midPart2 & 0xFF) << 8);
            short carry = (newRight > 0xFFFF) ? 1 : 0;
            short newLeft = left * other.right + other.left * right + (midPart1 >> 8) + (midPart2 >> 8) + highPart + carry;
            if (*this < 0 && other < 0) {
               newRight = -newRight;
            }
            return {newLeft, static_cast<short>(newRight & 0xFFFF)};
        }

        Int8 operator/(const Int8& other) const {
            if (other.left == 0 && other.right == 0) {
                throw std::invalid_argument("Division by zero");
            }
            int value = (left << 16) | (right & 0xFFFF);
            int otherValue = (other.left << 16) | (other.right & 0xFFFF);
            int result = value / otherValue;
            return {result};
            /* short resultLeft = 0;
            short resultRight = 0;
            short tempLeft = left;
            unsigned short tempRight = static_cast<unsigned short>(right);

            for (int i = 15; i >= 0; --i) {
                tempLeft = (tempLeft << 1) | (tempRight >> 15);
                tempRight = (tempRight << 1);

                if (tempLeft >= other.left || tempRight >= static_cast<unsigned short>(other.right)) {
                    tempLeft -= other.left;
                    tempRight -= other.right;
                    resultRight |= (1 << i);
                }
            }
            return {resultLeft, resultRight}; */
        }

        Int8 operator-() const {
            return Int8(~left, ~right) + Int8(1);
        }

        bool operator==(const Int8& other) const {
            return left == other.left && right == other.right;
        }

        bool operator!=(const Int8  other) const {
            return !(*this == other);
        }

        bool operator<(const Int8& other) const {
            return left < other.left || (left == other.left && right < other.right);
        }

        bool operator<=(const Int8& other) const {
            return *this < other || *this == other;
        }

        bool operator>(const Int8& other) const {
            return !(*this <= other);
        }

        bool operator>=(const Int8& other) const {
            return !(*this < other);
        }

        [[nodiscard]] short getLeft() const {
            return left;
        }

        [[nodiscard]] short getRight() const {
            return right;
        }

        [[nodiscard]] int getValue() const {
            return (left << 16) | (right & 0xFFFF);
        }
};

class UInt8 {
    private:
        unsigned short left;
        unsigned short right;

    public:
        UInt8(unsigned short l, unsigned short r) : left(l), right(r) {}
        UInt8(unsigned int value) {
            left = static_cast<unsigned short>(value >> 16);
            right = static_cast<unsigned short>(value & 0xFFFF);
        }
        UInt8(const UInt8 &other) = default;

        UInt8& operator=(const UInt8 & other) {
            if (this != &other) {
                left = other.left;
                right = other.right;
            }
            return *this;
        }

        UInt8 operator+(const UInt8& other) const {
            unsigned int newRight = right + other.right;
            unsigned short carry = (newRight > 0xFFFF) ? 1 : 0;
            unsigned short newLeft = left + other.left + carry;
            return {newLeft, static_cast<unsigned short>(newRight & 0xFFFF)};
        }

        UInt8 operator-(const UInt8& other) const {
            unsigned int newRight = right - other.right;
            unsigned short borrow = (right < other.right) ? 1 : 0;
            unsigned short newLeft = left - other.left - borrow;
            return {newLeft, static_cast<unsigned short>(newRight & 0xFFFF)};
        }

        UInt8 operator*(const UInt8& other) const {
            unsigned short rLow = right & 0xFF;
            unsigned short rHigh = (right >> 8) & 0xFF;
            unsigned short oLow = other.right & 0xFF;
            unsigned short oHigh = (other.right >> 8) & 0xFF;

            unsigned int lowPart = rLow * oLow;
            unsigned int midPart1 = rLow * oHigh;
            unsigned int midPart2 = rHigh * oLow;
            unsigned int highPart = rHigh * oHigh;

            unsigned int newRight = (lowPart & 0xFFFF) + ((midPart1 & 0xFF) << 8) + ((midPart2 & 0xFF) << 8);
            unsigned short carry = (newRight > 0xFFFF) ? 1 : 0;
            unsigned short newLeft = left * other.right + (midPart1 >> 8) + (midPart2 >> 8) + highPart + carry;

            return {newLeft, static_cast<unsigned short>(newRight & 0xFFFF)};
        }

        UInt8 operator/(const UInt8& other) const {
            if (other.left == 0 && other.right == 0) {
                throw std::invalid_argument("Division by zero");
            }

            unsigned short count = 0;
            UInt8 temp = *this;
            while (temp >= other) {
                temp = temp - other;
                count++;
            }

            return {count};

            /* unsigned int value = (left << 16) | right;
            unsigned int otherValue = (other.left << 16) | other.right;
            unsigned int result = value / otherValue;
            return {result}; */

            /* unsigned short resultLeft = 0;
            unsigned short resultRight = 0;
            unsigned short tempLeft = left;
            unsigned short tempRight = right;

            for (int i = 15; i >= 0; --i) {
                tempLeft = (tempLeft << 1) | (tempRight >> 15);
                tempRight = (tempRight << 1);

                if (tempLeft >= other.left || tempRight >= other.right) {
                    tempLeft -= other.left;
                    tempRight -= other.right;
                    resultRight |= (1 << i);
                }
            }

            return {resultLeft, resultRight}; */
        }

        bool operator==(const UInt8& other) const {
            return left == other.left && right == other.right;
        }

        bool operator!=(const UInt8& other) const {
            return !(*this == other);
        }

        bool operator<(const UInt8& other) const {
            if (left < other.left) return true;
            if (left > other.left) return false;
            return right < other.right;
        }

        bool operator<=(const UInt8& other) const {
            return *this < other || *this == other;
        }

        bool operator>(const UInt8& other) const {
            return !(*this <= other);
        }

        bool operator>=(const UInt8& other) const {
            return !(*this < other);
        }

        [[nodiscard]] unsigned short getLeft() const {
            return left;
        }

        [[nodiscard]] unsigned short getRight() const {
            return right;
        }

        [[nodiscard]] unsigned int getValue() const {
            return (static_cast<unsigned int>(left) << 16) | right;
        }
};

#endif // OOP_OF_RET_INT8_H
