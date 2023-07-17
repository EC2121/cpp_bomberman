#include "collider.h"
#include "physics-mgr.h"
#include "game.h"
#include <memory>
#include <vector>
#include "game-object.h"
#include "box-collider.h"
#include <iostream>
#include <algorithm>
#include "garbage-collector.h"
namespace Physics {
	Collider::~Collider()
	{
		
	}
	void Collider::Destroy(int id)
	{
		auto condition = [id](std::weak_ptr<Collider> ref) {
			return (ref.lock()->GetId() == id || ref.expired());
		};
		PhysicsMgr::colliders_in_scene.erase(std::remove_if(PhysicsMgr::colliders_in_scene.begin(),
		                                                    PhysicsMgr::colliders_in_scene.end() - 1, condition));
		/*auto partition = std::stable_partition(PhysicsMgr::colliders_in_scene.begin(), PhysicsMgr::colliders_in_scene.end(),
			[&](const auto& x) { return !condition(x); });
		GC::GarbageCollector::colliders_to_destroy.insert(GC::GarbageCollector::colliders_to_destroy.end(), std::make_move_iterator(partition),
			std::make_move_iterator(PhysicsMgr::colliders_in_scene.end()));
		PhysicsMgr::colliders_in_scene.erase(partition, PhysicsMgr::colliders_in_scene.end());*/

	}
	void Collider::Update()
	{
		if (type == STATIC) return;
		position = owner.GetPosition();
	}

}
