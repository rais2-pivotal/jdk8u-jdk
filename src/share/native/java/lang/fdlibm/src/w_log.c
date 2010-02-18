
/*
 * Copyright 1998-2001 Sun Microsystems, Inc.  All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Sun designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Sun in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Sun Microsystems, Inc., 4150 Network Circle, Santa Clara,
 * CA 95054 USA or visit www.sun.com if you need additional information or
 * have any questions.
 */

/*
 * wrapper log(x)
 */

#include "fdlibm.h"


#ifdef __STDC__
        double log(double x)            /* wrapper log */
#else
        double log(x)                   /* wrapper log */
        double x;
#endif
{
#ifdef _IEEE_LIBM
        return __ieee754_log(x);
#else
        double z;
        z = __ieee754_log(x);
        if(_LIB_VERSION == _IEEE_ || isnan(x) || x > 0.0) return z;
        if(x==0.0)
            return __kernel_standard(x,x,16); /* log(0) */
        else
            return __kernel_standard(x,x,17); /* log(x<0) */
#endif
}
