#ifndef INTERFACE_H
#define INTERFACE_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <vector>


class TInterface : public QWidget {
private:
    Q_OBJECT

    std::vector<QLabel*> delims;
    std::vector<std::vector<std::vector<QLineEdit*>>> nums;

    QPushButton *btnPrint;
    QPushButton *btnDeterminant;
    QPushButton *btnRank;
    QPushButton *btnTranspose;

    QLabel *output;

    int matrixSize;

public:
    explicit TInterface(QWidget *parent = nullptr);
    ~TInterface() override;

public slots:
    void ans(QString);

private slots:
    void formRequest();

signals:
    void request(QString);
};


#endif // INTERFACE_H
