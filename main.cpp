#include <QApplication>

#include "NumberSystem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    NumberSystem system;
    system.show();

    return app.exec();
}
