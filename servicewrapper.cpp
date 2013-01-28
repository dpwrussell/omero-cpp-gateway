#include "servicewrapper.h"

#include "blitzgateway.h"

using namespace gateway;

ServiceWrapper::ServiceWrapper(BlitzGateway* connection) : connection(connection) {}

void ServiceWrapper::resyncConnection() {
    if (!connection->getSessionId().empty()) {
        //Session exists so attempt to refresh

    }
}
