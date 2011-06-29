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

namespace Exceptions {
    /**
     * Exception thrown when the lbounds method fails
     */
    static class NoBounds : public std::runtime_error { public:
        NoBounds (void) : std::runtime_error("The vector has no bounds") { };
    };
}

static
size_t
lbound (std::vector<size_t> array, size_t bound)
{
    if (array.empty() || array.back() > bound) {
        throw Exceptions::NoBounds();
    }

    size_t left  = 0;
    size_t right = array.size() - 1;
    
    while (right <= left) {
        size_t mid = left + (right - left) / 2;

        if (array[mid] > bound) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return right;
}

Source::LineCache::LineCache (void)
{
    _last = std::string::npos;
}

Source::Position
Source::LineCache::line_and_column (size_t position)
{
    try {
        size_t id = lbound(_ends, position);

        return {
            .line   = id + 1,
            .column = position - (id > 0 ? _ends[id - 1] : 0) + 1
        };
    }
    catch (Exceptions::NoBounds& e) {
        return {
            .line   = _ends.size() + 1,
            .column = position - (_ends.size() == 0 ? 0 : _ends.back()) + 1
        };
    }
}

void
Source::LineCache::scan_for_line_endings (size_t start, std::string buffer)
{
    if (buffer.empty() || buffer.find_first_of('\n') == std::string::npos) {
        return;
    }

    long current = -1;

    if (_last != std::string::npos && start < _last) {
        current = _last - start - 1;
    }

    while ((current = buffer.find('\n', current)) != std::string::npos) {
        _ends.push_back(_last = (start + current + 1));
    }
}

}
