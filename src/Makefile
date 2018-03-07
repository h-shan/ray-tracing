EXENAME = main
OBJS = mp1.o lodepng.o PNG.o RGBAPixel.o sphere.o triangle.o hitable_list.o camera.o lambertian.o random.o
MP1_OBJS = mp1.o lodepng.o PNG.o RGBAPixel.o sphere.o triangle.o hitable_list.o camera.o lambertian.o random.o
CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp1: $(MP1_OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp1.o: mp1.cpp pngutil/PNG.h pngutil/RGBAPixel.h ray.h vec3.h random.h camera.h
	$(CXX) $< $(CXXFLAGS)

PNG.o: pngutil/PNG.cpp pngutil/PNG.h pngutil/RGBAPixel.h pngutil/lodepng.h
	$(CXX) $< $(CXXFLAGS)

lodepng.o: pngutil/lodepng.cpp pngutil/lodepng.h
	$(CXX) $< $(CXXFLAGS)

RGBAPixel.o: pngutil/RGBAPixel.cpp pngutil/RGBAPixel.h
	$(CXX) $< $(CXXFLAGS)

sphere.o: sphere.cpp sphere.h ray.h vec3.h hitable.h 
	$(CXX) $< $(CXXFLAGS)

triangle.o: triangle.cpp triangle.h ray.h vec3.h hitable.h
	$(CXX) $< $(CXXFLAGS)

hitable_list.o: hitable_list.cpp hitable_list.h hitable.h
	$(CXX) $< $(CXXFLAGS)

camera.o: camera.cpp camera.h
	$(CXX) $< $(CXXFLAGS)

lambertian.o: lambertian.cpp lambertian.h material.h
	$(CXX) $< $(CXXFLAGS)

random.o: random.cpp random.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -rf *.o *.gch $(EXENAME) mp1

