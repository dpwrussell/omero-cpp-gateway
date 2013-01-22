#ifndef QUERYSERVICEWRAPPER_H
#define QUERYSERVICEWRAPPER_H

#include "servicewrapper.h"

#include "omero/api/IQuery.h"
#include <string>

namespace gateway {

class QueryServiceWrapper : public ServiceWrapper
{
public:
    QueryServiceWrapper(BlitzGateway* connection);
    void findByQuery(const std::string& query);

private:
    virtual void checkService();

    omero::api::IQueryPrx q;
};

} // Namespace gateway

#endif // QUERYSERVICEWRAPPER_H
