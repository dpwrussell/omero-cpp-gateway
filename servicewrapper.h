#ifndef SERVICEWRAPPER_H
#define SERVICEWRAPPER_H

namespace gateway {

class BlitzGateway;

class ServiceWrapper
{
public:
    ServiceWrapper(BlitzGateway* connection);

protected:

    void resyncConnection();

    BlitzGateway* connection;
};

} // Namespace gateway
#endif // SERVICEWRAPPER_H
