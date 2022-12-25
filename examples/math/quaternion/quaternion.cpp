/***********************************************************/
/**	
\file
\brief		Example of Quaternion
\details	This file illustrates how to use Quaternion in yzLib
\author		Zhiqi Li
\date		12/20/2020
*/
/***********************************************************/
#include <iostream>
#include<zqBasicMath/math_vector.h>
#include<zqBasicMath/math_matrix.h>
#include<zqBasicMath/math_quaternion.h>
#include<zqBasicMath/math_lookup_table.h>
#include<zqBasicMath/math_dense.h>
int main() {
	zq::Matrix3x3<double>	M[3];
	zq::Quaternion<double>	q[3];

	std::cout << "==============================" << std::endl;

	for (int i = 0; i < 3; i++) {
		M[i].SetRotationDeg(zq::Vec3d(1, 0, 0), i * 45);
		q[i].Set(M[i]);
	}

	std::cout << "Matrix 0, rotate around x-axis for 0 degrees" << std::endl << M[0];
	std::cout << "Quaternion 0" << std::endl << q[0] << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Matrix 1, rotate around x-axis for 45 degrees" << std::endl << M[1];
	std::cout << "Quaternion 1" << std::endl << q[1] << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Matrix 2, rotate around x-axis for 90 degrees" << std::endl << M[2];
	std::cout << "Quaternion 2" << std::endl << q[2] << std::endl;
	std::cout << "--------------------" << std::endl;

	zq::Quaternion<double> q_slerp = zq::interpSlerp(q[0], q[2], 0.5);
	std::cout << "Slerp interpolate Quaternion 0 and 2:" << std::endl << q_slerp << std::endl;
	std::cout << "should equal Quaternion 1" << std::endl << q[1] << std::endl;
	zq::Matrix3x3<double> M_slerp(q_slerp);
	std::cout << "Matrix of Slerp Quaternion " << std::endl << M_slerp;
	std::cout << "should equal Matrix 1" << std::endl << M[1];
	std::cout << "--------------------" << std::endl;

	std::cout << "Quaternion 1 * Quaternion 1:" << std::endl << q[1] * q[1] << std::endl;
	std::cout << "should equal Quaternion 2" << std::endl << q[2] << std::endl;
	std::cout << "--------------------" << std::endl;

	return 0;
}