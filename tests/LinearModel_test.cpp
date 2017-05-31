#ifndef LinearModel_tset_cpp
#define LinearModel_tset_cpp

#include "./../include/LinearModel.hpp"
#include <assert.h>

void linearmodel_test(){
    std::vector<double> initial_params = *new std::vector<double>{1.0, 2.0, 3.0, 4.0};

    LinearModel* model = new LinearModel(initial_params);

    for(int i = 0; i < 4; i++){
        assert(model->getParams()[i] == initial_params[i]);
    }

    assert(model->action(*new std::vector<double>{1.0, 2.0, 3.0, 4.0}) == Action::A);
    assert(model->action(*new std::vector<double>{1.0, 2.0, 3.0, -4.0}) == Action::B);
    std::cerr << "model test passed" << std::endl;
}

int main(int argc,char **argv){
    linearmodel_test();
    return 0;
}

#endif // LinearModel_tset_cpp
