#ifndef BLITZGATEWAY_H
#define BLITZGATEWAY_H

#include <string>
#include <tr1/memory>

namespace gateway {

class BlitzGatewayImpl;
class QueryService;
    
class BlitzGateway
{
public:
    BlitzGateway(std::string username, std::string password, std::string group, std::string host, int port);

    bool connect();
    bool connect(std::string sessionUuid);

    std::string getSessionId() const;
    std::tr1::shared_ptr<QueryService> getQueryService();

private:
    std::tr1::shared_ptr<BlitzGatewayImpl> g;

};

} // Namespace gateway
#endif // BLITZGATEWAY_H
