#include "tcpdownload.h"

TCPDownload::TCPDownload(QObject *parent) : QObject(parent)
{

}

void TCPDownload::connectDownload(QString ip, int port )
{
    constIP = ip;
    constPort = port;
    mp_clientSocket->connectToHost(constIP, constPort);

    connect(mp_clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));

}

bool TCPDownload::downloadName(QString name)
{
    std::string str = name.toStdString();
    const char* ch = str.c_str();
    mp_clientSocket->write(ch, strlen(ch));
    file->setFileName("copy-get-123.png");
    QJsonParseError json_error;
    QJsonDocument json_doc =             QJsonDocument::fromJson(name.toLocal8Bit().data(),&json_error);
    qDebug()<<json_doc["downloadName"].toString();
    qDebug()<<"准备接受文件";
    return 0;
}

int i = 0;
void TCPDownload::ClientRecvData()
{
    //将接收内容存储到字符串中
        qDebug()<<"进入下载";
        if(!file->open(QIODevice::Append))
        {
            qDebug()<< "文件打开失败";

        }
        else
        {
            qDebug()<< "文件打开成功";
        }

        qint64 pos;
        pos = file->size();
        //重新定位文件输入位置，这里是定位到文件尾端
        file->seek(pos);

        QByteArray inBlock;
        inBlock = mp_clientSocket->readAll();	//读入所有数据
        file->write(inBlock);	//写入文件
        inBlock.resize(0);
        qDebug()<<"下载中:"<< i++;
        file->close();

}
