#pragma once
#include<memory>
#include<vector>
#include"game-object.h"
#include"collider.h"
namespace GC {
	class GarbageCollector {

	public:
		~GarbageCollector();
		GarbageCollector(const GarbageCollector& in_other) = default;
		GarbageCollector& operator=(const GarbageCollector& in_other) = default;
	protected:
		GarbageCollector();
	public:
		static GarbageCollector& GetInstance();
		static void ClearObjects();

	public:
		static std::vector<std::shared_ptr<Actors::GameObject>> objects_to_destroy;
	private:
		static std::unique_ptr<GarbageCollector> instance;
	};
}