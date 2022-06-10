#include <iostream>
#include <functional>
#include <map>
#include <chrono>

#include "function_member_efficiency.hpp"

#define ITER_SIZE 10000000

void Point1DSH::cross_product(const Point3DSH &) {std::cout << "p1dsh" << std::endl;}
void Point2DSH::cross_product(const Point3DSH &) {std::cout << "p2dsh" << std::endl;}
void Point1DMH1::cross_product(const Point3DMH &) {std::cout << "p1dmh1" << std::endl;}
void Point1DMH2::cross_product(const Point3DMH &) {std::cout << "p1dmh2" << std::endl;}
void Point2DVH::cross_product(const Point3DVH &) {std::cout << "p2dvh" << std::endl;}

void cross_product_nm(const Point3DNI& lhs, const Point3DNI& rhs){
    Point3DNI p;
    p.x = lhs.y * rhs.z - lhs.z * rhs.y;
    p.y = lhs.z * rhs.x - lhs.x * rhs.z;
    p.z = lhs.x * rhs.y - lhs.y * rhs.x;
}

void Point3DSH::cross_product(const Point3DSH &rhs) {
    Point3DSH p;
    p.x_ = y_ * rhs.z_ - z_ * rhs.y_;
    p.y_ = z_ * rhs.x_ - x_ * rhs.z_;
    p.z_ = x_ * rhs.y_ - y_ * rhs.x_;
}

void Point3DMH::cross_product(const Point3DMH &rhs) {
    Point3DMH p;
    p.x_ = y_ * rhs.z_ - z_ * rhs.y_;
    p.y_ = z_ * rhs.x_ - x_ * rhs.z_;
    p.z_ = x_ * rhs.y_ - y_ * rhs.x_;
}

void Point3DVH::cross_product(const Point3DVH &rhs) {
    Point3DVH p;
    p.x_ = y_ * rhs.z_ - z_ * rhs.y_;
    p.y_ = z_ * rhs.x_ - x_ * rhs.z_;
    p.z_ = x_ * rhs.y_ - y_ * rhs.x_;
}

void ni_nonmember_function(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    for (int i=0; i<ITER_SIZE; i++){
        cross_product_nm(p1, p2);
    }
}

void ni_nonstatic_member_function(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    for (int i=0; i<ITER_SIZE; i++){
        p1.cross_product(p2); 
    }
}

void ni_static_member_function(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    for (int i=0; i<ITER_SIZE; i++){
        Point3DNI::cross_product(p1, p2); 
    }
}

void ni_virtual_member_function(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    for (int i=0; i<ITER_SIZE; i++){
        p1.cross_product(p2); 
    }
}

void si_virtual_member_function_primary_base(){
    Point3DSH p1(1.725, 0.875, 0.478);
    Point3DSH p2(0.315, 0.317, 0.838);
    Point1DSH& p1dsh = p1;
    for (int i=0; i<ITER_SIZE; i++){
        p1dsh.cross_product(p2); // virtual call via reference
    }
}

void si_virtual_member_function_secondary_base(){
    Point3DSH p1(1.725, 0.875, 0.478);
    Point3DSH p2(0.315, 0.317, 0.838);
    Point2DSH& p2dsh = p1;
    for (int i=0; i<ITER_SIZE; i++){
        p2dsh.cross_product(p2); // virtual call via reference
    }
}

void mi_virtual_member_function_primary_base(){
    Point3DMH p1(1.725, 0.875, 0.478);
    Point3DMH p2(0.315, 0.317, 0.838);
    Point1DMH1& p1dmh = p1;
    for (int i=0; i<ITER_SIZE; i++){
        p1dmh.cross_product(p2); // virtual call via reference
    }
}
void mi_virtual_member_function_secondary_base(){
    Point3DMH p1(1.725, 0.875, 0.478);
    Point3DMH p2(0.315, 0.317, 0.838);
    Point1DMH2& p1dmh = p1;
    for (int i=0; i<ITER_SIZE; i++){
        p1dmh.cross_product(p2); // virtual call via reference
    }
}

void vi_virtual_member_function(){
    Point3DVH p1(1.725, 0.875, 0.478);
    Point3DVH p2(0.315, 0.317, 0.838);
    Point2DVH& p2dvh = p1;
    for (int i=0; i<ITER_SIZE; i++){
        p2dvh.cross_product(p2); // virtual call via reference
    }
}

void ni_nonmember_function_pointer(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    void (*fptr)(const Point3DNI& lhs, const Point3DNI& rhs) = cross_product_nm;
    for (int i=0; i<ITER_SIZE; i++){
        (*fptr)(p1, p2);
    }
}

