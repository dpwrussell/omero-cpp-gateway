#ifndef EXPERIMENTERWRAPPER_H
#define EXPERIMENTERWRAPPER_H

#include "wrapper/objectwrapper.h"
#include "omero/model/ExperimenterI.h"
#include <string>
#include "omerowrap.h"

namespace gateway {

class ExperimenterWrapper : public ObjectWrapper<omero::model::ExperimenterPtr> {

public:
    ExperimenterWrapper(omero::model::ExperimenterIPtr experimenter) : ObjectWrapper<omero::model::ExperimenterPtr>(experimenter) {}
//    ExperimenterWrapper(omero::model::ExperimenterIPtr experimenter);
    ExperimenterWrapper(ObjectWrapperI& experimenterWrapper) :
        ObjectWrapper<omero::model::ExperimenterPtr>(omero::model::ExperimenterIPtr::dynamicCast(experimenterWrapper.getObject())) {}

//    ExperimenterWrapper(ObjectWrapperI& experimenterWrapper);
//    std::string getFirstName() const;
    std::string getFirstName() const {
        return wrap<std::string,omero::RStringPtr>(object->getFirstName());
    }
};

} // Namespace gateway


#endif // EXPERIMENTERWRAPPER_H
