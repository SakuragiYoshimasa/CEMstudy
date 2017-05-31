# coding: utf-8
import os
import glob
import numpy as np
import pandas as pd
from scipy import stats
from pandas import DataFrame

if __name__ == '__main__':

    #rho = {0.5, 0.1, 0.15, 0.2};
    files = glob.glob('./Experiment/Results/ChangeRho*/0*_Rho_se.csv')
    rho_05_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rho_05_data = pd.concat([rho_05_data, data])

    files = glob.glob('./Experiment/Results/ChangeRho*/1*_Rho_se.csv')
    rho_10_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rho_10_data = pd.concat([rho_10_data, data])

    files = glob.glob('./Experiment/Results/ChangeRho*/2*_Rho_se.csv')
    rho_15_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rho_15_data = pd.concat([rho_15_data, data])

    files = glob.glob('./Experiment/Results/ChangeRho*/3*_Rho_se.csv')
    rho_20_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        rho_20_data = pd.concat([rho_20_data, data])

    print('episode_num')
    print(np.mean(rho_05_data['episode_num']))
    print(np.mean(rho_10_data['episode_num']))
    print(np.mean(rho_15_data['episode_num']))
    print(np.mean(rho_20_data['episode_num']))

    f_val, p_val = stats.f_oneway(rho_05_data['episode_num'], rho_10_data['episode_num'],rho_15_data['episode_num'], rho_20_data['episode_num'])
    print('episode_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)

    print('update_params_num')
    print(np.mean(rho_05_data['update_params_num']))
    print(np.mean(rho_10_data['update_params_num']))
    print(np.mean(rho_15_data['update_params_num']))
    print(np.mean(rho_20_data['update_params_num']))

    f_val, p_val = stats.f_oneway(rho_05_data['update_params_num'], rho_10_data['update_params_num'],rho_15_data['update_params_num'], rho_20_data['update_params_num'])
    print('update_params_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)

    print('step_num')
    print(np.mean(rho_05_data['step_num']))
    print(np.mean(rho_10_data['step_num']))
    print(np.mean(rho_15_data['step_num']))
    print(np.mean(rho_20_data['step_num']))

    f_val, p_val = stats.f_oneway(rho_05_data['step_num'], rho_10_data['step_num'],rho_15_data['step_num'], rho_20_data['step_num'])
    print('step_num f: %.10f, p: %.10f' % (f_val, p_val))
    print(p_val)
