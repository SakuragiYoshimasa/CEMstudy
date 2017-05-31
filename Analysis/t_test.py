# coding: utf-8
import os
import glob
import numpy as np
import pandas as pd
from scipy import stats
from pandas import DataFrame

if __name__ == '__main__':

    n_100_files = files = glob.glob('./Experiment/Results/ChangeN*/1*_N_se.csv')
    n_100_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        n_100_data = pd.concat([n_100_data, data])
        #print(csv_data['N'])

    up_rv_files = files = glob.glob('./Experiment/Results/UpdateRV/*_RV_se.csv')
    up_rv_data = pd.DataFrame({'N':[], 'rho':[], 'episode_num':[], 'update_params_num':[], 'step_num':[]})
    for file in files:
        data = pd.read_csv(file,sep=' ');
        up_rv_data = pd.concat([up_rv_data, data])
        #print(csv_data['N'])

    #print(up_rv_data)

    print(np.mean(n_100_data['update_params_num']))
    print(np.mean(up_rv_data['update_params_num']))


    t, p = stats.ttest_rel(n_100_data['update_params_num'], up_rv_data['update_params_num'])
    print('update_params_num t: %.2f, p: %.2f' % (t, p))
    print(p)

    print(np.mean(n_100_data['episode_num']))
    print(np.mean(up_rv_data['episode_num']))

    t, p = stats.ttest_rel(n_100_data['episode_num'], up_rv_data['episode_num'])
    print('episode_num t: %.2f, p: %.2f' % (t, p))
    print(p)
    print(np.mean(n_100_data['step_num']))
    print(np.mean(up_rv_data['step_num']))

    t, p = stats.ttest_rel(n_100_data['step_num'], up_rv_data['step_num'])
    print('step_num t: %.2f, p: %.2f' % (t, p))
    print(p)
