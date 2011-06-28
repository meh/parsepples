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

#ifndef _PARSEPPLES_ATOMS_RESPONSE_H
#define _PARSEPPLES_ATOMS_RESPONSE_H

namespace Parsepples { namespace Atoms {

class Response
{
  public:
    Response (bool success)
    {
        _success = success;
    };

    bool error (void)
    {
        return !_success;
    };

    bool success (void)
    {
        return _success;
    }

  private:
    bool _success;
};

class Failure : public Response
{
  public:
    Source* source;

    std::string reason;

    Source::Position position;

  public:
    Failure (Source* source, std::string reason, Source::Position position) : Response(false) {
        this->source   = source;
        this->reason   = reason;
        this->position = position;
    };
};

class Success : public Response
{
  public:
    Result* result;

  public:
    Success (Result* result) : Response(true) {
        this->result = result;
    };
};

} }

#endif
