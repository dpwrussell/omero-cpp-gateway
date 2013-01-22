#ifndef TAGWRAPPER_H
#define TAGWRAPPER_H

#include <string>
#include "wrapper/objectwrapper.h"
#include "omero/model/TagAnnotationI.h"

namespace gateway {

class BlitzGateway;

class TagWrapper : public ObjectWrapper
{
public:
    TagWrapper(BlitzGateway* connection, omero::model::TagAnnotationIPtr tag);

    //TODO These 2 methods are const at the moment, but if I am having to reconnect and check/fix loadedness, that may not be the case
    int getId() const;
    std::string getName() const;

private:
    BlitzGateway* connection;
    omero::model::TagAnnotationIPtr tag;
};

} // Namespace gateway

#endif // TAGWRAPPER_H
