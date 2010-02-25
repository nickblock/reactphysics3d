/****************************************************************************
* Copyright (C) 2009      Daniel Chappuis                                  *
****************************************************************************
* This file is part of ReactPhysics3D.                                     *
*                                                                          *
* ReactPhysics3D is free software: you can redistribute it and/or modify   *
* it under the terms of the GNU Lesser General Public License as published *
* by the Free Software Foundation, either version 3 of the License, or     *
* (at your option) any later version.                                      *
*                                                                          *
* ReactPhysics3D is distributed in the hope that it will be useful,        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of           *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
* GNU Lesser General Public License for more details.                      *
*                                                                          *
* You should have received a copy of the GNU Lesser General Public License *
* along with ReactPhysics3D. If not, see <http://www.gnu.org/licenses/>.   *
***************************************************************************/

#ifndef LCPSOLVER_H
#define LCPSOLVER_H

// Libraries
#include "../Vector.h"
#include "../Matrix.h"

// ReactPhysics3D namespace
namespace reactphysics3d {

/*  -------------------------------------------------------------------
    Class LCPSolver :
        This abstract class represents an algorithm to solve a Linear
        Complementary Problem (LCP). Given a matrix "A", a vector "b",
        a vector "lowLimit" of lower limits and a vector "highLimits" of
        upper limits. The goal is to find a vector "x" such that:

                w = Ax - b
                lowLimits <= x <= highLimits

        and one of the thre following conditions holds :

                x_i = lowLimits_i, w_i >= 0
                x_i = highLimits_i, w_i >= 0
                lowLimits_i < x_i < highLimits_i, w_i = 0
    -------------------------------------------------------------------
*/
class LCPSolver {
    protected:

    public:
        LCPSolver();                                                                                                            // Constructor
        virtual ~LCPSolver();                                                                                                   // Destructor
        virtual void solve(const Matrix& A, const Vector& b, const Vector& lowLimits, const Vector& highLimits, Vector& x)=0;   // Solve a LCP problem

};

} // End of the ReactPhysics3D namespace

#endif
