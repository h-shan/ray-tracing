/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#ifndef PNGUTIL_HSLAPIXEL_H_
#define PNGUTIL_HSLAPIXEL_H_

#include <iostream>
#include <sstream>

namespace pngutil {
    class HSLAPixel {
        public:
            double h;
            double s;
            double l;
            double a;
            HSLAPixel();
            HSLAPixel(double hue, double saturation, double luminance);
            HSLAPixel(double hue, double saturation, double luminance, double alpha);
    };
}
#endif
