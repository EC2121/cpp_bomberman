#pragma once
#include <memory>
#include "animation.h"
#include <map>
#include <string>

namespace Animations {
	class IAnimatable {
	public:
		IAnimatable() = default;
		~IAnimatable();
	public:
		void InsertAnimation(std::string const& in_key, std::shared_ptr<Animation> in_anim);
		void ChangeCurrentAnimation(std::string const& in_new_anim_key);
	protected:
		void Update();

	protected:
		std::map<std::string, std::shared_ptr<Animation>> animations_map;
		std::shared_ptr<Animation> curr_animation;
	};
}