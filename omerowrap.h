#ifndef OMEROWRAP_H
#define OMEROWRAP_H

namespace gateway {

template <typename TStd, typename TOme>
TStd wrap(TOme in) {
    return in->getValue();
}

} // Namespace gateway

#endif // OMEROWRAP_H
