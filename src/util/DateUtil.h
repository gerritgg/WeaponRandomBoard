/*
 * DateUtil.h
 *
 *  Created on: 17 Nov 2011
 *      Author: c0rn0
 */

#ifndef DATEUTIL_H_
#define DATEUTIL_H_

#include <boost/date_time/posix_time/posix_time.hpp>

namespace board {
namespace util {

class DateUtil {
public:

    DateUtil();
    virtual ~DateUtil();

    static boost::posix_time::time_duration::tick_type getMillisForDate(
            int year, int month, int day) {

        using boost::gregorian::date;
        using boost::posix_time::ptime;
        using boost::posix_time::time_duration;
        using boost::posix_time::microsec_clock;

        ptime date1(date(year, month, day), time_duration(0, 0, 0));
        static ptime const epoch(date(1970, 1, 1));

        return (date1 - epoch).total_milliseconds();

    }

    static boost::posix_time::time_duration::tick_type getCurrentMillis() {

        using boost::gregorian::date;
        using boost::posix_time::ptime;
        using boost::posix_time::time_duration;
        using boost::posix_time::microsec_clock;

        static ptime const epoch(date(1970, 1, 1));

        return (microsec_clock::local_time() - epoch).total_milliseconds();

    }

};

} /* namespace util */
} /* namespace board */
#endif /* DATEUTIL_H_ */
