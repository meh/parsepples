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

#include "parsepples/exceptions.hpp"
#include "parsepples/atoms.hpp"

namespace Parsepples { namespace Atoms {

Result*
Base::parse (Source source)
{
    Response* response = apply(&source);

    if (response.error()) {
        _parse_failed(static_cast<Failure*>(&response)->reason);
    }

    if (!source.eof()) {
        if (!_cause.empty()) {
            throw Exceptions::UnconsumedInput(_cause);
        }
        else {
            throw Exceptions::UnconsumedInput(std::string("Don't know what to do with ") + source.read(100).buffer());
        }
    }

    return Result::flatten(static_cast<Success*>(&response)->result);
}

Response*
Base::apply (Source& source)
{
    size_t old = source.position();

    try {
        Response* response = context.cache(this, source);
    }
    catch (Exceptions::NotCached& e) {
        Response* response = attempt(source, context);

        context.cache(this, source, response, old);
    }

    source.position(old);

    return response;
}

void
Base::_parse_failed (std::string reason)
{
    throw Exceptions::ParseError(_cause = reason);
}

Success*
Base::success (Result* result)
{
    return new Success(result);
}

Failure*
Base::error (Source* source, std::string message, Source::Position position)
{
    return new Failure(source, message, position);
}

} }
