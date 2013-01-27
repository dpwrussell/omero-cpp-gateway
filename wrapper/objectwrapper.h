#ifndef OBJECTWRAPPER_H
#define OBJECTWRAPPER_H

#include "omero/api/IQuery.h"

#include <tr1/memory>

namespace gateway {

class ObjectWrapperI {
public:
    virtual omero::model::IObjectPtr getObject() = 0;
};

typedef std::tr1::shared_ptr<ObjectWrapperI> ObjectWrapperIPtr;

template <class T>
class ObjectWrapper : public ObjectWrapperI {
protected:
    T object;
public:
    ObjectWrapper(T object) : object(object) {

    }

    virtual omero::model::IObjectPtr getObject(){
        return T::dynamicCast(object);
    }
};

} // Namespace gateway

#endif // OBJECTWRAPPER_H
