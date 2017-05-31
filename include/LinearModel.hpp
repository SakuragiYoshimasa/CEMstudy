#ifndef LinearModel_hpp
#define LinearModel_hpp

#include "CartPoleEnv.hpp"

class LinearModel {
public:
    LinearModel(const std::vector<double>& initial_params);
    void updateParams(const std::vector<double>& diff_params);
    void replaceParams(const std::vector<double>& new_params);
    Action action(const std::vector<double>& obs);
    const std::vector<double>& getParams();
private:
    int dim_size;
    std::vector<double> params;
};

#endif /* LinearModel_hpp */
