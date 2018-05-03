#include <fstream>
#include <iostream>
#include <float.h>
#include <vector>

#include "pngutil/PNG.h"
#include "vec3.h"
#include "ray.h"
#include "perspective_camera.h"
#include "orthogonal_camera.h"
#include "hitable.h"
#include "sphere.h"
#include "triangle.h"
#include "plane.h"
#include "hitable_list.h"
#include "random.h"
#include "lambertian.h"
#include "metal.h"
#include "light.h"
#include "bvh_node.h"

using namespace std;

vec3 color(const ray &r, hitable *world) {
  // light from back left
  light dir_light(vec3(1, -1 , -1), 1500);

  vec3 ambient_color = vec3(0.05, 0.05, 0.05);
  hit_record rec;
  if (world->hit(r, 0.01, 50, rec)) {
   // cout << rec.t << endl;
    ray scattered;
    vec3 albedo;
    rec.mat->scatter(r, rec, albedo, scattered);
    vec3 light_dir = -dir_light.direction;
    vec3 col;
    vec3 diffuse_color;
    if (light_dir.dot(rec.normal) > 0) {
      diffuse_color = light_dir.dot(rec.normal) * dir_light.intensity * dir_light.color * albedo / M_PI;
      hit_record temp;
      bool visible = !world->hit(ray(rec.p, light_dir), 0.01, DBL_MAX, temp);

      diffuse_color *= visible;
     // if (visible && diffuse_color.length() > 0.01) {
     //   cout << diffuse_color << endl;
     // }
    }
    col = albedo * ambient_color + diffuse_color;
    // col = diffuse_color;\

    return col;
  } else {
    return vec3();
  }
}

int main(int argc, char **argv) {
  string filename = "../teapot.obj";
  if (argc > 1) {
    filename = argv[1];
  }
  ifstream inFile;
  inFile.open(filename);
  if (!inFile) {
    cout << "Unable to open file" << endl;
    exit(1); // terminate with error
  }

  vector<vec3> vertices;
  vector<vec3> faces;
  string s;
  // for one indexing
  vertices.push_back(vec3());
  while (inFile >> s) {
    switch (s[0]) {
      double a, b, c;
      case 'v':
        inFile >> a >> b >> c;
        vertices.push_back(vec3(a, b, c));
        break;
      case 'f':
        inFile >> a >> b >> c;
        faces.push_back(vec3(a, b, c));
        break;
      case '#':
        getline(inFile, s);
        break;
    }
  }

  srand (time(NULL));
  unsigned width = 400;
  unsigned height = 400;

  pngutil::PNG img(width, height);

  vec3 lower_left_corner(-1, -1, 3.0);
  vec3 horizontal(2, 0.0, 0.0);
  vec3 vertical(0.0, 2, 0.0);

  hitable** list = new hitable* [faces.size()];
  for (size_t i = 0; i < faces.size(); i++) {
    vec3 v1 = vertices[(int)(faces[i][0])];
    vec3 v2 = vertices[(int)(faces[i][1])];
    vec3 v3 = vertices[(int)(faces[i][2])];
    list[i] = new triangle(v1, v2, v3, new lambertian(vec3(1, 0, 0)));
  }

  hitable *world = new hitable_list(list, faces.size());
  bvh_node *root = new bvh_node(list, faces.size(), 0, 5000);
  cout << root->box.min() << endl;
  cout << root->box.max() << endl;
  cout << "Number of faces: " << faces.size() << endl;
  orthogonal_camera cam_o(5);

  for (unsigned j = 0; j < height; j++) {
    for (unsigned i = 0; i < width; i++) {
      double u = double(i) / double(width);
      double v = double(height - 1 - j) / double(height);
      vec3 col_o;
      for (unsigned k = 0; k < 100; k++) {
        double jitter_x = rand_double() / width;
        double jitter_y = rand_double() / height;
        double x_comp = (u + jitter_x) * horizontal.x() + lower_left_corner.x();
        double y_comp = (v + jitter_y) * vertical.y() + lower_left_corner.y();
        ray r_o = cam_o.get_ray(x_comp, y_comp);
        col_o += color(r_o, root);
      }
      col_o /= 100;
      col_o = vec3(sqrt(col_o[0]), sqrt(col_o[1]), sqrt(col_o[2]));
      *img.getPixel(i, j) = pngutil::RGBAPixel(int(255.99 * col_o[0]), int(255.99 * col_o[1]), int(255.99 * col_o[2]));
    }
  }

  if (img.writeToFile("mp3.png")) {
    cout << "Image saved to mp3.png" << endl;
  } else {
    cout << "Could not write mp3 image" << endl;
  }
  delete root;
  return 0;
}
