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

#ifndef _PARSEPPLES_SOURCE_LINECACHE_H
#define _PARSEPPLES_SOURCE_LINECACHE_H

class LineCache
{
  public:
    LineCache (void);

    Position line_and_column (size_t offset);

    void scan_for_line_endings (size_t start, std::string buffer);

  private:
    std::vector<size_t> _ends;

    size_t _last;
};

#endif
