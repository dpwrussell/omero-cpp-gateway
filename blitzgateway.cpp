#include "blitzgateway.h"

#include "omero/API.h"
#include "omero/api/ISession.h"

#include <iostream>
using namespace gateway;

BlitzGateway::BlitzGateway(std::string username, std::string password, std::string group, std::string host, int port) :
    username(username), password(password), group(group), host(host), port(port) {

    client = new omero::client(this->host, this->port);
    connected = true;
    sessionUuid = "";


    //TODO createProxies()
    metadataServiceWrapper = new MetadataServiceWrapper(this);
    queryServiceWrapper = new QueryServiceWrapper(this);

    //TODO createServiceOptsDict() - Default user, etc
}

bool BlitzGateway::connect() {
    if (!sessionUuid.empty()) {
        if (connected) {
            connected = false;
            //TODO Log "was connected, creating new omero_client"
            //TODO resetOmeroClient()
        }

        omero::api::ServiceFactoryPrx sf = client->joinSession(sessionUuid);
        sf->detachOnDestroy();
        //TODO Log "Joined Session OK with Uuid: self._sessionUuid"


    } else {
        if (connected) {
            connected = false;
            //TODO Log "Closing previous connection...creating new client"
            //TODO closeSession()
            //TODO resetOmeroClient()
        }

        //TODO Log "Creating Session..."
        createSession();
        //TODO Log "Session Created"

        //TODO createProxies()
        //TODO Log - "created connection (uuid=self._sessionUuid)
        return true;
    }
    return false;
}

bool BlitzGateway::connect(std::string sessionUuid) {
    if (!this->sessionUuid.empty()) {
        this->sessionUuid = sessionUuid;
    }
    return connect();
}

void BlitzGateway::createSession() {
    omero::api::ServiceFactoryPrx sf = client->createSession(username, password);
    sf->detachOnDestroy();
    sessionUuid = getSessionId();
}

void BlitzGateway::createProxies() {
    //TODO Implement these. Python seems to create ProxyObjectWrappers for each service and set them in a dictionary, indexed by service name
}

omero::client_ptr gateway::BlitzGateway::getClient() const {
    return client;
}

std::string BlitzGateway::getSessionId() const {
    return client->getSessionId();
}

MetadataServiceWrapper* BlitzGateway::getMetadataService() const {
    return metadataServiceWrapper;
}

QueryServiceWrapper* BlitzGateway::getQueryService() const {
    return queryServiceWrapper;
}
