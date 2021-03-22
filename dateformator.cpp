#include "dateformator.h"

DateFormator::DateFormator()
{
    months["Jan"] = 1;
    months["Feb"] = 2;
    months["Mar"] = 3;
    months["Apr"] = 4;
    months["May"] = 5;
    months["Jun"] = 6;
    months["Jul"] = 7;
    months["Aug"] = 8;
    months["Sep"] = 9;
    months["Oct"] = 10;
    months["Nov"] = 11;
    months["Dec"] = 12;
}

std::string DateFormator::parse(std::string date) {
    int day, month, year;
    int res = std::sscanf(date.c_str(), "%2d/%2d/%4d", &day, &month, &year);
    if(res == 3){
        auto d = std::to_string(day);
        d = std::string(2 - d.length(), '0') + d;
        auto m = std::to_string(month);
        m = std::string(2 - m.length(), '0') + m;
        auto y = std::to_string(year);
        y = std::string(4 - y.length(), '0') + y;
        return y + "-" + m + "-" + d;
    }
    res = std::sscanf(date.c_str(), "%2d-%2d-%4d", &day, &month, &year);
    if(res == 3){
        auto d = std::to_string(day);
        d = std::string(2 - d.length(), '0') + d;
        auto m = std::to_string(month);
        m = std::string(2 - m.length(), '0') + m;
        auto y = std::to_string(year);
        y = std::string(4 - y.length(), '0') + y;
        return y + "-" + m + "-" + d;
    }

    char monthCStr[4];
    res = std::sscanf(date.c_str(), "%3s%4d", monthCStr, &year);
    if(res == 2){
        std::string monthStr = std::string(monthCStr);
        if ( months.find(monthStr) != months.end() ) {
            auto m = std::to_string(months.at(monthStr));
            auto y = std::to_string(year);
            y = std::string(4 - y.length(), '0') + y;
            return y +  m + "-" + "01-" + std::string(2 - m.length(), '0');
        }
    }

    return "";
}
