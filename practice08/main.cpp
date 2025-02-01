#include "parser.h"
#include "sample-switcher.h"
#include "interface.h"

#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TParser pars;
    TSampleSwitcher sample(&pars);
    TInterface interface(&sample);
    interface.show();

    return app.exec();
}
