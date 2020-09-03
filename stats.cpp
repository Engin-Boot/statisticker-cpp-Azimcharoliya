#include "stats.h"
#include "limits"

template <typename TYPE1>
double calculateAverage(const std::vector<TYPE1>& values)
{
    double sum=0;
    for(unsigned int i=0;i<values.size();i++)
    {
        sum += values[i];
    }
    sum /= values.size();
    return sum;
}


template <typename TYPE1>
TYPE1 calculateMin(const std::vector<TYPE1>& values)
{
    TYPE1 min=values[0];
    
    for(unsigned int i=1;i<values.size();i++)
    {
        if(min > values[i])
            min = values[i];
    }

    return min;
}


template <typename TYPE1>
TYPE1 calculateMax(const std::vector<TYPE1>& values)
{
    TYPE1 max=values[0];
    
    for(unsigned int i=1;i<values.size();i++)
    {
        if(max < values[i])
            max = values[i];
    }

    return max;
}

template <typename TYPE1>
Statistics::Stats<TYPE1> Statistics::ComputeStatistics(const std::vector<TYPE1>& values) {
    //Implement statistics here
    Stats<TYPE1> computedValues;

    if(values.size() == 0)
    {
        computedValues.average = std::numeric_limits<TYPE1>::quiet_NaN();
        computedValues.min = std::numeric_limits<TYPE1>::quiet_NaN();
        computedValues.max = std::numeric_limits<TYPE1>::quiet_NaN();
        return computedValues;
    }

    computedValues.min = calculateMin(values);
    computedValues.max = calculateMax(values);
    computedValues.average = calculateAverage(values);
    return computedValues;
}

template <>
Statistics::Stats<char> Statistics::ComputeStatistics(const std::vector<char>& values) {
    //Implement statistics here
    Stats<char> computedValues;

    computedValues.min = calculateMin(values);
    computedValues.max = calculateMax(values);
    computedValues.average = std::numeric_limits<double>::quiet_NaN();
    return computedValues;
}

