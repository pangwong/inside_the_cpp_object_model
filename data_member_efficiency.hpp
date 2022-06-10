#ifndef _data_member_efficiency_hpp_
#define _data_member_efficiency_hpp_

struct CStruct{
    float x;
    float y;
    float z;
};

class ClassInlineGetReference{
public:
    ClassInlineGetReference(float _x, float _y, float _z) : x_(_x), y_(_y), z_(_z){}
    float& x(){return x_;}
    float& y(){return y_;}
    float& z(){return z_;}
private:
    float x_=0.0;
    float y_=0.0;
    float z_=0.0;
};

class ClassInlineGetSet{
public:
    ClassInlineGetSet(float _x, float _y, float _z) : x_(_x), y_(_y), z_(_z){}
    float x(){return x_;}
    float y(){return y_;}
    float z(){return z_;}
    void x(float _x){x_ = _x;}
    void y(float _y){y_ = _y;}
    void z(float _z){z_ = _z;}
private:
    float x_=0.0;
    float y_=0.0;
    float z_=0.0;
};

// single inheritance
class Point1D {
public:
    Point1D(float _x=0.0) : x_(_x){}
    float x(){return x_;}
    void x(float _x){x_ = _x;}
    float x_ = 0.0;
};
class Point2D : public Point1D{
public:
    Point2D(float _x, float _y) : Point1D(_x), y_(_y){}
    void y(float _y){y_ = _y;}
    float y(){return y_;}
    float y_ = 0.0;
};
class Point3D : public Point2D{
public:
    Point3D(float _x, float _y, float _z) : Point2D(_x, _y), z_(_z){}
    float z(){return z_;}
    void z(float _z){z_ = _z;}
    float z_ = 0.0;
};

// single layer virtual inheritance
class Point2DV : public virtual Point1D{
public:
    Point2DV(float _x, float _y) : Point1D(_x), y_(_y){}
    void y(float _y){x_ = _y;}
    float y(){return y_;}
    float y_ = 0.0;
};
class Point3DVL1 : public Point2DV{
public:
    Point3DVL1(float _x, float _y, float _z) : Point2DV(_x, _y), z_(_z){}
    float z(){return z_;}
    void z(float _z){x_ = _z;}
    float z_ = 0.0;
};


// double layer virtual inheritance
class Point3DVL2 : public virtual Point2DV{
public:
    Point3DVL2(float _x, float _y, float _z) : Point2DV(_x, _y), z_(_z){}
    float z(){return z_;}
    void z(float _z){x_ = _z;}
    float z_ = 0.0;
};

#endif
