#ifndef POLYLINE_H
#define POLYLINE_H
#include "Polygon.h"
using namespace PolygonNameSpace;

    class Polyline {
    public:
        Polyline(Polygon &polygon);
        inline Polygon getPolygon()const{ return polygon; }
        friend ostream& operator<<(ostream &out, const Polyline& polyline);
    private:
        Polygon polygon;
    };



#endif /* POLYLINE_H */

