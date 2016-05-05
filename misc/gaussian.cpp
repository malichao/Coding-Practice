/******************************************************************************
 Author      : Lichao Ma
 Date        : May 4,2016
 Version     : v0.1
 Built       : Sublime GCC, -std=c++11
 Description :
 An example of generating Gaussian kernel,which could be used to blur an
 image.
 *****************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;
#define N 5

void createFilter(double gKernel[][N]) {
    // set standard deviation to 1.0
    double sigma = 1.0;
    double r, s = 2.0 * sigma * sigma;

    // sum is for normalization
    double sum = 0.0;

    // generate 5x5 kernel
    for (int x = -N / 2; x <= N / 2; x++) {
        for (int y = -N / 2; y <= N / 2; y++) {
            r = sqrt(x * x + y * y);
            gKernel[x + 2][y + 2] = (exp(-(r * r) / s)) / (M_PI * s);
            sum += gKernel[x + 2][y + 2];
        }
    }

    // normalize the Kernel
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            gKernel[i][j] /= sum;

}

int main() {
    double gKernel[N][N];
    createFilter(gKernel);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            printf("%.3f\t", gKernel[i][j]);
        cout << endl;
    }
}
