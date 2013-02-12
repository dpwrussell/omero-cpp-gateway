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


#include "blitzgatewayimpl.h"
#include "queryserviceimpl.h"

#include <tr1/memory>
#include <iostream>


using namespace gateway;

BlitzGatewayImpl::BlitzGatewayImpl(std::string username, std::string password, std::string group, std::string host, int port) :
    username(username), password(password), group(group), host(host), port(port) {

    client = new omero::client(host, port);
    connected = true;
    sessionUuid = "";

    //TODO createProxies()??

    //TODO createServiceOptsDict() - Default user, etc
}

BlitzGatewayImpl::~BlitzGatewayImpl()
{
    std::cout << "BlitzGatewayImpl destructed" << std::endl;
}

bool BlitzGatewayImpl::operator==(const BlitzGatewayImpl& other) const
{
///TODO: return ...;
}

bool BlitzGatewayImpl::connect() {
    if (!sessionUuid.empty()) {
        if (connected) {
            connected = false;
            //TODO Log "was connected, creating new omero_client"
            //TODO resetOmeroClient()
        }
        
        omero::api::ServiceFactoryPrx sf = client->joinSession(sessionUuid);
        sf->detachOnDestroy();
        //TODO Log "Joined Session OK with Uuid: self._sessionUuid"
        
        
    } else {
        if (connected) {
            connected = false;
            //TODO Log "Closing previous connection...creating new client"
            //TODO closeSession()
            //TODO resetOmeroClient()
        }
        
        //TODO Log "Creating Session..."
        createSession();
        //TODO Log "Session Created"

        //TODO createProxies
        createProxies();
        //TODO Log - "created connection (uuid=self._sessionUuid)
        return true;
    }
    return false;
}

bool BlitzGatewayImpl::connect(std::string sessionUuid) {
    if (!this->sessionUuid.empty()) {
        this->sessionUuid = sessionUuid;
    }
    return connect();
}

std::string BlitzGatewayImpl::getSessionId() const {
    return client->getSessionId();
}

omero::client_ptr BlitzGatewayImpl::getClient()
{
    return client;
}

std::tr1::shared_ptr< QueryServiceImpl > BlitzGatewayImpl::getQueryService()
{
    return queryService;
}


void BlitzGatewayImpl::createSession() {
    omero::api::ServiceFactoryPrx sf = client->createSession(username, password);
    sf->detachOnDestroy();
    sessionUuid = getSessionId();
}

void BlitzGatewayImpl::createProxies() {
    std::tr1::shared_ptr<QueryServiceImpl> temp(new QueryServiceImpl(*this));
    queryService = temp;
    //TODO Implement these. Python seems to create ProxyObjectWrappers for each service and set them in a dictionary, indexed by service name
}

