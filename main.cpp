#include <iostream>
#include <vector>
#include "shapes.h"
#include <memory>

using namespace shapes;

class _X {
public:
    _X() {}
    ~_X() {}
    void add_shape(const Shape2D &shape) { Line *ln = new Line(5, 5, 20, 20, { 0, 0, 0 }); _shapes.push_back(ln); }
    const std::vector<std::unique_ptr<Shape2D>>& get_shapes(void) const { return _shapes; }

private:
    std::vector<std::unique_ptr<Shape2D>> _shapes;
};

int main(void)
{
    _X x;
    Line ln(5, 5, 20, 20, { 0, 0, 0 });
    // Circle cr(20, 50, 10, { 0, 0, 0 });
    // Rect rect(33, 12, 50, 3, { 0, 0, 0 });
    x.add_shape(ln);
    // x.add_shape(cr);
    // x.add_shape(rect);


    x.get_shapes().at(0);

//    for (auto s : x.get_shapes())
//        for (auto i : s->get_bounds()) std::cout << "{" << i.get_x() << " " << i.get_y() << "} ";

    return 0;
}
