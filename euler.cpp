#include <iostream>
#include <cmath>

using namespace std;


double euler(float dt,float v,float y, float t1,float tf);


int main(){
   
   
    euler(0.01,0.0,1.0,0.0,10.0);
    return 0;
}

double euler(float dt,float v,float y,float t1, float tf){
    float k=10.0;
    float m=2.0;
    float b= 2.0;
   

    for(float t1; t1<tf; dt){
        float vn = v;
        float yn = y;
        
       
        y = y + dt*vn;
        v = v - (dt * (k/m) * yn);
        cout<< t1 << " " << y << "  " << v << endl;
        t1=t1+dt;
    }
    return 0;
}
