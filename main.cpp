#include <iostream>

#include "blitzgateway.h"
#include "queryservice.h"
#include "objectwrapper.h"
#include "experimenterwrapper.h"

#include <tr1/memory>
#include <vector>
#include <iostream>

using namespace std;

int main()
{

    gateway::BlitzGateway g("dpwrussell", "marlboro7", "Davis", "omero1.bioch.ox.ac.uk", 4064);

    g.connect();

    tr1::shared_ptr<gateway::QueryService> q = g.getQueryService();
    tr1::shared_ptr<gateway::ObjectWrapper> o = q->findByQuery("select e from Experimenter e where e.id=1");

    std::tr1::shared_ptr<gateway::ExperimenterWrapper> e = gateway::ExperimenterWrapper::staticCast(o);

    cout << "firstName: " << *(e->getFirstName()) << endl;
    
    return 0;
}

