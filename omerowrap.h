#ifndef OMEROWRAP_H
#define OMEROWRAP_H

#include <string>

namespace gateway {

template <typename TStd, typename TOme>
TStd* wrap(TOme in) {
    if (!in == 0) {
        return new std::string(in->getValue());
    }
    return 0;
}

} // Namespace gateway

#endif // OMEROWRAP_H
