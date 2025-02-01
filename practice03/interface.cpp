#include "interface.h"
#include "matrix.h"
#include <vector>


const int WINDOW_SIZE_X = 400;
const int WINDOW_SIZE_Y = 420;


TInterface::TInterface(QWidget *parent, int size) : QWidget(parent) {
    setWindowTitle("Practical №3");
    setFixedSize(WINDOW_SIZE_X, WINDOW_SIZE_Y);

    matrSize = size;

    nums.resize(size);
    delimeters.resize(size*size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            nums[i].resize(size);
            nums[i][j].resize(2);

            nums[i][j][0] = new QLineEdit("0", this);
            nums[i][j][0]->setGeometry(70 * j + 10, 40 * i + 10, 25, 25);

            delimeters[i+j] = new QLabel(" /", this);
            delimeters[i+j]->setGeometry(70*j + 35, 40*i + 10, 10, 25);

            nums[i][j][1] = new QLineEdit("0", this);
            nums[i][j][1]->setGeometry(70 * j + 45, 40 * i + 10, 25, 25);
        }
    }

    print_btn = new QPushButton("Print", this);
    print_btn->setGeometry(10, 210, 60, 30);
    determ_btn = new QPushButton("Determ.", this);
    determ_btn->setGeometry(10, 250, 60, 30);
    rank_btn = new QPushButton("Rank", this);
    rank_btn->setGeometry(10, 290, 60, 30);
    transp_btn = new QPushButton("Transpose", this);
    transp_btn->setGeometry(10, 330, 60, 30);

    output = new QLabel("", this);
    output->setGeometry(80, 210, 270, 150);
    output->setStyleSheet("QLabel { background-color : black; color : white; }");

    connect(print_btn, SIGNAL(pressed()), this, SLOT(print()));
    connect(determ_btn, SIGNAL(pressed()), this, SLOT(determinant()));
    connect(rank_btn, SIGNAL(pressed()), this, SLOT(rank()));
    connect(transp_btn, SIGNAL(pressed()), this, SLOT(transpose()));
}


TInterface::~TInterface() {
    for (auto &delim : delimeters)
        delete delim;
    for (auto &row : nums)
        for (auto &col : row)
            for (auto &el : col)
                delete el;

    delete print_btn;
    delete determ_btn;
    delete rank_btn;
    delete transp_btn;

    delete output;
}


std::vector<std::vector<number>> TInterface::getValues() {
    std::vector<std::vector<number>> vals(matrSize, std::vector<number>(matrSize, 0));

    for (int i = 0; i < matrSize; ++i) {
        for (int j = 0; j < matrSize; ++j) {
            number value(nums[i][j][0]->text().toDouble(), nums[i][j][1]->text().toDouble());
            vals[i][j] = value;
        }
    }

    return vals;
}


void TInterface::print() {
    std::vector<std::vector<number>> values = getValues();
    TMatrix mtrx(matrSize);
    mtrx.setValues(values);
    QString output_text("");
    output_text << mtrx;
    output->setText(output_text);
}


void TInterface::determinant() {
    std::vector<std::vector<number>> values = getValues();
    TMatrix mtrx(matrSize);
    mtrx.setValues(values);
    QString output_text("");
    output_text << mtrx.getDeterminant();
    output->setText(output_text);
}


void TInterface::rank() {
    std::vector<std::vector<number>> values = getValues();
    TMatrix mtrx(matrSize);
    mtrx.setValues(values);
    QString output_text("");
    output_text += std::to_string(mtrx.getRank());
    output->setText(output_text);
}


void TInterface::transpose() {
    std::vector<std::vector<number>> values = getValues();
    TMatrix mtrx(matrSize);
    mtrx.setValues(values);
    mtrx.transpose();
    QString output_text("");
    output_text << mtrx;
    output->setText(output_text);
}
