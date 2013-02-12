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


#include "experimenterwrapper.h"
#include "experimenterwrapperimpl.h"

#include <tr1/memory>
#include <iostream>

using namespace gateway;

std::tr1::shared_ptr< ExperimenterWrapper > ExperimenterWrapper::staticCast(const std::tr1::shared_ptr< ObjectWrapper >& other)
{
    std::tr1::shared_ptr<ExperimenterWrapper> experimenterWrapper(std::tr1::static_pointer_cast<ExperimenterWrapper>(other));
    return experimenterWrapper;
}

std::tr1::shared_ptr<std::string> ExperimenterWrapper::getFirstName() const
{
    
    std::tr1::shared_ptr<ExperimenterWrapperImpl> eImpl(std::tr1::static_pointer_cast<ExperimenterWrapperImpl>(o));
    return eImpl->getFirstName();
}

ExperimenterWrapper::~ExperimenterWrapper()
{
    std::cout << "Destruct ExperimenterWrapper" << std::endl;
}
