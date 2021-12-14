#include "shapes.h"

int main(void)
{
    shapes::Point2D point1({10, 10});
    shapes::Point2D point2({5, 5});

    std::cout << point1;
    point1 + point2;
    std::cout << (point1 == point2);

    return 0;
}
