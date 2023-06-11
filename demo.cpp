#include "Header.h"
#include <cstdio>
#include "ZPSOAlgorithm.h"
#include <math.h>
#include <iostream>

int main(){
  /*  Test the basic benchmark function */
  double* X;
  Benchmarks* fp=NULL;
  unsigned dim = 1000;
  unsigned funToRun[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  // unsigned funToRun[] = {1};
  // unsigned funToRun[] = {15};
  unsigned funNum = 15;
  unsigned run = 1;  //每个函数只跑一次

  vector<double> runTimeVec;
        
  X = new double[dim];
  for (unsigned i=0; i<dim; i++){
    X[i]=0;
  }

  for (unsigned i=1; i<2; i++){  //遍历每个函数
    fp = generateFuncObj(funToRun[2]); 
    printf("F %d value = %1.20E\n", fp->getID(), fp->compute(X));
    for (unsigned j=0; j < run; j++){
        //定义求解范围,x在[-10,10]范围，y在[-10,10]范围（二维
        double minPos[1000] = { 0};
        double maxPos[1000] = { 0};
        for (unsigned i = 0; i < dim; i++) {
            minPos[i] = -100;
            maxPos[i] = 100;
        }
        //定义问题描述参数
        //int dimension = 2; //候选解维度
        int particalCount = 200; //粒子群粒子个数
        double globalGuideCoe = 1; //全局引导加速度
        double localGuideCoe = 1; //局部引导加速度
        double maxSpeed = 4; //粒子最大速度
        cout<<"开始初始化"<<endl;
        //构建pso算法
        ZPSO_Algorithm pso(fp, minPos, maxPos, dim, particalCount,
            globalGuideCoe, localGuideCoe, maxSpeed);
        //运行pso算法
        ZPSO_Partical bestPartical; //粒子群最终进化结果
        int generation = 500000; //粒子群进化代数
        cout << "初始化完成"<<endl;
        pso.findMax(generation, bestPartical); //获取最终进化结果
        //输出最终结果
        cout << "the best position for the objFunction is:" << endl;
        for (int i = 0; i < dim; i++) {
            cout << bestPartical._position[i] << endl;
        }
        cout << "the best fitness for the objFunction is:" << bestPartical._fitness << endl;
    }

    delete fp;
  }

  delete []X;

  // for (unsigned i=0; i<runTimeVec.size(); i++){
  // 	printf ( "%f\n", runTimeVec[i] );
  // }

  return 0;
}

// create new object of class with default setting
Benchmarks* generateFuncObj(int funcID){
  Benchmarks *fp;
  // run each of specified function in "configure.ini"
  if (funcID==1){
    fp = new F1();
  }else if (funcID==2){
    fp = new F2();
  }else if (funcID == 3) {
    fp = new F3();
  }else if (funcID==4){
    fp = new F4();
  }else if (funcID==5){
    fp = new F5();
  }else if (funcID==6){
    fp = new F6();
  }else if (funcID==7){
    fp = new F7();
  }else if (funcID==8){
    fp = new F8();
  }else if (funcID==9){
    fp = new F9();
  }else if (funcID==10){
    fp = new F10();
  }else if (funcID==11){
    fp = new F11();
  }else if (funcID==12){
    fp = new F12();
  }else if (funcID==13){
    fp = new F13();
  }else if (funcID==14){
    fp = new F14();
  }else if (funcID==15){
    fp = new F15();
  }else{
    cerr<<"Fail to locate Specified Function Index"<<endl;
    exit(-1);
  }
  return fp;
}
