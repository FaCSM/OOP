#include "matrix.h"
#include <cmath>

TMatrix::TMatrix() {
    size = 3;
    values.resize(size, std::vector<number>(size, 0));
}

TMatrix::TMatrix(unsigned short size) : size(size) {
    values.resize(size, std::vector<number>(size, 0));
}

void TMatrix::setValues(std::vector<std::vector<number>>& newValues) {

    if (newValues.size() != size) {
        std::cout << "Size wrong. No updates\n";
        return;
    }

    values = newValues;
}

void TMatrix::setSize(unsigned short newSize) {

    if (newSize <= 0) {
        std::cout << "Size wrong. No updates\n";
        return;
    }

    if (newSize == size) {
        return;
    } else if (newSize < size) {
        values.resize(newSize, std::vector<number>(newSize));
        size = newSize;
    } else {


        std::vector<std::vector<number>> newValues(newSize, std::vector<number>(newSize, 0));

        for (unsigned short i = 0; i < size; ++i)
            for (unsigned short j = 0; j < size; ++j)
                newValues[i][j] = values[i][j];

        values = newValues;
        size = newSize;
    }
}

unsigned short TMatrix::getSize() const {
    return size;
}


QString& operator<< (QString& os, TMatrix& mtrx) {
    unsigned short N = mtrx.getSize();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            os << mtrx.values[i][j];
            os += "\t";
        }
        os += "\n";

    }
    return os;
}


void TMatrix::toUpperTriangularForm() {
    int rowsUpdated = 0;
    for (int pC = 0; pC < size; ++pC) {

        int pR = -1;
        for (int i = pC; i < size; ++i) {
            if (values[i][pC] != 0) {
                pR = i;
                break;
            }
        }

        if (pR == -1) continue;

        if (pR != rowsUpdated) {
            std::swap(values[rowsUpdated], values[pR]);
            pR = rowsUpdated;
        }


        for (int i = pR + 1; i < size; ++i) {
            number factor = values[i][pC] / values[pR][pC];
            for (int j = pC; j < size; ++j) {
                values[i][j] = values[i][j] - values[pR][j] * factor;
            }
        }

        rowsUpdated++;
        if (rowsUpdated == size - 1) break;
    }
}

number TMatrix::getDeterminant() {
    TMatrix upperMatrix(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            upperMatrix.values[i][j] = values[i][j];

    upperMatrix.toUpperTriangularForm();

    number determinant(1);
    for (int i = 0; i < size; ++i)
        determinant = determinant * upperMatrix.values[i][i];
    return determinant;
}

unsigned int TMatrix::getRank() {
    TMatrix upperMtrx(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            upperMtrx.values[i][j] = values[i][j];

    upperMtrx.toUpperTriangularForm();

    unsigned int rank = 0;
    for (int i = 0; i < size; ++i)
        for (int j = i; j < size; ++j)
            if (upperMtrx.values[i][j] != 0) {
                rank++;
                break;
            }
    return rank;
}

void TMatrix::transpose() {
    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size; ++j)
            std::swap(values[i][j], values[j][i]);
}
