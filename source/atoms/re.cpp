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

#include "parsepples/atoms.hpp"

namespace Parsepples::Atoms {

Re::Re (std::string re)
{
    const char* error       = NULL;
    int         errorOffset = 0;

    _pattern = pcre_compile(re.c_str(), PCRE_UTF8 | PCRE_MULTILINE | PCRE_EXTRA, &error, &errorOffset, NULL);

    if (_pattern == NULL) {
        throw Exceptions::RegexpCompilation(std::string(error) + " at " + errorOffset);
    }

    _study = pcre_study(_pattern, 0, &error);

    if (_study == NULL && error != NULL) {
        throw Exceptions::RegexpStudy(error);
    }
}

~Re::Re (void)
{
    if (_study) {
        free(_study);
    }

    pcre_free(_pattern);
}

Result*
Re::attempt (Source* source, Context& context)
{

}
