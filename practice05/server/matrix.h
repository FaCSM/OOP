#ifndef OOP_TMatrix_H
#define OOP_TMatrix_H

#include "number.h"
#include <iostream>
#include <QString>
#include <vector>


/**
 * @class TMatrix
 * @brief Implementation of matrix
 * Implement an matrix with the following functionality:
 * init, print, calculate the determinant, calculate the rank, transpose
 */
class TMatrix {
public:
    TMatrix();
    explicit TMatrix(unsigned short, unsigned short);

    void setValues(std::vector<std::vector<number>>&);
    void setSize(unsigned short, unsigned short);
    [[nodiscard]] unsigned short getSizeX() const;
    [[nodiscard]] unsigned short getSizeY() const;

    friend QString& operator<< (QString&, TMatrix&);

    void transpose();
    unsigned int getRank();

protected:
    void toUpperTriangularForm();
    unsigned short sizeX;
    unsigned short sizeY;
    std::vector<std::vector<number>> values;
};


#endif //OOP_TMATRIX_H
