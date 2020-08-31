#include <vector>

namespace Statistics {
    struct Stats
    {
        double average,min,max;
    };

    Stats ComputeStatistics(const std::vector<double>& );
}
