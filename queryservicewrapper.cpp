#include "queryservicewrapper.h"

#include "blitzgateway.h"
#include "omero/sys/ParametersI.h"
#include "omero/api/IQuery.h"

#include <iostream>

using namespace gateway;

QueryServiceWrapper::QueryServiceWrapper(BlitzGateway* connection) : ServiceWrapper(connection) {}

void QueryServiceWrapper::findByQuery(const std::string& query) {

    //TODO Before ensuring the service is created, resync the session/connection (In parent)
    // Ensure that the service is actually created
    checkService();

    //TODO Feed in default parameters
    omero::sys::ParametersIPtr param = new omero::sys::ParametersI();

    //omero::api::IObjectList results = q->findByQuery(query, param);
    omero::model::IObjectPtr result = q->findByQuery("select e from Experimenter e where e.id=1", param);
    omero::model::ExperimenterIPtr e = omero::model::ExperimenterIPtr::dynamicCast(result);


    ExperimenterWrapper ew(e);

    std::cout << "first: " << ew.getFirstName() << std::endl;

//    return result;

    //e = q.findByQuery("select e from Experimenter e where e.id = %i" % self._obj.details.owner.id.val,None, self._conn.SERVICE_OPTS)
    //self._author = e.firstName.val + " " + e.lastName.val


//    int i=0;

//    for (omero::api::IObjectList::iterator resultsIter = omero::api::IObjectList::iterator(results.begin()); resultsIter != results.end(); ++results) {
//        std::cout << "Row: " << ++i <<

//    }


}

void QueryServiceWrapper::checkService() {
    if (!q) {
        q = connection->getClient()->getSession()->getQueryService();
    }
}
