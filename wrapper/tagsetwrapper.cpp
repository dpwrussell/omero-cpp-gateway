#include "tagsetwrapper.h"

#include "blitzgateway.h"

using namespace gateway;

TagSetWrapper::TagSetWrapper(BlitzGateway* connection, omero::model::TagAnnotationIPtr tagSet) : connection(connection), tagSet(tagSet) {}

std::vector<TagWrapper> TagSetWrapper::listTagsInTagSet() const {
    omero::model::AnnotationLinkedAnnotationSeq tags = tagSet->linkedAnnotationList();

    std::vector<TagWrapper> tagWrapperList;

    for (omero::model::AnnotationLinkedAnnotationSeq::iterator tagIter = tags.begin(); tagIter != tags.end(); ++tagIter) {
        omero::model::TagAnnotationIPtr tag = omero::model::TagAnnotationIPtr::dynamicCast(*tagIter);
        tagWrapperList.push_back(TagWrapper(connection, tag));
    }

    return tagWrapperList;
}

int TagSetWrapper::countTagsInTagSet() const {

}


int TagSetWrapper::getId() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tagSet->isLoaded()) {
        connection->getMetadataService()->loadTagSets();
    }

    return tagSet->getId();
}

std::string TagSetWrapper::getName() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tagSet->isLoaded()) {
        connection->getMetadataService()->loadTagSets();
    }

    return tagSet->getTextValue()->getValue();
}
