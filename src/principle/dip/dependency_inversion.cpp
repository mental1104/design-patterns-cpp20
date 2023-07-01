#include <iostream>
#include <boost/di.hpp>

#include "ilogger.h"
#include "car.h"

namespace di = boost::di;

int main(){
    auto injector = di::make_injector(
        di::bind<ILogger>().to<ConsoleLogger>()
    );

    auto car = injector.create<shared_ptr<Car>>();
    std::cout << *car << std::endl;
}