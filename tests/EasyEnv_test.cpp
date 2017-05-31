#ifndef EasyEnv_test_cpp
#define EasyEnv_test_cpp

#include "./../i/EasyEnv.hpp"
#include <assert.h>

void reset_test(){
    EasyEnv* env = new EasyEnv();
    for(int i = 0; i < 100; i++){
        double sample = env->reset()[0];
        assert(sample >= -1.0 && sample <= 1.0);
    }
    delete env;
    std::cerr << "reset test passed" << std::endl;
}

void obs_dim_test(){
    EasyEnv* env = new EasyEnv();
    env->reset();
    assert(env->obs_dim() == 1);
    delete env;
    std::cerr << "obs_dim test passed" << std::endl;
}

void step_test(){
    for(int i = 0; i < 10; i++) {
        EasyEnv* env = new EasyEnv();

        double prev_obs = env->reset()[0];
        EnvResponse res;
        int step = 0;

        do {
            Action action = rand() > RAND_MAX / 2 ? Action::A : Action::B;
            res = env->step(action);
            assert(res.reward == action * prev_obs);
            prev_obs = res.observation->at(0);
            step++;
        }while(!res.isFinished);
        assert(step == 10);

        delete env;
    }
    std::cerr << "step test passed" << std::endl;
}

void easyenv_test(){
    std::cerr << "EasyEnv test start" << std::endl;

    reset_test();
    obs_dim_test();
    step_test();


    std::cerr << "Test Finished!" << std::endl;
}

int main(int argc,char **argv){
    easyenv_test();
    return 0;
}

#endif /* EasyEnv_test_cpp */
