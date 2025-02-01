#ifndef OOP_MYCOMP_H
#define OOP_MYCOMP_H

#include <iostream>
#include <QString>


class Complex {
private:
    static QChar SEPARATOR;
    double real, image;

public:
    Complex();
    Complex(const double&);
    Complex(const double&, const double&);
    explicit Complex(const QByteArray&);

    friend std::istream& operator>> (std::istream&, Complex&);
    friend std::ostream& operator<< (std::ostream&, Complex);
    friend QString& operator<< (QString&, Complex);
    friend QByteArray& operator>> (QByteArray&, Complex&);

    Complex operator+ (Complex) const;
    Complex operator- (Complex) const;
    Complex operator* (Complex) const;
    Complex operator/ (Complex) const;

    bool operator== (Complex num) const;
    bool operator!= (Complex num) const;
};


#endif
