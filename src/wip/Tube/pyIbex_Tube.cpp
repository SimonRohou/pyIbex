//============================================================================
//                                P Y I B E X
// File        : pyIbex_Tube.cpp
// Author      : Simon Rohou
// Copyright   : Benoit Desrochers
// License     : See the LICENSE file
// Created     : Nov 03, 2015
//============================================================================


#include "Tube.h"
#include <boost/python.hpp>

using namespace boost::python;
using namespace ibex;

void export_Tube() {

    //typedef const ibex::Interval& (Tube::*getT_1) (int);

    class_<Tube, boost::shared_ptr<Tube> >("Tube", init<Interval,unsigned int>())
        .def(repr(self))
        .def("print", &Tube::print)
        .def("size", &Tube::size)
        .def("isSlice", &Tube::isSlice)
        .def("getSlice", &Tube::getSlice, return_value_policy<manage_new_object>())
        .def("input2index", &Tube::input2index)
        .def("index2input", &Tube::index2input)
        //.def("getT", getT_1(&Tube::getT))
        //.def("getY", &Tube::getY)
        //.def("setY", &Tube::setY)
        .def("getFirstSubTube", &Tube::getFirstSubTube, return_value_policy<manage_new_object>())
        .def("getSecondSubTube", &Tube::getSecondSubTube, return_value_policy<manage_new_object>())
        .def("getIntegral", &Tube::getIntegral)
        //.def("intersect", &Tube::intersect)
        //.def("getEnclosedBounds", &Tube::getEnclosedBounds)
        ;
};