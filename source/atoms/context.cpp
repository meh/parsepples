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

#include "parsepples/atoms.hpp"

namespace Parsepples::Atoms {

Context::Context (void)
{
}

Context::~Context (void)
}

Response&
Context::cache (Base* obj, Source& source)
{
    size_t start = source.position;

    if (_cache.find(start) == _cache.end() || _cache[start].find(obj) == _cache[start].end()) {
        throw NotCached();
    }

    Cache cache = _cache[start][obj];

    source.position(start + cache.offset);

    return cache.response;
}

Response&
Context::cache (Base* obj, Source& source, Response& response, size_t before)
{
    _cache[source.position][obj] = Cache(response, source.position - before);

    return response;
}

}
