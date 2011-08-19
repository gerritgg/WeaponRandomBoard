/*
 * Logger.h
 *
 *  Created on: Aug 19, 2011
 *      Author: c0rn0
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <map>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/PatternLayout.hh>

using namespace std;
using namespace log4cpp;

#define LOGFILE "/var/log/weaponrandomboard/weaponrandomboard.log"

class Logger {
public:

    virtual ~Logger();

    static map<string, Logger*>* loggers;
    static Logger* getLogger(string name);

    void info(string logString) throw();


private:

    Category* category;

    Logger(string categoryName) {

        //Private constructor so can not be publicly instantiated.
        Appender* appender = new FileAppender("FileAppender", LOGFILE);
        PatternLayout* layout = new PatternLayout();
        layout->setConversionPattern(PatternLayout::TTCC_CONVERSION_PATTERN);
        Logger::category = &Category::getInstance(categoryName);

        appender->setLayout(layout);
        category->setAppender(appender);
        category->setPriority(Priority::INFO);

    }

};

#endif /* LOGGER_H_ */
