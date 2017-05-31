#include "LinearModel.hpp"

LinearModel::LinearModel(const std::vector<double>& initial_params){
    dim_size = (int)initial_params.size();
    params = *new std::vector<double>(dim_size, 0);
    for(int i = 0; i < dim_size; i++) params[i] = initial_params[i];
}

Action LinearModel::action(const std::vector<double>& obs){
    double dot = 0;
    for(int i = 0; i < dim_size; i++) dot += obs[i] * params[i];
    return dot >= 0 ? Action::A : Action::B;
}

void LinearModel::updateParams(const std::vector<double>& diff_params){
    for(int i = 0; i < dim_size; i++) params[i] += diff_params[i];
}

void LinearModel::replaceParams(const std::vector<double>& new_params){
    for(int i = 0; i < dim_size; i++) params[i] = new_params[i];
}

const std::vector<double>& LinearModel::getParams(){
    return params;
}
