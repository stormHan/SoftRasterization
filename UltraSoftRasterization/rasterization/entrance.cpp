// ----------- Soft Rasterization -----------
// Author: stormhan
// Date: 2021/01/03

#ifndef __ENTRANCE__
#define __ENTRANCE__

#include "tools/logger.h"
#include "inputdata2D.h"
#include "rasterization/geometrymanager.h"
#include "rasterization/raster.h"
#include "rasterization/rendertarget.h"
#include "rasterization/displayment.h"

using namespace rasterization;

int main(int argc, char** argv)
{
	Log("Soft Rasterization starts...");

	InputData2D single_input;
	single_input.loadData();
	
	rasterization::GeometryManager* g_geometry_manager = rasterization::GeometryManager::getInstance();
	g_geometry_manager->setInputData2D(&single_input);
	g_geometry_manager->injectRenderData();

	std::shared_ptr<RenderTarget> rt = std::make_shared<RenderTarget>(800, 600);

	Rasterization g_raster;
	Color color(1.0, 0.0, 0.0, 1.0);
	g_raster.raster2D(rt, g_geometry_manager->getTriangles2D(), color);

	std::string windows_name("Draw a triangle");
	std::shared_ptr<DisplayOpenCv> displayment = std::make_shared<DisplayOpenCv>(rt, windows_name);
	displayment->display();

	Log("Soft Rasterization ends...");
	return 0;
}


#endif