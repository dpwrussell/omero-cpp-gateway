#ifndef TAGSETWRAPPER_H
#define TAGSETWRAPPER_H

#include <string>
#include <vector>
#include "wrapper/objectwrapper.h"
#include "wrapper/tagwrapper.h"
#include "omero/model/TagAnnotationI.h"

namespace gateway {

class BlitzGateway;

class TagSetWrapper : public ObjectWrapper {

public:
    TagSetWrapper(BlitzGateway* connection, omero::model::TagAnnotationIPtr tagSet);

    std::vector<TagWrapper> listTagsInTagSet() const;
    int countTagsInTagSet() const;

    //TODO These 2 methods are const at the moment, but if I am having to reconnect and check/fix loadedness, that may not be the case
    int getId() const;
    std::string getName() const;


private:
    BlitzGateway* connection;
    omero::model::TagAnnotationIPtr tagSet;

};

} // Namespace gateway

#endif // TAGSETWRAPPER_H
