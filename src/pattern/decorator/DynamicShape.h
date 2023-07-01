#include <sstream>
#include <string>

using std::string;
using std::ostringstream;

struct Shape
{
    virtual string str() const = 0;
};

struct Circle : Shape
{
    float radius;
    explicit Circle(const float radius)
         : radius{radius} {}

    void resize(float factor) { radius *= factor; }

    string str() const override
    {
        ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
}; 

struct Square : Shape
{
    float size;
    explicit Square(const float size)
         : size{size} {}

    void resize(float factor) { size *= factor; }

    string str() const override
    {
        ostringstream oss;
        oss << "A Square of size " << size;
        return oss.str();
    }
};

struct ColoredShape : Shape
{
    Shape& shape;
    string color;

    ColoredShape(Shape& shape, const string& color)
        : shape{shape}, color{color} {}

    void make_dark();

    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has the color " << color;
        return oss.str();
    }
};

void ColoredShape::make_dark() {
    if (constexpr auto dark = "dark "; !color.starts_with(dark))
    color.insert(0, dark);
}

struct TransparentShape : Shape
{
    Shape& shape;
    uint8_t transparency;
    TransparentShape(Shape& shape, const uint8_t transparency): shape{shape}, transparency{transparency} {}
    
    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has "
            << static_cast<float>(transparency) / 255.f*100.f
            << "% transparency";
        return oss.str();
    }
};