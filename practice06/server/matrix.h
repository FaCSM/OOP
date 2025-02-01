#ifndef OOP_TMatrix_H
#define OOP_TMatrix_H

#include <iostream>
#include <QString>
#include <vector>



template <class number>
class TMatrix {
public:
    TMatrix();
    explicit TMatrix(unsigned short, unsigned short);

    void setValues(std::vector<std::vector<number>>&);
    void setSize(unsigned short, unsigned short);
    [[nodiscard]] unsigned short getSizeX() const;
    [[nodiscard]] unsigned short getSizeY() const;

    template <typename T>
    friend QString& operator<< (QString&, TMatrix<T>&);

    void transpose();
    unsigned int getRank();

protected:
    void toUpperTriangularForm();
    unsigned short sizeX;
    unsigned short sizeY;
    std::vector<std::vector<number>> values;
};


template <class number>
TMatrix<number>::TMatrix() {
    sizeX = 3;
    sizeY = 3;
    values.resize(sizeX, std::vector<number>(sizeY, 0));
}


template <class number>
TMatrix<number>::TMatrix(unsigned short x, unsigned short y) {
    sizeX = x;
    sizeY = y;
    values.resize(sizeX, std::vector<number>(sizeY, 0));
}


template <class number>
void TMatrix<number>::setValues(std::vector<std::vector<number>>& newValues) {
    if (newValues.size() != sizeX && newValues[0].size() != sizeY)  {
        std::cout << "Wrong size. Matrix wasn't updated\n";
        return;
    }

    values = newValues;
}


template <class number>
void TMatrix<number>::setSize(unsigned short newX, unsigned short newY) {
    // Wrong size error
    if (newX <= 0 || newY <= 0) {
        std::cout << "Wrong size. Matrix wasn't updated\n";
        return;
    }

    if (newX == sizeX && newY == sizeY) {
        // No changes. Return
        return;
    } else if (newX < sizeX && newY < sizeY) {
        values.resize(newX, std::vector<number>(newY));
        sizeX = newX;
        sizeY = newY;
    } else {


        std::vector<std::vector<number>> newValues(newX, std::vector<number>(newY, 0));

        for (unsigned short i = 0; i < sizeX; ++i)
            for (unsigned short j = 0; j < sizeY; ++j)
                newValues[i][j] = values[i][j];

        values = newValues;
        sizeX = newX;
        sizeY = newY;
    }
}


template <class number>
unsigned short TMatrix<number>::getSizeX() const {
    return sizeX;
}

template <class number>
unsigned short TMatrix<number>::getSizeY() const {
    return sizeY;
}


template <class number>
QString& operator<< (QString& os, TMatrix<number>& matrix) {
    unsigned short rows = matrix.getSizeX();
    unsigned short cols = matrix.getSizeY();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            os << matrix.values[i][j];
            os += "\t";
        }
        os += "\n";
    }
    return os;
}


template <class number>
void TMatrix<number>::toUpperTriangularForm() {

    int rowsUpdated = 0;
    for (int pC = 0; pC < sizeX; ++pC) {

        int pR = -1;
        for (int i = pC; i < sizeY; ++i) {
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


        for (int i = pR + 1; i < sizeX; ++i) {
            number factor = values[i][pC] / values[pR][pC];
            for (int j = pC; j < sizeY; ++j) {
                values[i][j] = values[i][j] - values[pR][j] * factor;
            }
        }

        rowsUpdated++;
        if (rowsUpdated == sizeY - 1) break;
    }
}


template <class number>
unsigned int TMatrix<number>::getRank() {

    TMatrix upperMatrix(sizeX, sizeY);
    for (int i = 0; i < sizeX; ++i)
        for (int j = 0; j < sizeY; ++j)
            upperMatrix.values[i][j] = values[i][j];

    upperMatrix.toUpperTriangularForm();

    unsigned int rank = 0;
    for (int i = 0; i < sizeX; ++i)
        for (int j = i; j < sizeY; ++j)
            if (upperMatrix.values[i][j] != 0) {
                rank++;
                break;
            }
    return rank;
}

template <class number>
void TMatrix<number>::transpose() {
    for (int i = 0; i < sizeX; ++i)
        for (int j = i + 1; j < sizeY; ++j)
            std::swap(values[i][j], values[j][i]);
}


#endif //OOP_TMATRIX_H
