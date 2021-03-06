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
#   error "Include parsepples/source.hpp, not this file"
#endif

#ifndef _PARSEPPLES_SOURCE_SLICE_H
#define _PARSEPPLES_SOURCE_SLICE_H

class Slice
{
  public:
    Slice (std::string buffer, size_t offset, LineCache* cache);

    std::string& buffer (void);

    size_t& offset (void);

    LineCache* cache (void);

    Slice operator + (Slice& slice);

    operator std::string (void);

  private:
    std::string _buffer;

    size_t _offset;

    LineCache* _cache;
};

#endif
