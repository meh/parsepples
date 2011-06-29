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

#ifndef _PARSEPPLES_EXCEPTIONS_H
#define _PARSEPPLES_EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace Parsepples { namespace Exceptions {

/**
 * Exception thrown when the Atoms::Re compilation fails
 */
class RegexpCompilation : public std::runtime_error { public:
    RegexpCompilation (std::string message) : std::runtime_error(message) { };
};

/**
 * Exception thrown when the Atoms::Re study fails
 */
class RegexpStudy : public std::runtime_error { public:
    RegexpStudy (std::string message) : std::runtime_error(message) { };
};

} }

#endif
