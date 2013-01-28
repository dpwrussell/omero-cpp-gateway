#include "experimenterwrapper.h"

#include "omerowrap.h"

using namespace gateway;
ExperimenterWrapper::ExperimenterWrapper(omero::model::ExperimenterIPtr experimenter) : ObjectWrapper<omero::model::ExperimenterPtr>(experimenter) {}

ExperimenterWrapper::ExperimenterWrapper(ObjectWrapperI& objectWrapper) :
    ObjectWrapper<omero::model::ExperimenterPtr>(omero::model::ExperimenterIPtr::dynamicCast(objectWrapper.getObject())) {}

std::string* ExperimenterWrapper::getFirstName() const {
    return wrap<std::string,omero::RStringPtr>(object->getFirstName());
}
