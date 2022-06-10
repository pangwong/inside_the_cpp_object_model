#include <iostream>
#include <functional>
#include <map>
#include <chrono>

#include "data_member_efficiency.hpp"

#define ITER_SIZE 10000000

void local_array(){
    float pA[3] = {1.725, 0.875, 0.478};
    float pB[3] = {0.315, 0.317, 0.838};
    enum fussy{x, y, z}; 
    for (int i=0; i<ITER_SIZE; i++){
        pB[x] = pA[x] - pB[z];
        pB[y] = pA[y] - pB[x];
        pB[x] = pA[z] - pB[y];
    } 
}

void c_struct(){
    CStruct pA = {1.725, 0.875, 0.478};
    CStruct pB = {0.315, 0.317, 0.838};
    for (int i=0; i<ITER_SIZE; i++){
        pB.x = pA.x - pB.z;
        pB.y = pA.y - pB.x;
        pB.x = pA.z - pB.y;
    } 
}

void class_inline_get_reference(){
    ClassInlineGetReference pA(1.725, 0.875, 0.478);
    ClassInlineGetReference pB(0.315, 0.317, 0.838);

    for (int i=0; i<ITER_SIZE; i++){
        pB.x() = pA.x() - pB.z();
        pB.y() = pA.y() - pB.x();
        pB.x() = pA.z() - pB.y();
    } 
} 

void class_inline_get_set(){
    ClassInlineGetSet pA(1.725, 0.875, 0.478);
    ClassInlineGetSet pB(0.315, 0.317, 0.838);

    for (int i=0; i<ITER_SIZE; i++){
        pB.x(pA.x() - pB.z());
        pB.y(pA.y() - pB.x());
        pB.x(pA.z() - pB.y());
    } 
} 

void class_single_inheritance(){
    Point3D pA(1.725, 0.875, 0.478);
    Point3D pB(0.315, 0.317, 0.838);
    for (int i=0; i<ITER_SIZE; i++){
        pB.x(pA.x() - pB.z());
        pB.y(pA.y() - pB.x());
        pB.x(pA.z() - pB.y());
    } 
}

void class_single_virtual_inheritance(){
    Point3DVL1 pA(1.725, 0.875, 0.478);
    Point3DVL1 pB(0.315, 0.317, 0.838);
    for (int i=0; i<ITER_SIZE; i++){
        pB.x(pA.x() - pB.z());
        pB.y(pA.y() - pB.x());
        pB.x(pA.z() - pB.y());
    } 
}

void class_double_virtual_inheritance(){
    Point3DVL2 pA(1.725, 0.875, 0.478);
    Point3DVL2 pB(0.315, 0.317, 0.838);
    for (int i=0; i<ITER_SIZE; i++){
        pB.x(pA.x() - pB.z());
        pB.y(pA.y() - pB.x());
        pB.x(pA.z() - pB.y());
    } 
}

void class_pointer_to_obj_member(){
    CStruct pA = {1.725, 0.875, 0.478};
    CStruct pB = {0.315, 0.317, 0.838};
    float *ax = &pA.x, *ay = &pA.y, *az = &pA.z;
    float *bx = &pB.x, *by = &pB.y, *bz = &pB.z;
    for (int i=0; i<ITER_SIZE; i++){
        *bx = *ax - *bz;
        *by = *ay - *bx;
        *bx = *az - *by;
    }
}

void class_pointer_to_class_member(){
    CStruct pA = {1.725, 0.875, 0.478};
    CStruct pB = {0.315, 0.317, 0.838};
    float CStruct::*ax = &CStruct::x, CStruct::*ay = &CStruct::y, CStruct::*az = &CStruct::z;
    float CStruct::*bx = &CStruct::x, CStruct::*by = &CStruct::y, CStruct::*bz = &CStruct::z;
    for (int i=0; i<ITER_SIZE; i++){
        pB.*bx = pA.*ax - pB.*bz;
        pB.*by = pA.*ay - pB.*bx;
        pB.*bx = pA.*az - pB.*by;
    }
}

void pointer_single_inheritance(){
    Point3D pA(1.725, 0.875, 0.478);
    Point3D pB(0.315, 0.317, 0.838);
    float Point3D::*ax = &Point3D::x_, Point3D::*ay = &Point3D::y_, Point3D::*az = &Point3D::z_;
    float Point3D::*bx = &Point3D::x_, Point3D::*by = &Point3D::y_, Point3D::*bz = &Point3D::z_;
    for (int i=0; i<ITER_SIZE; i++){
        pB.*bx = pA.*ax - pB.*bz;
        pB.*by = pA.*ay - pB.*bx;
        pB.*bx = pA.*az - pB.*by;
    }
}

