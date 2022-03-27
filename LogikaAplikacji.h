#ifndef LOGIKAAPLIKACJI_H
#define LOGIKAAPLIKACJI_H


class Komorka{
    public:
        Komorka(int,int,bool);
        ~Komorka();


    private:
        bool stan;
        int pozycjaX;
        int pozycjaY;
};

//class A
//{
//public:
//    int FA;
// //   void f1() { cout << "A f1\n"; }
//    A(int);

//};

//class B : public A {
//public:
//    int FB;
//    B(int _x){
//        FB=_x;
//        }


//    void f1() {
//    A::f1();
//    cout << "B f1\n";
//}
//};

// class C : public B {
// public:
//     int FC;

//     C(int _x){
//         FC=_x;
//    }

// void f1() {
// A::f1();
// B::f1();
// cout << "C f1\n";
// }

// int zwracajFC(){return FC;}

// };



#endif // LOGIKAAPLIKACJI_H
