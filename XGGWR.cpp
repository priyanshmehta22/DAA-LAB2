#include <iostream>
#include <cmath>

//MARK: ques 3.1 recursive method
int fibonacci1(int n){
    //base conditions if n = 1 or 0
    if (n ==0) {
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else{
        return fibonacci1(n-1) + fibonacci1(n-2); //recursive call until base condition is reached
    }
}


//MARK: ques 3.2 iterative method
int fibonacci2(int n){
    int arr[n]; //create an array of size n that will store the values of fibonacci series from 0 to n
    arr[0] = 0; //setting initial 2 values of the series
    arr[1] = 1;
    for (int i = 2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

//MARK: ques 3.3 binet's formula method
double fibonacci3(int n){
    double a = (1+sqrt(5))/2;
    double b = (1-sqrt(5))/2;
    double  ans = (1/sqrt(5)) * (pow(a, n) - pow(b, n));
    return ans;
}



//MARK: ques 3.4 matrix method
void power(int F[2][2], int n){
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
    for(int i = 2; i <= n; i++){
        
        int x = (F[0][0] * M[0][0]) + (F[0][1] * M[1][0]);
        int y = (F[0][0] * M[0][1]) + (F[0][1] * M[1][1]);
        int z = (F[1][0] * M[0][0]) + (F[1][1] * M[1][0]);
        int w = (F[1][0] * M[0][1]) + (F[1][1] * M[1][1]);
        
        F[0][0] = x;
        F[0][1] = y;
        F[1][0] = z;
        F[1][1] = w;
    }
}

int fibonacci4(int n){
    int F[2][2] = { { 1, 1 }, { 1, 0 } };
    if (n == 0)
        return 0;
    
    power(F, n - 1);
    return F[0][0];
}


//MARK: running code
int main ()
{
    int n = 9;
    std::cout << "using recursive method: " << fibonacci1(n)  << std::endl;
    std::cout << "using iterative method: " << fibonacci2(n) << std::endl;
    std::cout << "using matrix method: " << fibonacci4(n) << std::endl;
    std::cout << "using binet's formula: " << fibonacci3(n) << std::endl;
    return 0;
}
