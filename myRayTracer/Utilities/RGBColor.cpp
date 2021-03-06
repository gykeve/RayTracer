// This file contains the definition of the class RGBColor

#include <math.h>

#include "RGBColor.h"


RGBColor::RGBColor(void)
	: r(0.0), g(0.0), b(0.0)
{}



RGBColor::RGBColor(float c)
	: r(c), g(c), b(c)
{}



RGBColor::RGBColor(float _r, float _g, float _b)
	: r(_r), g(_g), b(_b)
{}



RGBColor::RGBColor(const RGBColor& c)
	: r(c.r), g(c.g), b(c.b)
{}



RGBColor::~RGBColor(void)
{}



RGBColor&
RGBColor::operator= (const RGBColor& rhs) {
	if (this == &rhs)
		return (*this);

	r = rhs.r; g = rhs.g; b = rhs.b;

	return (*this);
}



RGBColor
RGBColor::powc(float p) const {
	return (RGBColor(pow(r, p), pow(g, p), pow(b, p)));
}

