/*
 * Logger.cpp
 *
 *  Created on: Aug 19, 2011
 *      Author: c0rn0
 */

#include "Logger.h"

map<string, Logger*>* Logger::loggers;
bool Logger::__init = Logger::init();

Logger::~Logger() {
}

Logger* Logger::getLogger(string name) {

    init();

    map<string, Logger*>::iterator it;
    it = loggers->find(name);

    if (it == loggers->end()) {

        Logger* logger = new Logger(name);
        loggers->insert(pair<string, Logger*>(name, logger));

        cout << "Logger::loggers.size : " << loggers->size() << endl;
        return logger;

    } else {

        return it->second;

    }

}

void Logger::info(string logString) throw() {

    category->info(logString);

}
