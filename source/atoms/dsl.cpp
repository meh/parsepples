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

#include "parslet/atoms.hpp"

namespace Parsepples::Atoms {

Base*
DSL::str (std::string value)
{
    return new Str(value);
}

Base*
DSL::chr (char value)
{
    return new Str(value);
}

Base*
DSL::match (void)
{
    return new DelayedMatch(this);
}

Base*
DSL::match (std::string re)
{
    return new Re(re);
}

Base
DSL::any (void)
{
    return match(".");
}

Base*
DSL::repeat (int min, int max)
{
    return new Repetition(this, min, max)
}

Base*
DSL::maybe (void)
{
    return new Repetition(this, 0, 1);
}

Base*
DSL::operator >> (Base* part)
{
    return new Sequence(this, part);
}

Base*
DSL::operator | (Base* part)
{
    return new Alternative(this, part)
}

Base*
DSL::absent (void)
{
    return new Lookahead(this, false);
}

Base*
DSL::present (void)
{
    return new Lookahead(this, true);
}

Base*
DSL::as (std::string name)
{
    return new Named(this, name);
}

}
