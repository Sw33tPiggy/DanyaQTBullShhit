#ifndef DATEFORMATOR_H
#define DATEFORMATOR_H

#include <string>
#include <cstdio>
#include <map>

class DateFormator
{
public:
    DateFormator();
    std::string parse(std::string date);
    std::map<std::string, int> months;
};

#endif // DATEFORMATOR_H
