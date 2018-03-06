/**
 * @file RGBAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#ifndef PNGUTIL_RGBAPIXEL_H_
#define PNGUTIL_RGBAPIXEL_H_

#include <iostream>
#include <sstream>

namespace pngutil {
    class RGBAPixel {
        public:
            double r;
            double g;
            double b;
            double a;
            RGBAPixel();
            RGBAPixel(double r, double g, double b);
            RGBAPixel(double r, double g, double b, double alpha);
    };
}
#endif
