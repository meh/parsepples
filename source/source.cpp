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


#include <sstream>

#include "parsepples/source.hpp"

namespace Parsepples {

Source::Source (std::streambuf* buffer)
{
    _input  = new std::istream(buffer);
    _tsring = NULL;
}

Source::Source (std::string source)
{
    _string = new std::stringstream;
    _string << source;

    _input = new std::istream(static_cast<std::streambuf*>(_string));
}

Source::~Source (void)
{
    for (std::vector<Watcher*>::iterator it = _watchers.begin(); it < _watchers.end(); it++) {
        *it(this);
    }

    delete _input;

    if (_string) {
        delete _string;
    }
}

Source::Slice
Source::read (size_t length)
{
    size_t start = position();
    char   buffer[length + 1];

    _input->readsome(buffer, length);
    _cache.scan_for_line_endings(start, buffer);

    return Slice(buffer, start, &_cache);
}

size_t
Source::position (void)
{
    return _input->tellg();
}

void
Source::position (size_t position)
{
    _input->seekg(position, std::ios_base::beg);
}

Source::Position
Source::line_and_column (void)
{
    line_and_column(_offset);
}

Source::Position
Source::line_and_column (size_t position)
{
    return _cache.line_and_column(position);
}

void
Source::watch (Watcher* watcher)
{

}

long
Source::id (void)
{
    return (long) this;
}

}
