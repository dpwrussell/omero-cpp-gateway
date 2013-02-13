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


#ifndef QUERYSERVICEIMPL_H
#define QUERYSERVICEIMPL_H

#include <tr1/memory>
#include "omero/api/IQuery.h"

namespace gateway {

class BlitzGatewayImpl;
class ObjectWrapperImpl;
class ObjectWrapper;

class QueryServiceImpl
{

public:
    QueryServiceImpl(BlitzGatewayImpl& g);
    virtual ~QueryServiceImpl();

    std::tr1::shared_ptr<ObjectWrapperImpl> findByQuery(const std::string& query);
    //TODO findByQuery Wrap should really by a function createWrapper of ObjectWrapperImpl derivatives
    // but as it contains a shared pointer to ObjectWrapperImpl derivatives, this will require inheritance
    // from enable_shared_from_this in order to get access to the counter.
    // Otherwise returning a pointer to this would eventually result in a double free.
    std::tr1::shared_ptr<ObjectWrapper> findByQueryWrap(const std::string& query);
private:
    QueryServiceImpl(const QueryServiceImpl& other);
    QueryServiceImpl& operator=(const QueryServiceImpl& other);
    
    void checkService();
    std::tr1::shared_ptr<ObjectWrapperImpl> objectFactory(omero::model::IObjectPtr o);
    std::tr1::shared_ptr<ObjectWrapper> objectFactoryWrap(omero::model::IObjectPtr o);

    BlitzGatewayImpl& g;
    omero::api::IQueryPrx q;
};

} // Namespace gateway

#endif // QUERYSERVICEIMPL_H
