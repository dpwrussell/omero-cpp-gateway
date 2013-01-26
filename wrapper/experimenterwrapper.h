#ifndef EXPERIMENTERWRAPPER_H
#define EXPERIMENTERWRAPPER_H

#include "wrapper/objectwrapper.h"
#include "omero/model/ExperimenterI.h"
#include <string>

namespace gateway {

class ExperimenterWrapper : public ObjectWrapper<omero::model::ExperimenterPtr> {
public:
    ExperimenterWrapper(omero::model::ExperimenterIPtr experimenter);
    ExperimenterWrapper(ObjectWrapperI& experimenterWrapper);
    std::string getFirstName() const;
};

} // Namespace gateway


#endif // EXPERIMENTERWRAPPER_H
