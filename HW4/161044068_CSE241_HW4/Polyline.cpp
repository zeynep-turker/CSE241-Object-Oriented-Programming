#include "Polyline.h"
using namespace PolygonNameSpace;


    Polyline::Polyline(Polygon &polygon){
        this->polygon = polygon;
    }
    ostream& operator<<(ostream &out, const Polyline& polyline){
        string str="xmlns=\"http://wwww.w3.org/2000/svg\">";
        out<<"<svg version=\"1.1\" "<<"baseProfile=\"full\"";
        out<<" width=\""<<polyline.getPolygon().getMaxX()*2<<"\" height=\""<<polyline.getPolygon().getMaxY()*2<<"\" ";
        out<<str;
        out<<"<polyline points=\"";
        for(int i=0; i<polyline.getPolygon().getSize(); ++i){
            out<<polyline.getPolygon().getArray()[i].getCoordX()<<",";
            out<<polyline.getPolygon().getArray()[i].getCoordY()<<" ";
        }
        out<<"\" style=\"fill:none;stroke:black;stroke-width:3\" />";
        out<<"</svg>";
        return out;
    }
