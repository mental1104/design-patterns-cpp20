#pragma once
#include <string>
#include "ilogger.h"
using std::string;


class Reporting
{
    ILogger& logger;
public:
    Reporting(ILogger& logger):logger{logger} {}
    void prepare_report();
};

void Reporting::prepare_report(){
    logger.log("Preparing the report");
}