void pointer_single_virtual_inheritance(){
    Point3DVL1 pA(1.725, 0.875, 0.478);
    Point3DVL1 pB(0.315, 0.317, 0.838);
    float Point1D::*ax = &Point1D::x_, Point1D::*bx = &Point1D::x_;
    float Point2DV::*ay = &Point2DV::y_, Point2DV::*by = &Point2DV::y_;
    float Point3DVL1::*az = &Point3DVL1::z_, Point3DVL1::*bz = &Point3DVL1::z_;
    for (int i=0; i<ITER_SIZE; i++){
        pB.*bx = pA.*ax - pB.*bz;
        pB.*by = pA.*ay - pB.*bx;
        pB.*bx = pA.*az - pB.*by;
    }
}

void pointer_double_virtual_inheritance(){
    Point3DVL2 pA(1.725, 0.875, 0.478);
    Point3DVL2 pB(0.315, 0.317, 0.838);
    float Point1D::*ax = &Point1D::x_, Point1D::*bx = &Point1D::x_;
    float Point2DV::*ay = &Point2DV::y_, Point2DV::*by = &Point2DV::y_;
    float Point3DVL2::*az = &Point3DVL2::z_, Point3DVL2::*bz = &Point3DVL2::z_;
    for (int i=0; i<ITER_SIZE; i++){
        pB.*bx = pA.*ax - pB.*bz;
        pB.*by = pA.*ay - pB.*bx;
        pB.*bx = pA.*az - pB.*by;
    }
}


enum TestType {
    NoInheritanceStoreLoad=1,
    InheritanceStoreLoad,
    MemberPointerNoInheritanceStoreLoad,
    MemberPointerInheritanceStoreLoad,
    ExcludeVirtualInheritance,
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
                     "    1: NoInheritanceStoreLoad\n"
                     "    2: InheritanceStoreLoad\n"
                     "    3: MemberPointerNoInheritanceStoreLoad\n"
                     "    4: MemberPointerInheritanceStoreLoad\n"
                     "    5: ExcludeVirtualInheritance\n"
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
        case NoInheritanceStoreLoad:
            func_map = {
                {"01.local_array                     ", local_array},
                {"02.c_struct                        ", c_struct},
                {"03.class_inline_get_reference      ", class_inline_get_reference},
                {"04.class_inline_get_set            ", class_inline_get_set}
            };
            break;
        case InheritanceStoreLoad:
            func_map = {
                {"05.class_single_inheritance        ", class_single_inheritance},
                {"06.class_single_virtual_inheritance", class_single_virtual_inheritance},
                {"07.class_double_virtual_inheritance", class_double_virtual_inheritance}
            };
            break;
        case MemberPointerNoInheritanceStoreLoad:
            func_map = {
                {"02.c_struct                        ", c_struct},
                {"08.class_pointer_to_obj_member     ", class_pointer_to_obj_member},
                {"09.class_pointer_to_class_member   ", class_pointer_to_class_member}
            };
            break;
        case MemberPointerInheritanceStoreLoad:
            func_map = {
                {"09.class_pointer_to_class_member   ", class_pointer_to_class_member},
                {"10.pointer_single_inheritance      ", pointer_single_inheritance},
                {"11.pointer_single_virtual_inheritance", pointer_single_virtual_inheritance},
                {"12.pointer_double_virtual_inheritance", pointer_double_virtual_inheritance}
            };
            break;
        case ExcludeVirtualInheritance:
            func_map = {
                {"01.local_array                     ", local_array},
                {"02.c_struct                        ", c_struct},
                {"03.class_inline_get_reference      ", class_inline_get_reference},
                {"04.class_inline_get_set            ", class_inline_get_set},
                {"05.class_single_inheritance        ", class_single_inheritance},
                {"08.class_pointer_to_obj_member     ", class_pointer_to_obj_member},
                {"09.class_pointer_to_class_member   ", class_pointer_to_class_member},
                {"10.pointer_single_inheritance      ", pointer_single_inheritance}
            };
            break; 
        case ALL:
        default:
            func_map = {
                {"01.local_array                     ", local_array},
                {"02.c_struct                        ", c_struct},
                {"03.class_inline_get_reference      ", class_inline_get_reference},
                {"04.class_inline_get_set            ", class_inline_get_set},
                {"05.class_single_inheritance        ", class_single_inheritance},
                {"06.class_single_virtual_inheritance", class_single_virtual_inheritance},
                {"07.class_double_virtual_inheritance", class_double_virtual_inheritance},
                {"08.class_pointer_to_obj_member     ", class_pointer_to_obj_member},
                {"09.class_pointer_to_class_member   ", class_pointer_to_class_member},
                {"10.pointer_single_inheritance      ", pointer_single_inheritance},
                {"11.pointer_single_virtual_inheritance", pointer_single_virtual_inheritance},
                {"12.pointer_double_virtual_inheritance", pointer_double_virtual_inheritance}
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
