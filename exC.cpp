#include <iostream>
#include <memory>

class Coord {
  private:
    int x;
    int y;

  public:
    Coord(); // Construtor
    void set_coord(int x_new, int y_new);
};

void Coord::set_coord(int x_new, int y_new) {
  x = x_new;
  y = y_new;
}

Coord::Coord() {
}

class Cube {
    private:
        int x;
        int y;
        int z;
    
    public:
        Cube();
        void set_cube(int x_new, int y_new, int z_new);
        void get_volume();
};

void Cube::set_cube(int x_new, int y_new, int z_new) {
    x = x_new;
    y = y_new;
    z = z_new;
}

void Cube::get_volume() {
    int vol = x * y * z;
    std::cout << vol << std::endl; 
}

Cube::Cube(){    
}

int main() {
    std::unique_ptr<Coord> c1 (new Coord);
    c1 -> set_coord (5,10);

    std::unique_ptr<Cube> c2 (new Cube);
    c2 -> set_cube(5,2,3);
    c2 -> get_volume();

  return 0;
}
