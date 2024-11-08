#pragma once

#include "logger.h"

Logger& getLogger() {
    return Logger::getInstance();
}