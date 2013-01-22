#include <iostream>

#include "blitzgateway.h"
#include "metadataservicewrapper.h"
#include "wrapper/tagsetwrapper.h"
#include "wrapper/tagwrapper.h"

#include <vector>

using namespace std;

int main()
{


    gateway::BlitzGateway *bg = new gateway::BlitzGateway("dpwrussell", "marlboro7", "Davis", "omero1.bioch.ox.ac.uk", 4064);

    bg->connect();

    gateway::MetadataServiceWrapper* m = bg->getMetadataService();

    vector<gateway::TagSetWrapper> tagSets = m->loadTagSets();

    for (vector<gateway::TagSetWrapper>::iterator tagSetsIter = tagSets.begin(); tagSetsIter != tagSets.end(); ++tagSetsIter) {
        gateway::TagSetWrapper tagSet = *tagSetsIter;

        cout << "TagSet Name: " << tagSet.getName() << endl;

        vector<gateway::TagWrapper> tags = tagSet.listTagsInTagSet();
        for (vector<gateway::TagWrapper>::iterator tagIter = tags.begin(); tagIter != tags.end(); ++tagIter) {

            gateway::TagWrapper tag = *tagIter;
            cout << "\tTag Name: " << tag.getName() << endl;
        }
    }

    gateway::QueryServiceWrapper* q = bg->getQueryService();
    q->findByQuery("select * from experimenter");

    cout << "Hello World!" << endl;

    return 0;
}

