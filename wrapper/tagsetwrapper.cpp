#include "tagsetwrapper.h"

#include "metadataservicewrapper.h"

using namespace gateway;

TagSetWrapper::TagSetWrapper(MetadataServiceWrapper* m, omero::model::TagAnnotationIPtr tagSet) : m(m), tagSet(tagSet) {}

std::vector<TagWrapper> TagSetWrapper::listTagsInTagSet() const {
    omero::model::AnnotationLinkedAnnotationSeq tags = tagSet->linkedAnnotationList();

    std::vector<TagWrapper> tagWrapperList;

    for (omero::model::AnnotationLinkedAnnotationSeq::iterator tagIter = tags.begin(); tagIter != tags.end(); ++tagIter) {
        omero::model::TagAnnotationIPtr tag = omero::model::TagAnnotationIPtr::dynamicCast(*tagIter);
        tagWrapperList.push_back(TagWrapper(m, tag));
    }

    return tagWrapperList;
}

int TagSetWrapper::countTagsInTagSet() const {

}


int TagSetWrapper::getId() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tagSet->isLoaded()) {
        m->loadTagSets();
    }

    return tagSet->getId();
}

std::string TagSetWrapper::getName() const {
    //TODO Check connect status? Maybe this is delegated to isLoadeds call to MetadataServiceWrapper?

    if (!tagSet->isLoaded()) {
        m->loadTagSets();
    }

    return tagSet->getTextValue()->getValue();
}
