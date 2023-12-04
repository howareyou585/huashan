#pragma once
#include <string>
#include <vector>
using namespace std;
namespace Smart3dMap
{
	struct point3d {
		point3d() { point3d(0, 0, 0); };
		point3d(double xx, double yy, double zz) {
			x = xx; y = yy; z = zz;
		};
		point3d operator+ (const point3d& vec)
		{
			double nx = x + vec.x;
			double ny = y + vec.y;
			double nz = z + vec.z;
			return point3d(nx, ny, nz);
		};
		double x;  
		double y;  
		double z;
	};
	struct triangle {
		int a;  
		int b;  
		int c;
	};
	typedef vector<point3d> vec3dList;
	typedef vector<triangle> vecTriList;
}

