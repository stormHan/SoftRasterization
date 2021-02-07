
#include "geometrymanager.h"
#include "tools/logger.h"

namespace rasterization 
{
	GeometryManager* GeometryManager::_instance = nullptr;

	GeometryManager* GeometryManager::getInstance()
	{
		//todo : ��������ģʽ�ĵ���ģʽ���̲߳���ȫ��
		// ���Կ����滻�������ʹ���������C++11��ľֲ�staitc����
		if (_instance == nullptr)
		{
			_instance = new GeometryManager();
		}
		return _instance;
	}

	GeometryManager::~GeometryManager()
	{
		delete _input_data;
		_input_data = nullptr;
	}

	GeometryManager::GeometryManager() : _input_data(nullptr)
	{
		
	}

	bool GeometryManager::injectRenderData()
	{
		if (_input_data == nullptr)
		{
			Log("[GeometryManager] inject data failed because this->_input_data is null");
			return false;
		}

		return injectRenderData(_input_data->getVextexData(), _input_data->getIndexData());

	}

	bool GeometryManager::injectRenderData(const std::vector<Point2D>& vertex, const std::vector<Uint32>& indexes)
	{
		bool success = true;
		Uint32 facet_count = indexes.size() / 3;
		// ����û�м�����ݵ���ȷ�ԣ�Ŀǰinputdata���汣֤
		for (Uint32 i = 0; i < facet_count; ++i)
		{
			Triangle2Df new_triangle(vertex[indexes[i * 3 + 0]],
									vertex[indexes[i * 3 + 1]],
									vertex[indexes[i * 3 + 2]]);

			_triangle2Ds.push_back(new_triangle);
		}

		return success;
	}

	void GeometryManager::setInputData2D(InputData2D* input_data)
	{
		_input_data = input_data;
	}
}