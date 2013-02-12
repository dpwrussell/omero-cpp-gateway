/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2013  Douglas Russell <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef EXPERIMENTERWRAPPER_H
#define EXPERIMENTERWRAPPER_H

#include "objectwrapper.h"

#include <tr1/memory>

namespace gateway {

class ExperimenterWrapper : public ObjectWrapper {

public:
    ExperimenterWrapper();
    static std::tr1::shared_ptr<ExperimenterWrapper> staticCast(const std::tr1::shared_ptr<ObjectWrapper>& other);
    virtual ~ExperimenterWrapper();

    std::tr1::shared_ptr<std::string> getFirstName() const;
    
private:
    ExperimenterWrapper(const ExperimenterWrapper& other);
    ExperimenterWrapper& operator=(const ExperimenterWrapper& other);
};

} // Namespace gateway

#endif // EXPERIMENTERWRAPPER_H
