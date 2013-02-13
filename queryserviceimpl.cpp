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


#include "queryserviceimpl.h"
#include "blitzgatewayimpl.h"
#include "objectwrapperimpl.h"
#include "objectwrapper.h"
#include "experimenterwrapper.h"
#include "experimenterwrapperimpl.h"

#include "omero/sys/ParametersI.h"
#include "omero/model/IObject.h"


#include <tr1/memory>
#include <iostream>
#include <string>

using namespace gateway;

QueryServiceImpl::QueryServiceImpl(BlitzGatewayImpl& g) : g(g) {}

QueryServiceImpl::~QueryServiceImpl()
{
    std::cout << "QueryServiceImpl destructed" << std::endl;
}

std::tr1::shared_ptr<ObjectWrapperImpl> QueryServiceImpl::findByQuery(const std::string& query) {
    //TODO Before ensuring the service is created, resync the session/connection (In parent)
    // Ensure that the service is actually created
    checkService();
    
    //TODO Feed in default parameters
    omero::sys::ParametersIPtr param = new omero::sys::ParametersI();
    
    omero::model::IObjectPtr result = q->findByQuery(query, param);

    return objectFactory(result);
}

std::tr1::shared_ptr<ObjectWrapper> QueryServiceImpl::findByQueryWrap(const std::string& query) {
    //TODO Before ensuring the service is created, resync the session/connection (In parent)
    // Ensure that the service is actually created
    checkService();
    
    //TODO Feed in default parameters
    omero::sys::ParametersIPtr param = new omero::sys::ParametersI();
    
    omero::model::IObjectPtr result = q->findByQuery(query, param);
    return objectFactoryWrap(result);
}


void QueryServiceImpl::checkService() {
    std::cout << "checkService" << std::endl;
    

    g.getClient()->getSession();
    q = g.getClient()->getSession()->getQueryService();
    std::cout << "checkService2" << std::endl;
    if (!q) {
        std::cout << "checkService3" << std::endl;
        q = g.getClient()->getSession()->getQueryService();
    }
}

std::tr1::shared_ptr<ObjectWrapperImpl> QueryServiceImpl::objectFactory(omero::model::IObjectPtr o) {
    std::string iceType = o->ice_id();

    if (iceType == "::omero::model::Experimenter") {
        omero::model::ExperimenterIPtr experimenterPtr = omero::model::ExperimenterIPtr::dynamicCast(o);
        return std::tr1::shared_ptr<ExperimenterWrapperImpl>(new ExperimenterWrapperImpl(experimenterPtr));
    }
    
    return std::tr1::shared_ptr<ObjectWrapperImpl>();
}

std::tr1::shared_ptr<ObjectWrapper> QueryServiceImpl::objectFactoryWrap(omero::model::IObjectPtr o) {
    std::string iceType = o->ice_id();

    if (iceType == "::omero::model::Experimenter") {
        omero::model::ExperimenterIPtr experimenterPtr = omero::model::ExperimenterIPtr::dynamicCast(o);
        std::tr1::shared_ptr<ExperimenterWrapperImpl> experimenterWrapperImplPtr (new ExperimenterWrapperImpl(experimenterPtr));
        return std::tr1::shared_ptr<ExperimenterWrapper>(new ExperimenterWrapper(experimenterWrapperImplPtr));
    }

    return std::tr1::shared_ptr<ObjectWrapper>();
}