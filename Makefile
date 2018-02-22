EXENAME = main
OBJS = mp1.o lodepng.o PNG.o RGBAPixel.o
MP1_OBJS = mp1.o lodepng.o PNG.o RGBAPixel.o
CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

m1: $(MP1_OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp1.o: mp1/mp1.cpp pngutil/PNG.h pngutil/RGBAPixel.h ray.h vec3.h
	$(CXX) $< $(CXXFLAGS)

PNG.o: pngutil/PNG.cpp pngutil/PNG.h pngutil/RGBAPixel.h pngutil/lodepng.h
	$(CXX) $< $(CXXFLAGS)

lodepng.o: pngutil/lodepng.cpp pngutil/lodepng.h
	$(CXX) $< $(CXXFLAGS)

RGBAPixel.o: pngutil/RGBAPixel.cpp pngutil/RGBAPixel.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -rf *.o *.gch $(EXENAME)

