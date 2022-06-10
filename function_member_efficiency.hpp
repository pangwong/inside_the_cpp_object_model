#ifndef _object_member_efficiency_hpp_
#define _object_member_efficiency_hpp_

class Point3DNI{
public:
    friend void cross_product_nm(const Point3DNI& lhs, const Point3DNI& rhs);
    Point3DNI(float _x=0.0, float _y=0.0, float _z=0.0) : x(_x), y(_y), z(_z){}
    void cross_product(const Point3DNI& rhs){
        Point3DNI pC;
        pC.x = y * rhs.z - z * rhs.y;
        pC.y = z * rhs.x - x * rhs.z;
        pC.z = x * rhs.y - y * rhs.x;
    }
    static void cross_product(const Point3DNI& lhs, const Point3DNI& rhs){
        Point3DNI pC;
        pC.x = lhs.y * rhs.z - lhs.z * rhs.y;
        pC.y = lhs.z * rhs.x - lhs.x * rhs.z;
        pC.z = lhs.x * rhs.y - lhs.y * rhs.x;
    }
    virtual void cross_product_v(const Point3DNI& rhs){
        Point3DNI pC;
        pC.x = y * rhs.z - z * rhs.y;
        pC.y = z * rhs.x - x * rhs.z;
        pC.z = x * rhs.y - y * rhs.x;
    }

private:
    float x=0.0;
    float y=0.0;
    float z=0.0;
};


// single inheritance
// Point1DSH -> Point2DSH -> Point3DSH
class Point3DSH;
class Point1DSH {
public:
    Point1DSH(float _x=0.0) : x_(_x){}
    virtual void cross_product(const Point3DSH&);
    
    float x_ = 0.0;
};
class Point2DSH : public Point1DSH{
public:
    Point2DSH(float _x=0.0, float _y=0.0) : Point1DSH(_x), y_(_y){}
    virtual void cross_product(const Point3DSH&) override;
    
    float y_ = 0.0;
};
class Point3DSH : public Point2DSH{
public:
    Point3DSH(float _x=0.0, float _y=0.0, float _z=0.0) : Point2DSH(_x, _y), z_(_z){}
    virtual void cross_product(const Point3DSH&) override;
    
    float z_ = 0.0;
};


// multiple inheritance
// Point1DMH1 ----|
//             |--> Point3DMH
// Point1DMH2 ---|
class Point3DMH;
class Point1DMH1 {
public:
    Point1DMH1(float _x=0.0) : x_(_x){}
    virtual void cross_product(const Point3DMH&);
    
    float x_ = 0.0;
};
class Point1DMH2 {
public:
    Point1DMH2(float _y=0.0) : y_(_y){}
    virtual void cross_product(const Point3DMH&);
    
    float y_ = 0.0;
};
class Point3DMH : public Point1DMH1, public Point1DMH2 {
public:
    Point3DMH(float _x=0.0, float _y=0.0, float _z=0.0) : Point1DMH1(_x), Point1DMH2(_y), z_(_z){}
    virtual void cross_product(const Point3DMH&) override;
    
    float z_ = 0.0;
};

// virtual inheritance
// Point2DVH -> Point3DVH
class Point3DVH;
class Point2DVH{
public:
    Point2DVH(float _x=0.0, float _y=0.0) : x_(_x), y_(_y){}
    virtual void cross_product(const Point3DVH&);
    
    float x_ = 0.0;
    float y_ = 0.0;
};
class Point3DVH : public virtual Point2DVH{
public:
    Point3DVH(float _x=0.0, float _y=0.0, float _z=0.0) : Point2DVH(_x, _y), z_(_z){}
    virtual void cross_product(const Point3DVH&) override;
    
    float z_ = 0.0;
};

#endif
