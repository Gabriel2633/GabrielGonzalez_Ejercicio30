#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void ultima(string filename);
    
int main()
{
    
ultima("datos.dat");
return 0;
    
}

void ultima(string filename)
{
    ofstream outfile;
    outfile.open(filename);
    
    int m = 100;//las x
    double c=1.0;
    double dx=0.01;
    double beta=1.0;
    double u[m+1];
    double un[m+1];
    double dt = 0.01;
    double T_final=2.0;
    int n = int(T_final/dt);//las t
    
    for(int i=0;i<m; i++) //condicion inicial preguntar por lo de dt
    {
        u[i]=sin(4.0*M_PI*i*dx)/20.0;
    }
    
        for(int j=0;j<n+1; j++)
    {
            for(int i=0;i<m-1; i++)
            {
                //aplicando del libro 19.12
                double f=u[i+1]*u[i+1];
                double p=u[i-1]*u[i-1];
                double pres=u[i]*u[i];
                un[i]=u[i]-((beta/4.0)*(f-p))+((beta*beta/8.0)*((u[i+1]+u[i])*(f-pres)-(u[i]+u[i-1])*(pres-p)));
                
            }
            
            //actualizar
            
            for(int i=0;i<m;i++)
            {
                outfile << u[i] << " ";
            }
                outfile << "\n";

            for(int i=1;i<m-1;i++)
            {
                u[i]=un[i];
            }
            
            
    }
    outfile.close();
}

    



