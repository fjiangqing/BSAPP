#ifndef TCPDOWNLOAD_H
#define TCPDOWNLOAD_H

#include <QObject>
#include <QtNetwork>
#include <QString>
#include <QtCore>
#include <QLabel>
#include <iostream>
#include <QDialog>
#include <QTextCodec>
#include <QTcpSocket>
#include "string.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QJsonDocument>

class TCPDownload : public QObject
{
    Q_OBJECT
public:
    explicit TCPDownload(QObject *parent = nullptr);
    QTcpSocket * mp_clientSocket = new QTcpSocket();
    QString constIP;
    int constPort;
    QFile *file = new QFile("py.png");
    void connectDownload(QString ip, int port );
    bool downloadName(QString name);
signals:

public slots:
    void ClientRecvData();
};

#endif // TCPDOWNLOAD_H
