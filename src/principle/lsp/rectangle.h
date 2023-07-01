#pragma once

class Rectangle {
protected:
    int width;
    int height;
public:
    Rectangle(const int width, const int height)
        : width{width}, height{height} {}
    
    int get_width() const { return width; }
    virtual void set_width(const int width) { this->width = width; }
    int get_height() const { return height; }
    virtual void set_height(const int height) { this->height = height; }

    int area() const { return width * height; }
    bool is_square() const { return width == height; }
};

class Square : public Rectangle{
public:
    Square(int size) : Rectangle(size, size) {}
    void set_width(const int width) override {
        this->width = height = width;
    }

    void set_height(const int height) override {
        this->height = width = height;
    }
};

struct RectangleFactory {
    static Rectangle create_rectangle(int w, int h);
    static Rectangle create_square(int size);
};
