#ifndef EXPERIMENTERWRAPPER_H
#define EXPERIMENTERWRAPPER_H

#include "wrapper/objectwrapper.h"
#include "omero/model/ExperimenterI.h"
#include <string>
#include <tr1/memory>
#include "omerowrap.h"

namespace gateway {

class ExperimenterWrapper : public ObjectWrapper<omero::model::ExperimenterPtr> {

public:
    ExperimenterWrapper(omero::model::ExperimenterIPtr experimenter);
    ExperimenterWrapper(ObjectWrapperI& objectWrapper);

    std::string* getFirstName() const;
};

typedef std::tr1::shared_ptr<ExperimenterWrapper> ExperimenterWrapperPtr;

} // Namespace gateway

#endif // EXPERIMENTERWRAPPER_H
