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

#ifndef _PARSEPPLES_ATOMS_DSL_H
#define _PARSEPPLES_ATOMS_DSL_H

namespace Parsepples { namespace Atoms {

class Base;

class DSL
{
  public:
    inline Base* str (std::string value);

    inline Base* chr (char value);

    inline Base* match (void);

    inline Base* match (std::string value);

    inline Base* any (void);

    inline Base* repeat (int min = 0, int max = 0);

    inline Base* maybe (void);

    inline Base* operator >> (Base* part);

    inline Base* operator | (Base* part);

    inline Base* absent (void);

    inline Base* present (void);

    inline Base* as (std::string name);
};

} }

#endif
