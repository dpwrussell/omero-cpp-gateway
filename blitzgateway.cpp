#include "blitzgateway.h"

#include "blitzgatewayimpl.h"
#include "queryservice.h"

#include <tr1/memory>
#include <iostream>
using namespace gateway;

BlitzGateway::BlitzGateway(std::string username, std::string password, std::string group, std::string host, int port) {
    g = std::tr1::shared_ptr<BlitzGatewayImpl>(new BlitzGatewayImpl(username, password, group, host, port));
}

bool BlitzGateway::connect() {
    return g->connect();
}

bool BlitzGateway::connect(std::string sessionUuid) {
    return g->connect(sessionUuid);
}

std::string BlitzGateway::getSessionId() const {
    return g->getSessionId();
}

std::tr1::shared_ptr<QueryService> BlitzGateway::getQueryService() {
    return std::tr1::shared_ptr<QueryService>(new QueryService(g->getQueryService()));
}
