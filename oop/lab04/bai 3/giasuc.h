
#ifndef GIASUC_H_INCLUDED
#define GIASUC_H_INCLUDED
#include<bits/stdc++.h>
#include <string>
#include <cstdlib>
using namespace std;
class giasuc{
public:
    virtual string speak() {};
    virtual int breed() {};
    virtual int milk() {};
};


#endif // GIASUC_H_INCLUDED

#ifndef COW_H_INCLUDED
#define COW_H_INCLUDED

class COW : public giasuc{
private:
       int num;
public:
     COW() {
        num=1;
     }
     string speak() override{
        return "um_bo ";
    }
    int breed() override{
        int sl=0;
        for(int i=1; i<=num; i++) sl+= abs(rand())%6;
        this->num+= sl;
        return sl;
    }
    int milk() override{
        int lit=0;
        for(int i=1; i<=num; i++) lit+= abs(rand())%21;
        return lit;
    }
};


#endif // COW_H_INCLUDED

#ifndef SHEEP_H_INCLUDED
#define SHEEP_H_INCLUDED

class SHEEP : public giasuc{
private:
       int num;
public:


     SHEEP() {
        num=1;
     }
     string speak() override{
        return "be be ";
    }
    int breed() override{
        int sl=0;
        for(int i=1; i<=num; i++) sl+= abs(rand())%6;
        this->num+= sl;
        return sl;
    }
    int milk() override{
        int lit=0;
        for(int i=1; i<=num; i++) lit+= abs(rand())%6;
        return lit;
    }
};


#endif // SHEEP_H_INCLUDED


#ifndef DEEL_H_INCLUDED
#define DEEL_H_INCLUDED

class DEEL : public giasuc{
private:
       int num;
public:


     DEEL() {
        num=1;
     }
     string speak() override{
        return "e e e e e ";
    }
    int breed() override{
        int sl=0;
        for(int i=1; i<=num; i++) sl+= abs(rand())%6;
        this->num+= sl;
        return sl;
    }
    int milk() override{
        int lit=0;
        for(int i=1; i<=num; i++) lit+= abs(rand())%11;
        return lit;
    }
};


#endif // DEEL_H_INCLUDED
