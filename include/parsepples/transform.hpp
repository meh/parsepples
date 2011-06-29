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

#ifndef _PARSEPPLES_TRANSFORM_H
#define _PARSEPPLES_TRANSFORM_H

#ifndef TRANSFORM
#   define TRANSFORM \
        public: void initialize (void)
#endif

#define PP_TRANSFORM \
    public: void initialize (void)

#ifndef T_RULE
#   define T_RULE(name) \
        Parsepples::Result* name (Parsepples::Result* data)
#endif

#ifndef TRANSFORM_RULE
#   define TRANSFORM_RULE(name) \
        Parsepples::Result* name (Parsepples::Result* data)
#endif

#define PP_TRANSFORM_RULE(name) \
    Parsepples::Result* name (Parsepples::Result* data)

namespace Parsepples {

class Transform
{
  public:
    typedef Result* (*Transformer) (Result*);

  public:
    Transform (void);

    virtual void initialize (void);

    Result* apply (Result* data);

    void simple (std::string name, Transformer* transformer);

    void sequence (std::string name, Transformer* transformer);

    void subtree (std::string name, Transformer* transformer);
}

}

#endif
