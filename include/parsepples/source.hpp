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

#ifndef _PARSEPPLES_SOURCE_H
#define _PARSEPPLES_SOURCE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace Parsepples {

class Source
{
  public:
    struct Position {
        size_t line;
        size_t column;
    };

    #include "parsepples/source/line_cache.hpp"
    #include "parsepples/source/slice.hpp"

  public:
    Source (std::streambuf* buffer);

    Source (std::string source);

    Slice read (size_t length);

    bool eof (void);

    size_t position (void);
    void   position (size_t value);

    Position line_and_column (void);

    Position line_and_column (size_t position);

  private:
    std::istream* _input;

    LineCache _cache;

    size_t _offset;
};

}
#endif
