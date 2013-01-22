#include "tagwrapper.h"

#include "blitzgateway.h"

using namespace gateway;

TagWrapper::TagWrapper(BlitzGateway* connection, omero::model::TagAnnotationIPtr tag) : connection(connection), tag(tag) {}

int TagWrapper::getId() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tag->isLoaded()) {
       connection->getMetadataService()->loadTagSets();
    }

    return tag->getId();
}

std::string TagWrapper::getName() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tag->isLoaded()) {
        connection->getMetadataService()->loadTagSets();
    }

    return tag->getTextValue()->getValue();
}
