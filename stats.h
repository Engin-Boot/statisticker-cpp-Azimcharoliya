#include <vector>

namespace Statistics {
    
    template<class TYPE>
    struct Stats
    {
        TYPE min,max;
        double average;
    };

    template <typename TYPE1>
    Stats<TYPE1> ComputeStatistics(const std::vector<TYPE1>& );
}
