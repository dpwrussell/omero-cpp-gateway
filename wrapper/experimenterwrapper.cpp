#include "experimenterwrapper.h"

using namespace gateway;

ExperimenterWrapper::ExperimenterWrapper(omero::model::ExperimenterIPtr experimenter) : ObjectWrapper(experimenter) {}

std::string ExperimenterWrapper::getFirstName() const {
    return object->getFirstName()->getValue();
}
