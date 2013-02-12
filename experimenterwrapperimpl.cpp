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


#include "experimenterwrapperimpl.h"

#include "omero/model/ExperimenterI.h"

using namespace gateway;

std::tr1::shared_ptr<std::string> ExperimenterWrapperImpl::getFirstName() const {
    omero::model::ExperimenterIPtr e = omero::model::ExperimenterIPtr::dynamicCast(o);
    return std::tr1::shared_ptr<std::string>(new std::string(e->getFirstName()->getValue()));
    
}

ExperimenterWrapperImpl::~ExperimenterWrapperImpl()
{
    std::cout << "Destruct ExperimenterWrapperImpl" << std::endl;
}


