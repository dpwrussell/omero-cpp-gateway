#ifndef SERVICEWRAPPER_H
#define SERVICEWRAPPER_H

namespace gateway {

class BlitzGateway;

class ServiceWrapper
{
protected:
    ServiceWrapper(BlitzGateway* connection);

protected:
    void resyncConnection();

    BlitzGateway* connection;

private:
    virtual void checkService() = 0;
};

} // Namespace gateway
#endif // SERVICEWRAPPER_H
