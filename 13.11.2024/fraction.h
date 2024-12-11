#pragma once

#ifndef OOP_OF_RET_FRACTION_H
#define OOP_OF_RET_FRACTION_H

#include <iostream>

class Fraction {
    private:
        int numerator;
        int denominator;

        [[nodiscard]] int gcd(int a, int b) const {
            a = a < 0 ? -a : a;
            b = b < 0 ? -b : b;
            return b == 0 ? a : gcd(b, a % b);
        }

        void reduce() {
            int divisor = gcd(numerator, denominator);
            numerator /= divisor;
            denominator /= divisor;
        }

    public:
        Fraction(int numerator, int denominator) {
            if (denominator == 0) throw std::invalid_argument("Denominator can't be zero");
            if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
            }
            this->numerator = numerator;
            this->denominator = denominator;
        }

        Fraction(const Fraction& other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }

        Fraction& operator=(const Fraction& other) {
            numerator = other.numerator;
            denominator = other.denominator;
            return *this;
        }

        Fraction operator+(const Fraction& other) const {
            Fraction result = Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
            result.reduce();
            return result;
        }

        Fraction operator+=(const Fraction& other) {
            numerator = numerator * other.denominator + other.numerator * denominator;
            denominator *= other.denominator;
            reduce();
            return *this;
        }

        Fraction operator-(const Fraction& other) const {
            Fraction result = Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
            result.reduce();
            return result;
        }

        Fraction operator-=(const Fraction& other) {
            numerator = numerator * other.denominator - other.numerator * denominator;
            denominator *= other.denominator;
            reduce();
            return *this;
        }

        Fraction operator*(const Fraction& other) const {
            Fraction result = Fraction(numerator * other.numerator, denominator * other.denominator);
            result.reduce();
            return result;
        }

        Fraction operator*=(const Fraction& other) {
            numerator *= other.numerator;
            denominator *= other.denominator;
            reduce();
            return *this;
        }

        Fraction operator/(const Fraction& other) const {
            Fraction result = Fraction(numerator * other.denominator, denominator * other.numerator);
            result.reduce();
            return result;
        }

        Fraction operator/=(const Fraction& other) {
            numerator *= other.denominator;
            denominator *= other.numerator;
            reduce();
            return *this;
        }

        // Префиксный инкремент
        Fraction operator++() {
            numerator += denominator;
            reduce();
            return *this;
        }
        // Постфиксный инкремент
        Fraction operator++(int) {
            numerator += denominator;
            reduce();
            return *this;
        }
        // Префиксный декремент
        Fraction operator--() {
            numerator -= denominator;
            reduce();
            return *this;
        }
        // Постфиксный декремент
        Fraction operator--(int) {
            numerator -= denominator;
            reduce();
            return *this;
        }

        template <typename T>
        Fraction operator+(const T& other) const {
            Fraction result = Fraction(numerator + other * denominator, denominator);
            result.reduce();
            return result;
        }

        template <typename T>
        Fraction operator+=(const T& other) {
            numerator += other * denominator;
            reduce();
            return *this;
        }

        template <typename T>
        Fraction operator-(const T& other) const {
            Fraction result = Fraction(numerator - other * denominator, denominator);
            result.reduce();
            return result;
        }

        template <typename T>
        Fraction operator-=(const T& other) {
            numerator -= other * denominator;
            reduce();
            return *this;
        }

        template <typename T>
        Fraction operator*(const T& other) const {
            Fraction result = Fraction(numerator * other, denominator);
            result.reduce();
            return result;
        }

        template <typename T>
        Fraction operator*=(const T& other) {
            numerator *= other;
            reduce();
            return *this;
        }

        template <typename T>
        Fraction operator/(const T& other) const {
            if (other == 0) throw std::invalid_argument("Division by zero");

            int resultNumerator = other < 0 ? -numerator : numerator;
            int resultDenominator = (other < 0 ? -other : other) * denominator;

            Fraction result = Fraction(resultNumerator, resultDenominator);
            result.reduce();
            return result;
        }

        template <typename T>
        Fraction operator/=(const T& other) {
            if (other == 0) throw std::invalid_argument("Division by zero");
            numerator = other < 0 ? -numerator : numerator;
            denominator *= other < 0 ? -other : other;
            reduce();
            return *this;
        }

        [[nodiscard]] int lcm(const Fraction& other) const {
            return denominator * other.denominator / gcd(denominator, other.denominator);
        }

        void print() const {
            printf("%d/%d\n", numerator, denominator);
        }
};

#endif // OOP_OF_RET_FRACTION_H
