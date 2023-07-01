#pragma once

#include <string>
using std::string;

template<typename T>
struct AndSpecification;

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };
enum class Feature { Less, Normal, More};

struct Product
{
    string name;
    Color color;
    Size size;
    Feature feature;
};


template <typename T>
struct Specification
{
    virtual bool is_satisfied(T* item) = 0;

    AndSpecification<T> operator&& (Specification& other)
    {
        return AndSpecification<T>(*this, other);
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    explicit ColorSpecification(const Color color) : color{color} {}

    bool is_satisfied(Product* item) override {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(const Size size) : size{size} {}

    bool is_satisfied(Product* item) override {
        return item->size == size;
    }
};

struct FeatureSpecification : Specification<Product>
{
    Feature feature;

    explicit FeatureSpecification(const Feature feature) : feature{feature} {}

    bool is_satisfied(Product* item) override {
        return item->feature == feature;
    }
};

template<typename T>
struct AndSpecification : Specification<T>
{
    Specification<T>& first;
    Specification<T>& second;

    AndSpecification(Specification<T>& first,
                     Specification<T>& second)
    : first{first}, second{second} {}

    bool is_satisfied(T* item) override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};