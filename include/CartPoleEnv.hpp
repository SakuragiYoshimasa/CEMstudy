#ifndef CartPoleEnv_hpp
#define CartPoleEnv_hpp

#include "Env.hpp"

class CartPoleEnv : public Env {
public:
    const std::vector<double>& reset();
    int obs_dim();
    EnvResponse step(Action action);
    void end();

    static constexpr int MAX_STEP = 500;

    CartPoleEnv(){};
    ~CartPoleEnv(){};

private:
    int step_count;
    std::vector<double>* obs;

    void reset_host();
    void quit_host();
    void get_observation();
};

#endif /* CartPoleEnv_hpp */
