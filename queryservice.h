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


#ifndef QUERYSERVICE_H
#define QUERYSERVICE_H

#include <tr1/memory>

namespace gateway {

class QueryServiceImpl;
class ObjectWrapper;
    
class QueryService
{

public:
    QueryService(std::tr1::shared_ptr<QueryServiceImpl> q);
    virtual ~QueryService();    
    
    std::tr1::shared_ptr<ObjectWrapper> findByQuery(const std::string& query);
private:
    QueryService(const QueryService& other);
    QueryService& operator=(const QueryService& other);

    std::tr1::shared_ptr<QueryServiceImpl> q;
};

} // Namespace gateway

#endif // QUERYSERVICE_H
