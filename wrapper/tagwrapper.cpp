#include "tagwrapper.h"

#include "metadataservicewrapper.h"

using namespace gateway;

TagWrapper::TagWrapper(MetadataServiceWrapper* m, omero::model::TagAnnotationIPtr tag) : m(m), tag(tag) {}

int TagWrapper::getId() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tag->isLoaded()) {
        m->loadTagSets();
    }

    return tag->getId();
}

std::string TagWrapper::getName() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tag->isLoaded()) {
        m->loadTagSets();
    }

    return tag->getTextValue()->getValue();
}
