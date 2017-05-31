#ifndef EasyEnv_hpp
#define EasyEnv_hpp

#include "Env.hpp"
#include <random>

class EasyEnv : public Env {
public:
    const std::vector<double>& reset();
    int obs_dim();
    EnvResponse step(Action action);
    void end(){}

    EasyEnv();
    ~EasyEnv();

private:
    int step_count;
    double prev_obs;
    std::vector<double>* obs;
    std::random_device rnd;
    std::mt19937 mt;
    std::uniform_real_distribution<> rand;
};
#endif /* EasyEnv_hpp */
