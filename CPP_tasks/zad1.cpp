#include <iostream>

using namespace std;

class punkt {
private:
    double _x,_y,_z;
public:
    punkt(){
        cout << "Podaj x:" << endl;
        cin >> _x;
        cout << "Podaj y:" << endl;
        cin >> _y;
        cout << "Podaj z:" << endl;
        cin >> _z;
    }
    punkt(double x, double y, double z) {
        _x = x;
        _y = y;
        _z = z;
    }
    double& x() {return _x;}
    double x() const {return _x;}
    double& y(){return _y;}
    double y() const {return _y;}
    double& z(){return _z;}
    double z() const {return _z;}
};

class prostokat {
private:
    punkt pkt;
    double _a, _b;
public:
    prostokat(): pkt() {
        cout << "Podaj szerokosc:" << endl;
        cin >> _a;
        cout << "Podaj dlugosc:" << endl;
        cin >> _b;
    }
    prostokat(double x, double y, double z, double a, double b): pkt(x,y,z), _a(a), _b(b) {}

    prostokat(punkt &p, double a, double b): pkt(p), _a(a), _b(b) {}

    double pole() const {
        return _a * _b;
    }
    double& x() {return pkt.x();}
    double x() const {return pkt.x();}
    double& y() {return pkt.y();}
    double y() const {return pkt.y();}
    double& z() {return pkt.z();}
    double z() const {return pkt.z();}
    double& a() {return _a;}
    double a() const {return _a;}
    double& b() {return _b;}
    double b() const {return _b;}
};

class graniastoslup {
private:
    prostokat pr;
    double _h;
public:
    graniastoslup(): pr() {
        cout << "Podaj wysokosc:" << endl;
        cin >> _h;
    }
    graniastoslup(double x, double y, double z, double a, double b, double h): pr(x,y,z,a,b), _h(h){}
    graniastoslup(punkt &p, double a, double b, double h): pr(p,a,b), _h(h){}
    graniastoslup(const prostokat &p, double h): pr(p), _h(h){}

    double objetosc() const {
        return pr.pole() * _h;
    }
    double& x() {return pr.x();}
    double x() const {return pr.x();}
    double& y() {return pr.y();}
    double y() const {return pr.y();}
    double& z() {return pr.z();}
    double z() const {return pr.z();}
    double& a() {return pr.a();}
    double a() const {return pr.a();}
    double& b() {return pr.b();}
    double b() const {return pr.b();}
    double& h() {return _h;}
    double h() const {return _h;}
};

int main() {
    punkt p1, p2(1,2,3);
    const punkt p3(1.1,2.2,3.3);

    cout << p1.x() << endl;
    cout << p2.x() << endl;
    cout << p3.x() << endl;

    cout << p3.x() << '\t' << p3.y() <<'\t' << p3.z() << endl;

    p1.x() = 1;
    p1.y() = 10;
    p1.z() = 100;

    cout << p1.x() << '\t' << p1.y() <<'\t' << p1.z() << endl;

    prostokat pr1, pr2(1,2,3,10.5,20.5);
    const prostokat pr3(p2,5,5);

    pr1.x() = 2;
    pr1.y() = 20;
    pr1.z() = 200;
    pr1.a() = 10;
    pr1.b() = 10;

    cout << pr1.x() << '\t' << pr1.y() <<'\t' << pr1.z() << '\t'
        << pr1.a() << '\t' << pr1.b() << endl;

    cout << pr1.pole() << endl;

    graniastoslup g1, g2(1,2,3,10.5,20.5,30.5),g3(p2,100,200,300);
    const graniastoslup g4(pr3,5);

    cout << g4.x() << '\t' << g4.y() << '\t' << g4.z() << '\n'
        << g4.a() << '\t' << g4.b() << '\t' << g4.h() << '\n'
        << g4.objetosc() << endl;

    g1.a() = 10;
    g1.b() = 10;
    g1.h() = 10;

    cout << g1.x() << '\t' << g1.y() << '\t' << g1.z() << '\n'
        << g1.a() << '\t' << g1.b() << '\t' << g1.h() << '\n'
        << g1.objetosc() << endl;

    return 0;
}

