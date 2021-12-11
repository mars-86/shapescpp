#include <iostream>
#include <vector>
#include "shapes.h"
#include <memory>

using namespace shapes;

int main(void)
{

    Square sq(10, 10, 5);
    Circle circ(40, 40, 5);
    Ellipse ell(40, 40, 5, 5);
    Line ln(1, 1, 10, 10);
    Parable pb(3, 3, 6, 6);
    Rect rect(10, 10, 6, 7);

    FreeHand fh({{10, 10},{40, 30},{22, 5},{13, 50},{1, 70}});
    // auto b = rect.get_bounds();
    // for (auto i : b) std::cout << "{" << i.get_x() << " " << i.get_y() << "}";

    return 0;
}
