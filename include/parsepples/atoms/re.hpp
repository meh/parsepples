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

#ifndef _PARSEPPLES_ATOMS_RE_H
#define _PARSEPPLES_ATOMS_RE_H

#include "parsepples/atoms/base.hpp"

namespace Parsepples { namespace Atoms {

class Re : public Base
{
  public:
    Re (std::string re);

    ~Re (void);

  private:
    pcre*       _pattern;
    pcre_extra* _study;
};

} }

#endif
