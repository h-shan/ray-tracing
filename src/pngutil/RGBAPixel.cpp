/**
 * @file RGBAPixel.cpp
 * Implementation of the RGBAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "RGBAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace pngutil {

    RGBAPixel::RGBAPixel() :r{1}, g{1}, b{1}, a{255} {};
    RGBAPixel::RGBAPixel(double r, double g, double b) : r{r}, g{g}, b{b}, a{255} {}
    RGBAPixel::RGBAPixel(double r, double g, double b, double a) : r{r}, g{g}, b{b}, a{a} {} 
}
