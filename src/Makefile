EXENAME = main
OBJS = mp1.o lodepng.o PNG.o RGBAPixel.o sphere.o triangle.o plane.o hitable_list.o perspective_camera.o orthogonal_camera.o lambertian.o metal.o random.o light.o aabb.o bvh_node.o
MP1_OBJS = mp1.o lodepng.o PNG.o RGBAPixel.o sphere.o triangle.o plane.o hitable_list.o perspective_camera.o orthogonal_camera.o lambertian.o metal.o random.o light.o aabb.o bvh_node.o
MP2_OBJS = mp2.o lodepng.o PNG.o RGBAPixel.o sphere.o triangle.o plane.o hitable_list.o perspective_camera.o orthogonal_camera.o lambertian.o metal.o random.o light.o aabb.o bvh_node.o bvh_node.o
CXX = clang++
CXXFLAGS = -std=c++0x -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++0x

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp1: $(MP1_OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp2: $(MP2_OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

mp1.o: mp1.cpp pngutil/PNG.h pngutil/RGBAPixel.h ray.h vec3.h random.h camera.h light.h triangle.h 
	$(CXX) $< $(CXXFLAGS)

mp2.o: mp2.cpp pngutil/lodepng.h pngutil/PNG.h pngutil/RGBAPixel.h sphere.h triangle.h plane.h hitable_list.h perspective_camera.h orthogonal_camera.h lambertian.h metal.h random.o light.h aabb.h bvh_node.h bvh_node.h
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

plane.o: plane.cpp plane.h
	$(CXX) $< $(CXXFLAGS)

hitable_list.o: hitable_list.cpp hitable_list.h hitable.h
	$(CXX) $< $(CXXFLAGS)

perspective_camera.o: perspective_camera.cpp perspective_camera.h camera.h
	$(CXX) $< $(CXXFLAGS)

orthogonal_camera.o: orthogonal_camera.cpp orthogonal_camera.h camera.h
	$(CXX) $< $(CXXFLAGS)

lambertian.o: lambertian.cpp lambertian.h material.h
	$(CXX) $< $(CXXFLAGS)

metal.o: metal.cpp metal.h
	$(CXX) $< $(CXXFLAGS)

random.o: random.cpp random.h
	$(CXX) $< $(CXXFLAGS)

light.o: light.cpp light.h
	$(CXX) $< $(CXXFLAGS)

aabb.o: aabb.cpp aabb.h
	$(CXX) $< $(CXXFLAGS)

bvh_node.o: bvh_node.cpp bvh_node.h
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -rf *.o *.gch $(EXENAME) mp1

