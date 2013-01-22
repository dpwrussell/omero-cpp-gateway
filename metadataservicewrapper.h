#ifndef METADATASERVICEWRAPPER_H
#define METADATASERVICEWRAPPER_H

#include "servicewrapper.h"

#include "omero/api/IMetadata.h"
#include <vector>
#include "wrapper/tagsetwrapper.h"

namespace gateway {

class MetadataServiceWrapper : public ServiceWrapper {

public:
    MetadataServiceWrapper(BlitzGateway* connection);
    void doSomething();
    std::vector<TagSetWrapper> loadTagSets();
private:
    omero::api::IMetadataPrx m;
};

} // Namespace gateway

#endif // METADATASERVICEWRAPPER_H
