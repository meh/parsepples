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

#include "parsepples/source.hpp"

namespace Parsepples {

Source::Slice::Slice (std::string buffer, size_t offset, Source::LineCache* cache)
{
    _buffer = buffer;
    _offset = offset;
    _cache  = cache;
}

inline
std::sring&
Source::Slice::buffer (void)
{
    return _buffer;
}

inline
size_t
Source::Slice::offset (void)
{
    return _offset;
}

inline
Source::LineCache*
Source::Slice::cache (void)
{
    return _cache;
}

inline
Source::Slice
Source::Slice::operator + (Slice& slice)
{
    return Source::Slice(buffer() + slice.buffer(), offset(), cache());
}

inline
Source::Slice::operator std::string ()
{
    return _buffer;
}

}
