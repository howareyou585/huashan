#include "gmeParseObj.h"
namespace Smart3dMap
{
	gmeParseObj::gmeParseObj()
	{
		point3d pnt1 = point3d(1, 2, 3);
		point3d pnt2 = point3d(1, 2, 3);
		m_points.push_back(pnt1);
		m_points.push_back(pnt2);
	}

	gmeParseObj::~gmeParseObj()
	{
	}

	void gmeParseObj::fillPoints(vec3dList pnts)
	{
		m_points.assign(pnts.begin(), pnts.end());
	}

	void gmeParseObj::fillTriangles(vecTriList tris)
	{
		m_triangles.assign(tris.begin(), tris.end());
	}

	void gmeParseObj::setObjName(string name)
	{
		m_name = name;
	}

	int gmeParseObj::getPointsNum()
	{
		return m_points.size();
	}

	int gmeParseObj::getTrianglesNum()
	{
		return m_triangles.size();
	}

	string gmeParseObj::getName()
	{
		return m_name;
	}

	vector<int> gmeParseObj::getBatchId()
	{
		return m_bachId;
	}

}
