#include "garbage-collector.h"
#include <iostream>
namespace GC {

	std::vector<std::shared_ptr<Actors::GameObject>> GarbageCollector::objects_to_destroy;
	std::unique_ptr<GarbageCollector> GarbageCollector::instance;
	GarbageCollector::~GarbageCollector()
	{
	}
	GarbageCollector::GarbageCollector()
	{
	}
	GarbageCollector& GarbageCollector::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = std::unique_ptr<GarbageCollector>(new GarbageCollector());
		}
		return *instance;
	}
	void GarbageCollector::ClearObjects()
	{
		if (objects_to_destroy.size() > 0)
		{
			objects_to_destroy.clear();
		}
	}
}

