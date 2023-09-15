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
    cout<<"Enter the number of particles: ";
    cin >> NumberOfParitcles;
    for (int i = 2; i < NumberOfParitcles + 1; i++)
    {
        double Radius, AnglePhi, AngleTheta, ParticleType;
        cout<<"Enter Radius, AnglePhi, AngleTheta, ParticleType  For Particle "<<i<<" ";
        cin >> Radius>>AnglePhi>>AngleTheta>>ParticleType;
        Cordinate = FindCordinate(Radius, AnglePhi, AngleTheta);
        Cordinates.push_back(Cordinate);
    }
    ofstream outputFile("StructuralCordinate.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the file!" << std::endl;
        return 1; // Return an error code
    }
    outputFile << "x y z" << endl;
    for (int i = 0; i < NumberOfParitcles; i++)
    {
        outputFile << Cordinates[i][0] << " " << Cordinates[i][1] << " " << Cordinates[i][2] << endl;
    }
    outputFile.close();
    return 0;
}