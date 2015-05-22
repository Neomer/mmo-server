#ifndef NETSERVER
#define NETSERVER

#include <QTcpServer>
#include <QList>
#include "netclient.h"

namespace MMO_SERVER
{

namespace Network
{

class NetServer : public QTcpServer
{
    Q_OBJECT
    
public:
    NetServer() : 
        QTcpServer(this)
    {
        connect(this, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    }

private slots:
    void acceptConnection()
    {
        QTcpSocket * so = this->nextPendingConnection();
        // TODO Проверка подключения
        // -TODO
        
        __cl.append(new NetClient(so));
    }
    
private:
    QList<NetClient *> __cl;

};

}

}

#endif // NETSERVER

