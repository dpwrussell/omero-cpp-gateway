#include "blitzgateway.h"
#include "wrapper/objectwrapper.h"

#include <iostream>

using namespace std;

int main()
{
    string username = "";
    string password = "";
    string group = "";
    string hostname = "localhost";
    int port = 4064;

    gateway::BlitzGateway *bg = new gateway::BlitzGateway(username, password, group, hostname, port);
    bg->connect();

    gateway::QueryServiceWrapper* q = bg->getQueryService();
    gateway::ObjectWrapperIPtr owi = q->findByQuery("select e from Experimenter e where e.id=1");
    gateway::ExperimenterWrapperPtr ew(new gateway::ExperimenterWrapper(*owi));

    cout << "Experimenter 1: " << *(ew->getFirstName()) << endl;

    return 0;
}