void ni_nonstatic_member_function_pointer(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    void (Point3DNI::*fptr)(const Point3DNI&) = &Point3DNI::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (p1.*fptr)(p2); 
    }
}

void ni_static_member_function_pointer(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    void (*fptr)(const Point3DNI& lhs, const Point3DNI& rhs) = Point3DNI::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (*fptr)(p1, p2); 
    }
}

void ni_virtual_member_function_pointer(){
    Point3DNI p1(1.725, 0.875, 0.478);
    Point3DNI p2(0.315, 0.317, 0.838);
    void (Point3DNI::*fptr)(const Point3DNI&) = &Point3DNI::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (p1.*fptr)(p2); 
    }
}

void si_virtual_member_function_pointer_primary_base(){
    Point3DSH p1(1.725, 0.875, 0.478);
    Point3DSH p2(0.315, 0.317, 0.838);
    Point1DSH& p1dsh = p1;
    void (Point1DSH::*fptr)(const Point3DSH&) = &Point1DSH::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (p1dsh.*fptr)(p2); // virtual call via function pointer 
    }
}

void si_virtual_member_function_pointer_secondary_base(){
    Point3DSH p1(1.725, 0.875, 0.478);
    Point3DSH p2(0.315, 0.317, 0.838);
    Point2DSH& p2dsh = p1;
    void (Point2DSH::*fptr)(const Point3DSH&) = &Point2DSH::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (p2dsh.*fptr)(p2); // virtual call via function pointer
    }
}

void mi_virtual_member_function_pointer_primary_base(){
    Point3DMH p1(1.725, 0.875, 0.478);
    Point3DMH p2(0.315, 0.317, 0.838);
    Point1DMH1& p1dmh = p1;
    void (Point1DMH1::*fptr)(const Point3DMH&) = &Point1DMH1::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (p1dmh.*fptr)(p2); // virtual call via function pointer
    }
}
void mi_virtual_member_function_pointer_secondary_base(){
    Point3DMH p1(1.725, 0.875, 0.478);
    Point3DMH p2(0.315, 0.317, 0.838);
    Point1DMH2& p1dmh = p1;
    void (Point1DMH2::*fptr)(const Point3DMH&) = &Point1DMH2::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (p1dmh.*fptr)(p2); // virtual call via function pointer
    }
}

void vi_virtual_member_function_pointer(){
    Point3DVH p1(1.725, 0.875, 0.478);
    Point3DVH p2(0.315, 0.317, 0.838);
    Point2DVH& p2dvh = p1;
    void (Point2DVH::*fptr)(const Point3DVH&) = &Point2DVH::cross_product;
    for (int i=0; i<ITER_SIZE; i++){
        (p2dvh.*fptr)(p2); // virtual call via function pointer
    }
}

enum TestType {
    NonVirtualFunction=1,
    VirtualFunction,
    NonVirtualFunctionPointer,
    VirtualFunctionPointer,
    ExcludeVirtualFunction,
    ALL
};

