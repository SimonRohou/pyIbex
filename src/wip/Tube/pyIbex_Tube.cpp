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

    const Interval& (Tube::*getT_1)(void) = &Tube::getT;
    const Interval& (Tube::*getT_2)(int) = &Tube::getT;
    const Interval& (Tube::*getT_3)(double) = &Tube::getT;

    const Interval& (Tube::*getY_1)(int) = &Tube::getY;
    const Interval& (Tube::*getY_2)(double) = &Tube::getY;
    Interval (Tube::*getY_3)(const Interval&) = &Tube::getY;

    void (Tube::*setY_1)(const Interval&, int) = &Tube::setY;
    void (Tube::*setY_2)(const Interval&, double) = &Tube::setY;
    void (Tube::*setY_3)(const Interval&, const Interval&) = &Tube::setY;

    bool (Tube::*intersect_1)(const Interval&, int) = &Tube::intersect;
    bool (Tube::*intersect_2)(const Interval&, double) = &Tube::intersect;
    bool (Tube::*intersect_3)(const Interval&, const Interval&, bool) = &Tube::intersect;

    pair<Interval,Interval> (Tube::*getEnclosedBounds_1)(void) const = &Tube::getEnclosedBounds;
    pair<Interval,Interval> (Tube::*getEnclosedBounds_2)(const Interval&) const = &Tube::getEnclosedBounds;

    class_<Tube, boost::shared_ptr<Tube> >("Tube", init<Interval,unsigned int>())
        .def(repr(self))
        .def("print", &Tube::print)
        .def("size", &Tube::size)
        .def("isSlice", &Tube::isSlice)
        .def("getSlice", &Tube::getSlice, return_value_policy<manage_new_object>())
        .def("input2index", &Tube::input2index)
        .def("index2input", &Tube::index2input)
        .def("getT", getT_1, return_value_policy<copy_const_reference>())
        .def("getT", getT_2, return_value_policy<copy_const_reference>())
        .def("getT", getT_3, return_value_policy<copy_const_reference>())
        .def("getY", getY_1, return_value_policy<copy_const_reference>())
        .def("getY", getY_2, return_value_policy<copy_const_reference>())
        .def("getY", getY_3)
        .def("setY", setY_1)
        .def("setY", setY_2)
        .def("setY", setY_3)
        .def("getFirstSubTube", &Tube::getFirstSubTube, return_value_policy<manage_new_object>())
        .def("getSecondSubTube", &Tube::getSecondSubTube, return_value_policy<manage_new_object>())
        .def("getIntegral", &Tube::getIntegral)
        .def("intersect", intersect_1)
        .def("intersect", intersect_2)
        .def("intersect", intersect_3)
        .def("getEnclosedBounds", getEnclosedBounds_1)
        .def("getEnclosedBounds", getEnclosedBounds_2)
        ;
};