#pragma once
#include <iostream>
#include <memory>
#include "ilogger.h"
#include "engine.h"

using std::ostream;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;

struct Car
{
    unique_ptr<Engine> engine;
    shared_ptr<ILogger> logger;

    Car(unique_ptr<Engine> engine,
        const shared_ptr<ILogger>& logger)
        : engine{move(engine)}, logger{logger}
    {
        logger->log("making a car");
    }

    friend ostream& operator<<(ostream& os, const Car& obj)
    {
        return os << "car with engine: " << *obj.engine;
    }
};