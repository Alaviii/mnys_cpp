#ifndef __AVIMATRIX_H__
#define __AVIMATRIX_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class matrix
{
public:
    matrix(std::size_t rows, std::size_t cols);
    matrix(std::string);                                            //roto, no abre

    double& operator()(const std::size_t i, const std::size_t j);
    double operator()(const std::size_t i, const std::size_t j) const;

    double& operator[](const std::size_t i);
    double operator[](const std::size_t i) const;

    void operator=(matrix);

    void resize(const std::size_t i, const std::size_t j);
    bool write(std::string);
    bool read(std::string);
    void print();

    std::size_t getRows() const;
    std::size_t getCols() const;

    matrix operator+(matrix);
    matrix operator-(matrix);
    matrix operator*(matrix);

    matrix transpose();

private:
    std::size_t mRows;
    std::size_t mCols;
    std::vector<double> mData;
};

#endif