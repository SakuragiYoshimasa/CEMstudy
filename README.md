# CEMstudy


## プログラムに関して
以下のプログラム及びコマンドはCEMstudtyディレクトリでの作業を想定しています．  
分析用のpythonファイルなど一部想定外のディレクトリでは動作しない可能性があります．  


### 実行環境
macOS Sierra v10.12.5  
gcc  
C++11  
python3.6.0 :: Anaconda 4.3.1 (x86_64)

### 実行手順

　EasyEnvのテスト．  
```  
./bin/EasyEnv_test.out  
```  

実行ファイルを生成 
```  
make EasyEnv_test -f test_makefile  
```  

CartPoleEnvのテスト．  
```    
./bin/CartPoleTestEnv.out ./bin/CartPoleEnv_test.out   
```    

実行ファイルを生成  
```  
make CartPoleTestEnv -f test_makefile  
make CartPoleEnv_test -f test_makefile  
```  

LinearModelのテスト．  
```  
./bin/LinearModel_test.out    
```  

実行ファイルを生成  
```
make LinearModel_test -f test_makefile
```

CEMのEasyEnvでの動作確認．  
```
./bin/CEM_test.out
```
実行ファイルを生成
```
make CEM_test -f test_makefile
```

学習及びパラメータ出力  
```
./bin/cartpole.out ./bin/main.out  
```

実行ファイルを生成
```
make
```

Nを変動(出力は ./Experiment/Result/ChangeN に)  
```
./bin/cartpole.out ./bin/Experiment_change_n.out
```

Rhoを変動(出力は ./Experiment/Result/ChangeRho に)  
```
./bin/cartpole.out ./bin/Experiment_change_rho.out
```

ノイズの分散を変動 (出力は ./Experiment/Result/ChangeVR に)  
```
./bin/cartpole.out ./bin/Experiment_change_rv.out
```
CEMの更新規則に分散の更新を追加
```
./bin/cartpole.out ./bin/Experiment_update_rv.out
```

それぞれ実行ファイルの生成 
```
make Experiment_change_n -f experiment_makefile
make Experiment_change_rho -f experiment_makefile
make Experiment_change_rv -f experiment_makefile
make Experiment_update_rv -f experiment_makefile
```

分析用pythonスクリプトの実行  
```
python ./Analysis/スクリプト名
```
