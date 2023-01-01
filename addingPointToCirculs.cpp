#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;
// 1...
struct point2D {
    float x, y;
};
// 2...
istream& operator>>(istream& in, point2D& point){
    cout<<"input center:"<<endl;
    cout<<"please input x and y coordinate: ";
     in>>point.x >> point.y;
    return in;
}
// 3...
ostream& operator<<(ostream& out, point2D& point){
    out<<"("<<point.x<<", "<<point.y<<")";
    return out;
}
// 4...
point2D operator+(point2D& point1, point2D& point2){
    point2D sum;
    sum.x = point1.x + point2.x;
    sum.y = point1.y + point2.y;
    return sum;
}
// 5...
struct circle {
    point2D center;
    float radius;
};
// 6...
istream& operator>>(istream& in, circle& c){
    in>> c.center;
    cout<<"please input radius: ";
    in>> c.radius;
    if (c.radius < 0){
    cerr << "error in operator>>: negative radius, sign changed"<<endl;
    c.radius = c.radius * (-1);
    }
    return in;
}
// 1-
inline float circumference(circle& c){
    return  2 * M_PI * c.radius;  ;
}
// 7...
ostream& operator<<(ostream& out, circle& c){
    out<<"circle: center="<<c.center<<", radius="<<c.radius<<", circumference="<<circumference(c)<<endl;;
    return out;
}
// 8...
circle operator+(circle& c, point2D& p){
   circle newCircle  ;
    newCircle.center = c.center + p ;
    newCircle.radius = c.radius;
    return newCircle;
}
// 9...
circle& operator+(circle& c , float& num){
    c.radius = c.radius + num;
    return c;
}
// 10...
bool operator==(point2D& point1, point2D& point2){
    if( (point1.x == point2.x) && (point1.y == point2.y))
    return true;
    else
     return false;
}
// 11...
bool operator!=(point2D& point1, point2D& point2){
    if( (point1.x != point2.x) && (point1.y != point2.y))
    return true;
    else
    return false;
}
// 12...
bool operator==(circle& c1, circle& c2){
    if (c1.center == c2.center){
        if (c1.radius == c2.radius)
    return true;
    } 
    else
    return false;
}
// 13...
bool operator!=(circle& c1, circle& c2){
    if (c1.center != c2.center){
        if (c1.radius != c2.radius)
    return true;
    }
    else 
    return false;
}
// 3- 
circle operator/(circle& c, float n){
    circle res;
    res.center = c.center;
    if (n < 0){
        cerr << "error in operator/: divisor with non positive value, division with sign changed value instead or radius set to 0"<<endl;
        n = n * (-1);
    }
    if ( n == 0){
        cerr << "error in operator/: divisor with non positive value, division with sign changed value instead or radius set to 0"<<endl;
        res.radius = 0;
    }
    res.radius = c.radius / n;
   return res; 
}
// 4-
bool operator>(circle& c1, circle& c2){
    if ( circumference(c1) > circumference(c2))
     return true;
    else return false;
}
// 5-
bool operator>=(circle& c1, circle& c2){
    if ( circumference(c1) >= circumference(c2))
     return true;
    else return false;
}
// 14...
int main(void){
    point2D p;
    p.x = 1.0;
    p.y = 1.0;
    circle c[12];
    c[0].center.x = 0.0;
    c[0].center.y = 0.0;
    c[0].radius = 1.0;
    cin>>c[1];
    cin>>c[2];
    for (int i=0; i<3; i++)
    cout<<"c["<<i<<"]: "<<c[i];
    c[3] = c[0] + p;
    c[4] = c[1] + p;
    c[5] = c[2] + p;
    cout<<"by adding point (1,1) to c[0] to c[2] assign the results to c[3] to c[5]"<<endl;
    for(int i=0; i<6; i++)
     cout<<"c["<<i<<"]: "<<c[i];
    float n;
    cout<<"input value to get added to the radius of c[3] to c[5]: ";
    cin>>n;
    for(int i=3; i<=5; i++){
        c[i] + n;
        cout<<"c[" << i<<"]: "<<c[i];
    }
    cout<<"compare circles:"<<endl;
    if (c[0] == c[1])
    cout<<"c[0] and c[1] are equal"<<endl;
    else
    cout<<"c[0] and c[1] are not equal"<<endl;
    if(c[1] != c[2])
    cout<<"c[1] and c[2] are unequal"<<endl;
    else
    cout<<"c[1] and c[2] are not unequal"<<endl;
    //.. add
    float a;
    cout<<"input value to divide by the radius of each circle: ";
    cin>>a;
    for (int i=0; i<6; i++)
    c[i + 6] = c[i] / a;
    for (int i=0; i<12; i++)
    cout<<"c["<<i<<"]: "<<c[i];
    for(int i=0; i<12; i++){
        cout<<"c["<<i<<"] < c[0] is "<<boolalpha<<(c[i] > c[0])<<endl;
        cout<<"c["<<i<<"] <= c[0] is "<<boolalpha<<(c[i] >= c[0])<<endl;
    }

    return 0;
}
