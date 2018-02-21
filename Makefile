EXENAME = main
OBJS = mp1.o lodepng.o PNG.o HSLAPixel.o
MP1_OBJS = mp1.o lodepng.o PNG.o HSLAPixel.o
CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp1: $(MP1_OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp1.o: mp1/mp1.cpp pngutil/PNG.h pngutil/HSLAPixel.h pngutil/RGB_HSL.hpp ray.hpp vec3.hpp    
	$(CXX) $< $(CXXFLAGS)

PNG.o: pngutil/PNG.cpp pngutil/PNG.h pngutil/HSLAPixel.h pngutil/lodepng.h
	$(CXX) $< $(CXXFLAGS)

lodepng.o: pngutil/lodepng.cpp pngutil/lodepng.h
	$(CXX) $< $(CXXFLAGS)

HSLAPixel.o: pngutil/HSLAPixel.cpp pngutil/HSLAPixel.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -rf *.o *.gch $(EXENAME)

