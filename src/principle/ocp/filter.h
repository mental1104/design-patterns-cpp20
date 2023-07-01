#pragma once

#include <vector>
#include "specification.h"
using std::vector;


template <typename T>
struct Filter
{
    virtual vector<T*> filter(
        vector<T*> items,
        Specification<T>&& spec
    ) const = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(
        vector<Product*> items,
        Specification<Product>&& spec
    ) const override {
        vector<Product*> result;
        for(auto& p : items)
            if(spec.is_satisfied(p))
                result.push_back(p);
        return result;
    }
};