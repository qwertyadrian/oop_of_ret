#pragma once

#ifndef OOP_OF_RET_MYCOMPLEX_H
#define OOP_OF_RET_MYCOMPLEX_H

#include <iostream>

class Complex {
    private:
        double real;
        double imag;

    public:
        Complex(double real, double imag) {
            this->real = real;
            this->imag = imag;
        }

        Complex(const Complex& other) {
            real = other.real;
            imag = other.imag;
        }

        Complex& operator=(const Complex& other) {
            real = other.real;
            imag = other.imag;
            return *this;
        }

        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }

        Complex operator+=(const Complex& other) {
            real += other.real;
            imag += other.imag;
            return *this;
        }

        Complex operator-(const Complex& other) const {
            return Complex(real - other.real, imag - other.imag);
        }

        Complex operator-=(const Complex& other) {
            real -= other.real;
            imag -= other.imag;
            return *this;
        }

        Complex operator*(const Complex& other) const {
            return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
        }

        Complex operator*=(const Complex& other) {
            double newReal = real * other.real - imag * other.imag;
            double newImag = real * other.imag + imag * other.real;
            real = newReal;
            imag = newImag;
            return *this;
        }

        Complex operator/(const Complex& other) const {
            double newReal = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
            double newImag = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
            return Complex(newReal, newImag);
        }

        Complex operator/=(const Complex& other) {
            double newReal = (real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag);
            double newImaginary = (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag);
            real = newReal;
            imag = newImaginary;
            return *this;
        }

        template <typename T>
        Complex operator+(const T& other) const {
            return Complex(real + other, imag);
        }

        template <typename T>
        Complex operator+=(const T& other) {
            real += other;
            return *this;
        }

        template <typename T>
        Complex operator-(const T& other) const {
            return Complex(real - other, imag);
        }

        template <typename T>
        Complex operator-=(const T& other) {
            real -= other;
            return *this;
        }

        template <typename T>
        Complex operator*(const T& other) const {
            return Complex(real * other, imag * other);
        }

        template <typename T>
        Complex operator*=(const T& other) {
            real *= other;
            imag *= other;
            return *this;
        }

        template <typename T>
        Complex operator/(const T& other) const {
            return Complex(real / other, imag / other);
        }

        template <typename T>
        Complex operator/=(const T& other) {
            real /= other;
            imag /= other;
            return *this;
        }

        [[nodiscard]] double getReal() const {
            return real;
        }

        [[nodiscard]] double getImag() const {
            return imag;
        }

        void print() const {
            printf("%f + %fi\n", real, imag);
        }
};

#endif // OOP_OF_RET_MYCOMPLEX_H
