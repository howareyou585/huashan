#pragma once
#include "gmeDefine.h"
namespace Smart3dMap 
{
	class gmeParseObj
	{
	public:
		gmeParseObj();
		~gmeParseObj();
		void fillPoints(vec3dList pnts);
		void fillTriangles(vecTriList tris);
		void setObjName(string name);
		int getPointsNum();
		int getTrianglesNum();
		string getName();
		vector<int> getBatchId();
	private:
		vec3dList m_points;
		vecTriList m_triangles;
		string m_name;
		vector<int> m_bachId;
	};
}

