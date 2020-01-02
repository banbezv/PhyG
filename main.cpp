#include <iostream>
//#include "Engine.hpp"
#include "Body.hpp"

using namespace std;

int main(){
    cout<<"main"<<endl;
    Body body(Vector(1,2),Vector(3,4),5);
    FILE *fp;
    fp=fopen("1.txt","wb");
    body.save(fp);
    fclose(fp);
    Body body2;
    fp=fopen("1.txt","rb");
    body2.load(fp);
    fclose(fp);
    cout<<body2.position.x.x
        <<body2.position.y.x
        <<body2.size.x.x
        <<body2.size.y.x
        <<body2.rotation.x
        <<endl;
    return 0;
}
