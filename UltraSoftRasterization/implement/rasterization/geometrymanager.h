#pragma once
// ----------- Geometry Manager -----------
// Author: stormhan
// Date: 2021/01/16
// Details: 负责管理输入数据，整合成三角形，做相关处理后传递给光栅器

#ifndef __GEOMETRYMANAGER__
#define __GEOMETRYMANAGER__

#include <vector>
#include "math/triangle.h"
#include "inputdata2D.h"


namespace rasterization
{
	class GeometryManager
	{
	public:
		static GeometryManager* getInstance();

		bool injectRenderData();

		bool injectRenderData(const std::vector<Point2D>& vertex, const std::vector<Uint32>& indexes);

		void setInputData2D(InputData2D* input_data);

		
	private:
		static GeometryManager* _instance;
		GeometryManager();
		GeometryManager(const GeometryManager& rhs);
		GeometryManager& operator=(const GeometryManager& rhs);
		~GeometryManager();

		InputData2D* _input_data;
		std::vector<Triangle2Df> _triangle2Ds;		//传递给rasterization的数据
		
	};

}
#endif // __GEOMETRYMANAGER__
