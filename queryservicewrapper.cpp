#include "queryservicewrapper.h"

#include "blitzgateway.h"

#include "omero/sys/ParametersI.h"
#include "omero/api/IQuery.h"
#include <iostream>

using namespace gateway;

QueryServiceWrapper::QueryServiceWrapper(BlitzGateway* connection) : ServiceWrapper(connection) {}

ObjectWrapperIPtr QueryServiceWrapper::findByQuery(const std::string& query) {

    //TODO Before ensuring the service is created, resync the session/connection
    // Ensure that the service is actually created
    checkService();

    //TODO Feed in default parameters
    omero::sys::ParametersIPtr param = new omero::sys::ParametersI();

    omero::model::IObjectPtr result = q->findByQuery(query, param);

    ObjectWrapperIPtr resultPtr(new ObjectWrapper<omero::model::IObjectPtr>(result));

    return resultPtr;



}

void QueryServiceWrapper::checkService() {
    if (!q) {
        q = connection->getClient()->getSession()->getQueryService();
    }
}
