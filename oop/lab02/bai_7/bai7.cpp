#include "bai7.h"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}


#include <iostream>
#include <cmath>
#include "bai7.h"

using namespace std;

void Polygon::Nhap() {
    cin>>n;
    vertices.resize(n);
    for (int i = 0; i < n; ++i) {
        cout << "Nhap toa do dinh " << i + 1 << " (x, y): ";
        cin >> vertices[i].x >> vertices[i].y;
    }
}

void Polygon::Xuat() {
    for (size_t i = 0; i < vertices.size(); ++i) {
        cout << "Dinh " << i + 1 << ": (" << vertices[i].x << ", " << vertices[i].y << ")\n";
    }
}
float Polygon::dientich(){
       float S=0;
       for(size_t i=0; i<vertices.size(); ++i){
            int j=(i+1)%vertices.size();
            S+= vertices[i].x*vertices[j].y - vertices[i].y*vertices[j].x;
       }
       return abs(S)/2.0;
}

