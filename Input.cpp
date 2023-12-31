#include <bits/stdc++.h>
using namespace std;

vector<double> FindCordinate(double Radius, double AnglePhi, double AngleTheta)
{

    double AnglePhiRadian = M_PI * AnglePhi / 180, AngleThetaRadian = M_PI * AngleTheta / 180;
    double XCordinate = Radius * sin(AnglePhiRadian) * cos(AngleThetaRadian), YCordinate = Radius * sin(AnglePhiRadian) * sin(AngleThetaRadian), ZCordinate = Radius * cos(AnglePhiRadian);
    vector<double> Cordinate;
    Cordinate.push_back(XCordinate);
    Cordinate.push_back(YCordinate);
    Cordinate.push_back(ZCordinate);
    return Cordinate;
}

int main(int argc, char const *argv[])
{
    // vector<double> Cordinate = FindCordinate(3, 60, 45);
    // cout << Cordinate[0] << " " << Cordinate[1] << " " << Cordinate[2] << endl;
    vector<vector<double>> Cordinates;
    vector<double> Cordinate = {0, 0, 0};
    Cordinates.push_back(Cordinate);
    int NumberOfParitcles;
    cin >> "Enter the number of particles: " >> NumberOfParitcles;
    for (int i = 2; i < NumberOfParitcles + 1; i++)
    {
        double Radius, AnglePhi, AngleTheta, ParticleType;
        cin >> "Enter Radius For Particle " + i >> Radius >> "Enter AnglePhi For Particle " + i >> AnglePhi >> "Enter AngleTheta For Particle " + i >> AngleTheta >> "Enter ParticleType For Particle " + i >> ParticleType;
        Cordinate = FindCordinate(Radius, AnglePhi, AngleTheta);
        Cordinates.push_back(Cordinate);
    }
    return 0;
}
