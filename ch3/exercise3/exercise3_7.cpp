//
// Created by wang on 11/17/19.
//
#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
// Eigen 几何模块
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;
int main()
{
    //initialize
    Quaterniond carrot1RotationQuat (0.35,0.2,0.3,0.1);
    Vector3d carrot1T(0.3,0.1,0.1);
    Quaterniond carrot2RotationQuat (-0.5,0.4,-0.1,0.2);
    Vector3d carrot2T(-0.1,0.5,0.3);
    Vector3d p_carrot1(0.5,0,0.2);
    //normalize
    carrot1RotationQuat.normalize();
    carrot2RotationQuat.normalize();
    //cout<<carrot1RotationQuat<<endl;//编译失败，Quaterniond类型没有重载运算符<<
    cout<<carrot1RotationQuat.coeffs()<<endl;//coeffs()输出的第四个参数为虚部
    // 使用欧式变化矩阵
    Isometry3d T_cw1 = Isometry3d::Identity();
    T_cw1.rotate(carrot1RotationQuat);
    T_cw1.pretranslate(carrot1T);
    Isometry3d T_cw2 = Isometry3d::Identity();
    T_cw2.rotate(carrot1RotationQuat);
    T_cw2.pretranslate(carrot1T);

    //calculate
    Vector3d p_c = T_cw1*p_carrot1;
    cout<<p_c.transpose()<<endl;
    //使用向量相加计算，结果一样
    //p_c = carrot1RotationQuat*p_carrot1 + carrot1T;
    //cout<<p_c.transpose()<<endl;
    Vector3d p_carrot2 = T_cw2.inverse() * p_c;
    cout<<p_carrot2.transpose()<<endl;
    return 0;
}