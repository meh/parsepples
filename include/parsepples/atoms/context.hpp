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

#ifndef _PARSEPPLES_ATOMS_CONTEXT_H
#define _PARSEPPLES_ATOMS_CONTEXT_H

#include "parsepples/atoms/response.hpp"

namespace Parsepples { namespace Atoms {

class Context
{
  public:
    struct Cache {
        Response* response;
        size_t    offset;
    };

  public:
    Context (void);

    Response* cache (Base* obj, Source& source);
    Response* cache (Base* obj, Source& source, Response* response);

  private:
    std::map<size_t, std::map<Base*, Cache*> > _cache;
};

} }

#endif
