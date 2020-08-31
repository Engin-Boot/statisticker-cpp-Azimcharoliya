#include "stats.h"
#include "limits"

double calculateAverage(const std::vector<double>& values)
{
    double sum=0;
    for(int i=0;i<values.size();i++)
    {
        sum += values[i];
    }
    sum /= values.size();
    return sum;
}

double calculateMin(const std::vector<double>& values)
{
    double min=values[0];
    
    for(int i=1;i<values.size();i++)
    {
        if(min > values[i])
            min = values[i];
    }

    return min;
}


double calculateMax(const std::vector<double>& values)
{
    double max=values[0];
    
    for(int i=1;i<values.size();i++)
    {
        if(max < values[i])
            max = values[i];
    }

    return max;
}

//template <typename type = float>
Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& values) {
    //Implement statistics here
    struct Stats computedValues;

    if(values.size() == 0)
    {
        computedValues.average = std::numeric_limits<float>::quiet_NaN();
        computedValues.min = std::numeric_limits<float>::quiet_NaN();
        computedValues.max = std::numeric_limits<float>::quiet_NaN();
        return computedValues;
    }

    computedValues.min = calculateMin(values);
    computedValues.max = calculateMax(values);
    computedValues.average = calculateAverage(values);
    return computedValues;
}
