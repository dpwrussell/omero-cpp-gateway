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


#ifndef BLITZGATEWAYIMPL_H
#define BLITZGATEWAYIMPL_H

#include "omero/client.h"

#include <string>
#include <tr1/memory>

namespace gateway {

class QueryServiceImpl;
    
class BlitzGatewayImpl
{

public:
    BlitzGatewayImpl(std::string username, std::string password, std::string group, std::string host, int port);
    ~BlitzGatewayImpl();

    bool connect();
    bool connect(std::string sessionUuid);

    std::string getSessionId() const;
    omero::client_ptr getClient();

    std::tr1::shared_ptr<QueryServiceImpl> getQueryService();

private:
    BlitzGatewayImpl(const BlitzGatewayImpl& other);
    BlitzGatewayImpl& operator=(const BlitzGatewayImpl& other);

    std::string username;
    std::string password;
    omero::client_ptr client;
    std::string group;
    //    1251         @param clone:       If True, overwrite anonymous with False
    //    1252         @type clone:        Boolean
    //    1253         @param try_super:   Try to log on as super user ('system' group)
    //    1254         @type try_super:    Boolean
    std::string host;
    int port;
    //    1259         @param extra_config:    Dictionary of extra configuration
    //    1260         @type extra_config:     Dict
    bool secure;
    bool anonymous;
    //    1265         @param useragent:   Log which python clients use this connection. E.g. 'OMERO.webadmin'
    //    1266         @type useragent:    String
    
    
    
    bool connected;
    std::string sessionUuid;
    
    void createSession();
    void createProxies();

    std::tr1::shared_ptr<QueryServiceImpl> queryService;

    
};

} // Namespace gateway

#endif // BLITZGATEWAYIMPL_H
