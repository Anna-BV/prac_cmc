
#include <iostream>
#include <fstream>
#include <iomanip> 

using namespace std;

const double eps = 0.5;
const int N = 3; // количество уравнений

// метод Рунге-Кута
// h - шаг по времени
// E1,E2,E3 и m - параметры 
double* Method(double E1, double E2, double E3, double m, double* Y, double h) {
    double* NextY = new double[N];
    double* Arr = new double[N];
   // k1,k2,k3,k4 - приближающие угловые коэффициенты

    double* k1 = new double[N]; // в исходной точке
    k1[0] = Y[0] * ((3 - 4 * m) - Y[0] - Y[1] - Y[2]); // посчитаем правую часть уравнения
    k1[1] = Y[1] * (-E2 + Y[0] + 2 * m * Y[1]);
    k1[2] = Y[2] * (-E3 + Y[1]);
    Arr[0] = Y[0] + h / 2 * k1[0];
    Arr[1] = Y[1] + h / 2 * k1[1];
    Arr[2] = Y[2] + h / 2 * k1[2];
    
    // на половинном шаге
    double* k2 = new double[N];
    k2[0] = Arr[0] * ((3 - 4 * m) - Arr[0] - Arr[1] - Arr[2]);
    k2[1] = Arr[1] * (-E2 + Arr[0] + 2 * m * Arr[1]);
    k2[2] = Arr[2] * (-E3 + Arr[1]);
    Arr[0] = Y[0] + h / 2 * k2[0];
    Arr[1] = Y[1] + h / 2 * k2[1];
    Arr[2] = Y[2] + h / 2 * k2[2];
    
    //тоже на половинном шаге, но по уточненному значению углового коэффициента k2 вместо k1
    double* k3 = new double[N];
    k3[0] = Arr[0] * ((3 - 4 * m) - Arr[0] - Arr[1] - Arr[2]);
    k3[1] = Arr[1] * (-E2 + Arr[0] + 2 * m * Arr[1]);
    k3[2] = Arr[2] * (-E3 + Arr[1]);
    Arr[0] = Y[0] + h * k3[0];
    Arr[1] = Y[1] + h * k3[1];
    Arr[2] = Y[2] + h * k3[2];

    // на целом шаге по предыдущему значению k3
    double* k4 = new double[N];
    k4[0] = Arr[0] * ((3 - 4 * m) - Arr[0] - Arr[1] - Arr[2]);
    k4[1] = Arr[1] * (-E2 + Arr[0] + 2 * m * Arr[1]);
    k4[2] = Arr[2] * (-E3 + Arr[1]);

    NextY[0] = Y[0] + h / 6 * (k1[0] + 2 * k2[0] + 2 * k3[0] + k4[0]);
    NextY[1] = Y[1] + h / 6 * (k1[1] + 2 * k2[1] + 2 * k3[1] + k4[1]);
    NextY[2] = Y[2] + h / 6 * (k1[2] + 2 * k2[2] + 2 * k3[2] + k4[2]);

    return NextY;

}


int main()
{
  
    double* Y = new double[N];
    double E1,E2,E3; // параметры const
    double m; // меняющийся параметр
    double h = 0.005; // шаг по времени
    double Time = 200; //  m = 0.2 хаотический режим
    cout << "Введите параметры\n";
    cout << "E1: ";
    cin >> E1;
    cout << "E2: ";
    cin >> E2;
    cout << "E3: ";
    cin >> E3;
    cout << "m: ";
    cin >> m;

    ofstream modelP;
    modelP.open("file.txt");
    // начальные условия Задачи Коши
    Y[0] = E2 - 2 * m * E3 + eps;
    cout << "Y1 = " << Y[0] << endl;
    Y[1] = E3 + eps;
    cout << "Y2 = " << Y[1] << endl;
    Y[2] = 3 - 4 * m + 2 * m * E3 - E2 - E3 + eps;
    cout << "Y3 = " << Y[2] << endl;

    modelP << setfill(' ');
    modelP << "# E1 = " << E1 << " E2 = " << E2 << " E3 = " << E3 << " m = " << m << " Eps = " << eps << endl;
    modelP << setw(10) << left << "# Time" << setw(20) << left << "Y_1" << setw(20) << left << "Y_2" << setw(20) << left << "Y_3" << endl;
    
    double t = 0;
    while (t < Time) {
      
            Y = Method(E1, E2, E3, m, Y, h);
            t += h;
        
        modelP << setfill(' ');
        modelP << setw(10) << left << t << setw(20) << left << Y[0] << setw(20) << left << Y[1] << setw(20) << left << Y[2] << endl;
    }
    return 0;
}

