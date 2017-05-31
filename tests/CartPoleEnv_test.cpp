#ifndef CartPoleEnv_test_cpp
#define CartPoleEnv_test_cpp

#include <stdio.h>
#include <assert.h>
#include "./../include/CartPoleEnv.hpp"
#include "./../include/reactive.hpp"

void reset_step_test(){

    CartPoleEnv* env = new CartPoleEnv();
    EnvResponse res;
    int step = 0;
    env->reset();

    do {
        Action action = rand() > RAND_MAX / 2 ? Action::A : Action::B;
        res = env->step(action);
        assert(res.reward == 1.0);

        std::cerr << "obs ";
        for(int i = 0; i < res.observation->size(); i++) std::cerr << res.observation->at(i) << " ";
        std::cerr << std::endl;
        step++;
    }while(!res.isFinished);

    assert(step == 500);

    delete env;

    std::cerr << "step test passed" << std::endl;
}

void obs_dim_test(){
    CartPoleEnv* env = new CartPoleEnv();
    assert(env->obs_dim() == 4);
    delete env;
    std::cerr << "obs_dim test passed" << std::endl;
}


int main(int argc,char **argv) {
    obs_dim_test();
    reset_step_test();
    return 0;
}

#endif // CartPoleEnv_test_cpp
