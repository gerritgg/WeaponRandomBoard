/*
 * Logger.cpp
 *
 *  Created on: Aug 19, 2011
 *      Author: c0rn0
 */

#include "Logger.h"

map<string, Logger*>* createMap(map<string, Logger*>* loggers) {
    if (!loggers) {
        loggers = new map<string, Logger*>;
    }
    return loggers;
}

map<string, Logger*>* Logger::loggers = createMap(loggers);;

Logger::~Logger() {
}

Logger* Logger::getLogger(string name) {

    loggers = createMap(loggers);

    map<string, Logger*>::iterator it;
    it = loggers->find(name);

    if (it == loggers->end()) {

        Logger* logger = new Logger(name);
        loggers->insert(pair<string, Logger*>(name, logger));

        return logger;

    } else {

        return it->second;

    }

}

void Logger::info(string logString) throw() {

    category->info(logString);

}
