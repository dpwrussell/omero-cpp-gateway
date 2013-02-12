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
    
    cout << "start" << endl;
    gateway::BlitzGateway g("dpwrussell", "marlboro7", "Davis", "omero1.bioch.ox.ac.uk", 4064);

    g.connect();

    tr1::shared_ptr<gateway::QueryService> q = g.getQueryService();
    tr1::shared_ptr<gateway::ObjectWrapper> o = q->findByQuery("select e from Experimenter e where e.id=1");

    cout << "here" << endl;

    std::tr1::shared_ptr<gateway::ExperimenterWrapper> e = gateway::ExperimenterWrapper::staticCast(o);

    
    cout << "here2" << endl;
    cout << "firstName: " << *(e->getFirstName()) << endl;
    
    

//     gateway::MetadataServiceWrapper* m = bg->getMetadataService();

//     vector<gateway::TagSetWrapper> tagSets = m->loadTagSets();
// 
//     for (vector<gateway::TagSetWrapper>::iterator tagSetsIter = tagSets.begin(); tagSetsIter != tagSets.end(); ++tagSetsIter) {
//         gateway::TagSetWrapper tagSet = *tagSetsIter;
// 
//         cout << "TagSet Name: " << tagSet.getName() << endl;
// 
//         vector<gateway::TagWrapper> tags = tagSet.listTagsInTagSet();
//         for (vector<gateway::TagWrapper>::iterator tagIter = tags.begin(); tagIter != tags.end(); ++tagIter) {
// 
//             gateway::TagWrapper tag = *tagIter;
//             cout << "\tTag Name: " << tag.getName() << endl;
//         }
//     }
/*
    gateway::QueryServiceWrapper* q = bg->getQueryService();
    gateway::ObjectWrapperIPtr owi = q->findByQuery("select e from Experimenter e where e.id=1");
    gateway::ExperimenterWrapperPtr ew(new gateway::ExperimenterWrapper(*owi));

    omero::RStringPtr rsp = omero::rtypes::rstring("something");
    omero::RStringPtr rspn = 0;

    string* s = gateway::wrap<std::string,omero::RStringPtr>(rsp);
    string* n = gateway::wrap<std::string,omero::RStringPtr>(rspn);

    cout << "first: " << *(ew->getFirstName()) << endl;

    cout << "s: " << *s << endl;
    cout << "n: " << *n << endl;*/

    cout << "Hello World!" << endl;

    return 0;
}

