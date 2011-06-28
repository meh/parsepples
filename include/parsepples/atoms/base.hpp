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

#ifndef _PARSEPPLES_ATOMS_BASE_H
#define _PARSEPPLES_ATOMS_BASE_H

#include "parsepples/atoms/response.hpp"
#include "parsepples/atoms/dsl.hpp"
#include "parsepples/atoms/context.hpp"

namespace Parsepples { namespace Atoms {

class Base : public DSL
{
  public:
    Result* parse (Source source);

    Response& apply (Source& source, Context& context);

    virtual Response attempt (Source& source, Context& context) = 0;

  private:
    void _parse_failed (std::string reason);

  protected:
    /**
     * Return a Success object, to use when the parsing has been successful
     *
     * @param result The result of the parsing.
     *
     * @return The Sucess object.
     */
    Success& success (Result* result);

    /**
     * Return a Failure object, to use when the parsing has been unsuccesful
     *
     * @param source The parsed source
     * @param message The error message
     * @param position The position where the error was generated
     *
     * @return The Failure object
     */
    Failure& error (Source& source, std::string message, Source::Position position);

  private:
    std::string _cause;
};

} }

#endif
