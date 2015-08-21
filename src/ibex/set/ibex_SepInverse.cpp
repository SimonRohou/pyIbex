//============================================================================
//                                  I B E X                                   
// File        : ibex_SepInverse.cpp
// Author      : Benoit Desrochers, Gilles Chabert
// Copyright   : Ecole des Mines de Nantes (France)
// License     : See the LICENSE file
// Created     : Mar 3, 2015
// Last Update : Mar 3, 2015
//============================================================================

#include "ibex_SepInverse.h"

namespace ibex {

SepInverse::SepInverse(Sep& s, Function& f) : s(s), f(f), yin(f.image_dim()), yout(f.image_dim()) {
	const ExprSymbol& y=ExprSymbol::new_(f.expr().dim);
	id = new Function(y,y);
	//id = new Function("x","x");
}

SepInverse::~SepInverse() {
	delete id;
}
void SepInverse::separate(IntervalVector& xin, IntervalVector& xout){

	assert(xin.size()==f.nb_var() && xout.size() == f.nb_var());


	xin &= xout;
	Domain tmp=f.eval_domain(xin);
	yin.init(Interval::ALL_REALS);
	yout.init(Interval::ALL_REALS);
	id->backward(tmp, yin);
	id->backward(tmp, yout);
	// Domain fxout=fxin;

	try {
		s.separate(yin, yout);
	} catch(EmptyBoxException& e) {
		throw e;
	}

	if( yin.is_empty())
		xin.set_empty();
	else
		f.backward(yin, xin);

	if( yout.is_empty())
		xout.set_empty();
	else
		f.backward(yout, xout);

}

} // end namespace ibex