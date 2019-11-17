#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
    /*
     * 习题5
     */
    Matrix<double, 5, 8> m = Matrix<double, 5, 8>::Random();
    cout << m << endl;
    //block() 取出矩阵的指定区域，0行0列开始，向右取3行，向下取3列
    Matrix3d b = m.block(0, 0, 3, 3);
    cout << b << endl;
    /*
     * 习题7
     */

    return 0;
}