int main(int argc, char** argv){
    auto test_type = static_cast<TestType>(1);
    if (argc >= 2){
        test_type = static_cast<TestType>(std::stoi(argv[1]));
    }
    else{
        std::cout << "{EXEC} TestType [loop]\n"
                     "Please provide a Test Type: \n"
                     "    1: NonVirtualFunction\n"
                     "    2: VirtualFunction\n"
                     "    3: NonVirtualFunctionPointer\n"
                     "    4: VirtualFunctionPointer\n"
                     "    5: ExcludeVirtualFunction\n"
                     "    6: ALL\n";
        exit(-1);
    }

    int loop = 1;
    if (argc >= 3){
        loop = std::stoi(argv[2]);
    }
    std::cout << "run 10000000 * loop times where loop=" << loop << std::endl;
    
    std::map<std::string, std::function<void()>> func_map;
    switch (test_type){
        case NonVirtualFunction:
            func_map = {
                {"01.ni_nonmember_function                    ", ni_nonmember_function},
                {"02.ni_nonstatic_member_function             ", ni_nonstatic_member_function},
                {"03.ni_static_member_function                ", ni_static_member_function},
                {"04.ni_virtual_member_function               ", ni_virtual_member_function},
            };
            break;
        case VirtualFunction:
            func_map = {
                {"05.si_virtual_member_function_primary_base  ", si_virtual_member_function_primary_base},
                {"06.si_virtual_member_function_secondary_base", si_virtual_member_function_secondary_base},
                {"07.mi_virtual_member_function_primary_base  ", mi_virtual_member_function_primary_base},
                {"08.mi_virtual_member_function_secondary_base", mi_virtual_member_function_secondary_base},
                {"09.vi_virtual_member_function               ", vi_virtual_member_function},
            };
            break;
        case NonVirtualFunctionPointer:
            func_map = {
                {"10.ni_nonmember_function_pointer                    ", ni_nonmember_function_pointer},
                {"11.ni_nonstatic_member_function_pointer             ", ni_nonstatic_member_function_pointer},
                {"12.ni_static_member_function_pointer                ", ni_static_member_function_pointer},
                {"13.ni_virtual_member_function_pointer               ", ni_virtual_member_function_pointer},
            };
            break;
        case VirtualFunctionPointer:
            func_map = {
                {"14.si_virtual_member_function_pointer_primary_base  ", si_virtual_member_function_pointer_primary_base},
                {"15.si_virtual_member_function_pointer_secondary_base", si_virtual_member_function_pointer_secondary_base},
                {"16.mi_virtual_member_function_pointer_primary_base  ", mi_virtual_member_function_pointer_primary_base},
                {"17.mi_virtual_member_function_pointer_secondary_base", mi_virtual_member_function_pointer_secondary_base},
                {"18.vi_virtual_member_function_pointer               ", vi_virtual_member_function_pointer},
            };
            break;
        case ExcludeVirtualFunction:
            func_map = {
                {"01.ni_nonmember_function                            ", ni_nonmember_function},
                {"02.ni_nonstatic_member_function                     ", ni_nonstatic_member_function},
                {"03.ni_static_member_function                        ", ni_static_member_function},
                {"04.ni_virtual_member_function                       ", ni_virtual_member_function},
                {"10.ni_nonmember_function_pointer                    ", ni_nonmember_function_pointer},
                {"11.ni_nonstatic_member_function_pointer             ", ni_nonstatic_member_function_pointer},
                {"12.ni_static_member_function_pointer                ", ni_static_member_function_pointer},
                {"13.ni_virtual_member_function_pointer               ", ni_virtual_member_function_pointer},
            };
            break; 
        case ALL:
        default:
            func_map = {
                {"01.ni_nonmember_function                            ", ni_nonmember_function},
                {"02.ni_nonstatic_member_function                     ", ni_nonstatic_member_function},
                {"03.ni_static_member_function                        ", ni_static_member_function},
                {"04.ni_virtual_member_function                       ", ni_virtual_member_function},
                {"05.si_virtual_member_function_primary_base          ", si_virtual_member_function_primary_base},
                {"06.si_virtual_member_function_secondary_base        ", si_virtual_member_function_secondary_base},
                {"07.mi_virtual_member_function_primary_base          ", mi_virtual_member_function_primary_base},
                {"08.mi_virtual_member_function_secondary_base        ", mi_virtual_member_function_secondary_base},
                {"09.vi_virtual_member_function                       ", vi_virtual_member_function},
                {"10.ni_nonmember_function_pointer                    ", ni_nonmember_function_pointer},
                {"11.ni_nonstatic_member_function_pointer             ", ni_nonstatic_member_function_pointer},
                {"12.ni_static_member_function_pointer                ", ni_static_member_function_pointer},
                {"13.ni_virtual_member_function_pointer               ", ni_virtual_member_function_pointer},
                {"14.si_virtual_member_function_pointer_primary_base  ", si_virtual_member_function_pointer_primary_base},
                {"15.si_virtual_member_function_pointer_secondary_base", si_virtual_member_function_pointer_secondary_base},
                {"16.mi_virtual_member_function_pointer_primary_base  ", mi_virtual_member_function_pointer_primary_base},
                {"17.mi_virtual_member_function_pointer_secondary_base", mi_virtual_member_function_pointer_secondary_base},
                {"18.vi_virtual_member_function_pointer               ", vi_virtual_member_function_pointer},
            };
            break; 
    }
    for (auto iter=func_map.begin(); iter!=func_map.end(); iter++){
        auto r_start = std::chrono::high_resolution_clock::now();        
        for (int i=0; i<loop; i++){
            (iter->second)();
        }
        auto r_end = std::chrono::high_resolution_clock::now();        
        std::chrono::duration<double, std::micro> r_duration = r_end - r_start;
        std::cout << iter->first << "\t run time: \t" << r_duration.count() << "\tmicro second" << std::endl;
    }
}
