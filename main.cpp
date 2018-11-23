#include "dialog.h"
#include <QApplication>
#include "tcpdownload.h"

QString IP = "127.0.0.1";
int Port = 9993;
QString name = "{\"downloadName\": \"get-123.png\"}";
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TCPDownload tcp;
    tcp.connectDownload(IP, Port);
    tcp.downloadName(name);

    Dialog w;
    w.show();
    return a.exec();
}
