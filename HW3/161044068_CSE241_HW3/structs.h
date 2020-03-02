/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structs.h
 * Author: osboxes
 *
 * Created on October 21, 2018, 8:38 AM
 */

#ifndef STRUCTS_H
#define STRUCTS_H

struct Coords{
	double x;
	double y;
};

enum whichShape { /*shapeElemde istenilen enum u tanımladım.*/
    Circ,Rect,Tri
};

#endif /* STRUCTS_H */

