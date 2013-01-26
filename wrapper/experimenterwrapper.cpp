#include "experimenterwrapper.h"

using namespace gateway;

ExperimenterWrapper::ExperimenterWrapper(omero::model::ExperimenterIPtr experimenter) : ObjectWrapper(experimenter) {}

ExperimenterWrapper::ExperimenterWrapper(ObjectWrapperI& experimenterWrapper) : ObjectWrapper(omero::model::ExperimenterIPtr::dynamicCast(experimenterWrapper.getObject())) {}

std::string ExperimenterWrapper::getFirstName() const {
    return object->getFirstName()->getValue();
}
