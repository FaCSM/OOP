#include "interface.h"
#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    bool noErr;
    QString userInput = QInputDialog::getText(nullptr, "Matrix size", "Enter size: ", QLineEdit::Normal, "", &noErr);

    if (noErr && !userInput.isEmpty()) {
        int size = userInput.toInt(&noErr);


        if (size > 5) {
            QMessageBox::critical(nullptr, "Err1", "Huge size");
            return -1;
        }


        if (size < 0) {
            QMessageBox::critical(nullptr, "Err2", "Too little size");
            return -2;
        }

        if (!noErr) {
            QMessageBox::critical(nullptr, "Err3", "Incorrect input");
            return -3;
        }

        TInterface w(nullptr, size);
        w.show();
        return a.exec();
    }

    return 0;
}
