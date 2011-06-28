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

#ifndef _PARSEPPLES_PARSER_H
#define _PARSEPPLES_PARSER_H

#define ROOT(name) \
    Parsepples::Atoms::Base* root (void) { \
        return this->name(); \
    }

#define PP_ROOT(name) \
    Parsepples::Atoms::Base* root (void) { \
        return this->name(); \
    }

#define RULE(name, block) \
    Parsepples::Atoms::Base* name (void) \
        block

#define PP_RULE(name, block) \
    Parsepples::Atoms::Base* name (void) \
        block

#include "parsepples/atoms.hpp"

namespace Parsepples {

class Parser : public Atoms::Base
{
  public:
    Parser (void);

    virtual Atoms::Base* root (void) = 0;

    Result* attempt (Source source, Context& context);
}

}

#endif
