#ifndef BLITZGATEWAY_H
#define BLITZGATEWAY_H

#include <string>

#include "omero/client.h"
#include "metadataservicewrapper.h"

namespace gateway {

class BlitzGateway
{
public:
    BlitzGateway(std::string username, std::string password, std::string group, std::string host, int port);

    bool connect();
    bool connect(std::string sessionUuid);

    MetadataServiceWrapper* getMetadataService();

    //TODO Would be better to restrict access to client if possible
    omero::client_ptr getClient() const;

    std::string getSessionId() const;

private:
    std::string username;
    std::string password;
    omero::client_ptr client;
    std::string group;
//    1251         @param clone:       If True, overwrite anonymous with False
//    1252         @type clone:        Boolean
//    1253         @param try_super:   Try to log on as super user ('system' group)
//    1254         @type try_super:    Boolean
    std::string host;
    int port;
//    1259         @param extra_config:    Dictionary of extra configuration
//    1260         @type extra_config:     Dict
    bool secure;
    bool anonymous;
//    1265         @param useragent:   Log which python clients use this connection. E.g. 'OMERO.webadmin'
//    1266         @type useragent:    String



    bool connected;
    std::string sessionUuid;

    void createSession();
    void createProxies();

    //Services
    MetadataServiceWrapper* metadataServiceWrapper;


};

} // Namespace gateway
#endif // BLITZGATEWAY_H
