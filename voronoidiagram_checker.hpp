/*  
 *  Copyright 2010-2011 Anders Wallin (anders.e.e.wallin "at" gmail.com)
 *  
 *  This file is part of OpenVoronoi.
 *
 *  OpenCAMlib is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  OpenCAMlib is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with OpenCAMlib.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef VODI_CHECK_H
#define VODI_CHECK_H

#include "voronoidiagram_graph.hpp"

namespace ovd
{
class VoronoiDiagram;

/// this class provides sanity-checks for the VoronoiDiagram class
class VoronoiDiagramChecker {
public:
    VoronoiDiagramChecker(VoronoiDiagram* d) : vd(d) {}
    ~VoronoiDiagramChecker() {}
    
    /// sanity-check for the diagram, calls other sanity-check functions
    bool isValid();
    
    /// check that number of faces equals the number of generators
    bool face_count_equals_generator_count();
    
    /// the diagram should be of degree three (at least with point generators)
    bool vertex_degree_ok();
    
    /// traverse the incident faces and check next-pointers
    bool allIncidentFacesOK();
    
    /// check that all vertices in the input vector are of type IN
    bool allIn( const VertexVector& q);

    /// check that no undecided vertices remain in the face
    bool  noUndecidedInFace(  HEFace f );
  
    bool faceVerticesConnected( HEFace f, VoronoiVertexStatus Vtype );
    bool incidentFaceVerticesConnected(  VoronoiVertexStatus Vtype );
    
    bool detH_is_negative(  const Point& p, HEFace f, HEVertex minimalVertex );
    
    bool current_face_equals_next_face( HEEdge e); 
    VoronoiDiagram* vd;
};

} // end namespace
#endif
// end voronoidiagram_checker.h
