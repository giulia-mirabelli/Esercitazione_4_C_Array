#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include <iomanip>

using namespace std;

double V (double *w, double *r, double s, int n)
{
    double sum=0;

    for(int i=0;i<n;i++)
    {
        sum= sum+w[i]*s*(1+r[i]);
    }

    return sum;
}

double RoR(double s, double v)
{
    double r=v/s-1;
    return r;
}

int main()
{
    string nameFile = "data.csv";
    ifstream fstr(nameFile);
    if (fstr.fail())
    {
        cerr << "file not found!" <<endl;
        return 1;
    };
    ofstream resultFile("result.txt");
    if (resultFile.fail())
    {
        cerr << "file not found" <<endl;
        return 1;
    };

    double s,rr,v;
    int n;

    string l1,l2,l3,l4,s1,n1;

    getline(fstr,l1,';');   //S

    getline(fstr,s1);       //1000
    istringstream c1(s1);
    c1>>s;

    getline(fstr,l2,';');   //n
    getline(fstr,n1);       //8
    istringstream c2(n1);
    c2>>n;

    getline(fstr,l3,';');   //w
    getline(fstr,l4);       //r

    double *w= new double[n];
    double *r= new double[n];
    string aw,ar;

    for(int i=0; i<n;i++) //w[] e r[]
        {
            getline(fstr,aw,';');
            istringstream c(aw);
            getline(fstr,ar);
            istringstream c1(ar);

            c>>w[i];

            c1>>r[i];
        }

    v=V(w,r,s,n);

    rr=RoR(s,v);

    cout << "S = "<<fixed <<setprecision(2)<<s<<", n = "<<n
         << defaultfloat <<"\nw = [ "<<w[0]<<" "<<w[1]<<" "<<w[2]<<" "<<w[3]<<" "<<w[4]<<" "<<w[5]<<" "<<w[6]<<" "<<w[7]<<" ]"
         << "\nr = [ "<<r[0]<<" "<<r[1]<<" "<<r[2]<<" "<<r[3]<<" "<<r[4]<<" "<<r[5]<<" "<<r[6]<<" "<<r[7]<<" ]"
         << "\nRate of return of the portfolio: "<<setprecision(4)<<rr
         << "\nV: "<<fixed<<setprecision(2)<<v<<endl;

    resultFile <<"S = "<<fixed <<setprecision(2)<<s<<", n = "<<n
               <<defaultfloat << "\nw = [ "<<w[0]<<" "<<w[1]<<" "<<w[2]<<" "<<w[3]<<" "<<w[4]<<" "<<w[5]<<" "<<w[6]<<" "<<w[7]<<" ]"
               << "\nr = [ "<<r[0]<<" "<<r[1]<<" "<<r[2]<<" "<<r[3]<<" "<<r[4]<<" "<<r[5]<<" "<<r[6]<<" "<<r[7]<<" ]"
               << "\nRate of return of the portfolio: "<<setprecision(4)<<rr
               << "\nV: "<<fixed<<setprecision(2)<<v;
    fstr.close();
    resultFile.close();
    delete []w;
    delete []r;

    return 0;
}





