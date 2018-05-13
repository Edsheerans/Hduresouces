#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Shape
{
public:
    virtual double area() const=0;
};
class Circle : public Shape
{
private:
    double r;
public:
    Circle(){};
    Circle(double &r1){r=r1;};
    virtual double area() const {return 3.1416*r*r;};
};
class Rectangle : public Shape
{
private:
    double w,h;
public:
    Rectangle(){};
    Rectangle(double &w1,double &h1){w=w1;h=h1;};
    virtual double area() const {return w*h;};
};
class Triangle : public Shape
{
private:
    double a,b,c,p;
public:
    Triangle(){};
    Triangle(double &a1,double &b1,double &c1){a=a1;b=b1;c=c1;p=(a1+b1+c1)/2;};
    virtual double area() const {return sqrt(p*(p-a)*(p-b)*(p-c));};
};
int main()
{
    int i=0,j=0,k=0;
    double a,b,c;
    char str[10];
    Circle c1[10];
    Rectangle r[10];
    Triangle t[10];
    double sumarea=0;
    while(cin>>str)
    {
        if(strcmp(str,"circle")==0)
        {
            cin>>a;
            c1[i]=Circle(a);
            i++;
        }
        else if(strcmp(str,"rectangle")==0)
        {
            cin>>a>>b;
            r[j]=Rectangle(a,b);
            j++;
        }
        else if(strcmp(str,"triangle")==0)
        {
            cin>>a>>b>>c;
            t[k]=Triangle(a,b,c);
            k++;
        }
    }
    while(i>0)
    {
        sumarea=sumarea+c1[i-1].area();
        i--;
    }
    while(j>0)
    {
        sumarea=sumarea+r[j-1].area();
        j--;
    }
    while(k>0)
    {
        sumarea=sumarea+t[k-1].area();
        k--;
    }
    printf("%.4f\n",sumarea);
    return 0;
}
