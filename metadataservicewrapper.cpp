#include "metadataservicewrapper.h"

#include "blitzgateway.h"
#include "omero/sys/ParametersI.h"
#include "omero/model/IObject.h"
#include "omero/model/TagAnnotationI.h"
#include "wrapper/tagsetwrapper.h"

#include <iostream>

using namespace gateway;

MetadataServiceWrapper::MetadataServiceWrapper(BlitzGateway* connection) : ServiceWrapper(connection) {}

//TODO Should return a list of TagSetWrappers (typedef)
std::vector<TagSetWrapper> MetadataServiceWrapper::loadTagSets() {

    //TODO Before ensuring the service is created, resync the session/connection (In parent)
    // Ensure that the service is actually created
    checkService();

    //TODO Feed in default parameters
    omero::sys::ParametersIPtr param = new omero::sys::ParametersI();
    //param->exp(sf->getAdminService()->getEventContext()->userId);

    omero::api::IObjectList tagSets = m->loadTagSets(param);

    std::vector<TagSetWrapper> tagSetWrapperList;

    for (omero::api::IObjectList::iterator tagSetIter = tagSets.begin(); tagSetIter != tagSets.end(); ++tagSetIter) {
        omero::model::TagAnnotationIPtr tagSet = omero::model::TagAnnotationIPtr::dynamicCast(*tagSetIter);
        tagSetWrapperList.push_back(TagSetWrapper(connection, tagSet));
    }

    return tagSetWrapperList;
}

void MetadataServiceWrapper::checkService() {
    if (!m) {
        std::cout << "init m" << std::endl;
        m = connection->getClient()->getSession()->getMetadataService();
    }
}
