#include <iostream>
#include <vector>
#include "shapes.h"
#include <memory>

using namespace shapes;


int main(void)
{
    // Square rect(10, 10, 5);
    Circle circ(40, 40, 5);
    // Ellipse ell(40, 40, 5, 5);

    // auto b = rect.get_bounds();
    // for (auto i : b) std::cout << "{" << i.get_x() << " " << i.get_y() << "}";

    return 0;
}
