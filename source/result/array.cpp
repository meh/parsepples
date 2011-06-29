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

Array::Array (void) : Result("array")
{
}

Array::Array (std::vector<Result*>& value)
{
    _value = value;
}

Array::~Array (void)
{
    for (std::vector<Result*>::iterator it = _value.begin(); it < _value.end(); it++) {
        delete *it;
    }
}

std::vector<Result*>&
Array::value (void)
{
    return _value;
}

}
