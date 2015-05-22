#ifndef NETCLIENT
#define NETCLIENT

#include <QTcpSocket>

namespace MMO_SERVER
{

namespace Network
{

enum ClientConnectionState
{
    CCS_Auth,
    CCS_Online
};

class NetClient : public QTcpSocket
{
    Q_OBJECT
    
public:
    NetClient(QTcpSocket * socket)
    {
        this->__so = socket;
        this->__st = CCS_Auth;
    }
    
    ClientConnectionState state() const
    {
        return __st;
    }

private:
    ClientConnectionState __st;
    QTcpSocket * __so;
    
};

}

}

#endif // NETCLIENT

