#include "queryservicewrapper.h"

#include "blitzgateway.h"
#include "omero/sys/ParametersI.h"

using namespace gateway;

QueryServiceWrapper::QueryServiceWrapper(BlitzGateway* connection) : ServiceWrapper(connection) {}

void QueryServiceWrapper::findByQuery(const std::string& query) {

    //TODO Before ensuring the service is created, resync the session/connection (In parent)
    // Ensure that the service is actually created
    checkService();

    //TODO Feed in default parameters
    omero::sys::ParametersIPtr param = new omero::sys::ParametersI();

    q->findByQuery(query, param);
}

void QueryServiceWrapper::checkService() {
    if (!q) {
        q = connection->getClient()->getSession()->getQueryService();
    }
}
