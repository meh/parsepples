/**************************************************************************
 * Copyleft meh. [http://meh.paranoid.pk | meh@paranoici.org]
 *
 * This file is part of parsepples
 *
 * Parsepples is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Parsepples is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with parsepples. If not, see <http://www.gnu.org/licenses/>.
 */

#include "parsepples/result.hpp"

namespace Parsepples {

String::String (void) : Result("string")
{
    _value    = "";
    _position = { 0, 0 };
    _cache    = cache;
}

String::String (std::string value, Source::Position position, Source::LineCache* cache) : Result("string")
{
    _value    = value;
    _position = position;
    _cache    = cache;
}

String::~String (void)
{
}

std::string&
String::value (void)
{
    return _value;
}

Source::Position&
String::position (void)
{
    return _position;
}

}
