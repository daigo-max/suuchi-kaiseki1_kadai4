// 線形代数2021/10/12 課題4 二分法
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>

double f (double x) { //f(x) = x + cos(x)の定義
    return x + cos(x);
}

double search_c (double a, double b) { //cの定義と解
    double c;
    int i = 0;
    while (fabs(b - a) > 1e-10) { // |a - b|が十分に小さくなったら終了(1の-10乗)
        c = (a + b) / 2; //中点cを求める

        if (f(c) == 0) { break; } //c０で終了
        if (f(a) * f(c) < 0) { b = c; }//解の区間を狭める
        if (f(c) * f(b) < 0){ a = c; }
    }
    return c;
}

int main (void) {
    double answer; //結果を表示するための変数
    answer = search_c(-100, 100); //とりあえず(a,b) = (-100, 100)とおく
    printf("f(x)=0 の解は %f です\n", answer); //結果の表示
    return 0;
}