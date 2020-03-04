#include <QApplication>
#include "tcpclient.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TCPClient Client;
    Client.show();
    return app.exec();
}
