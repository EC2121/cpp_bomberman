#include "IAnimatable.h"


namespace Animations {



	IAnimatable::~IAnimatable()
	{
		animations_map.clear();
	}

	void IAnimatable::InsertAnimation(std::string const& in_key, std::shared_ptr<Animations::Animation> in_anim)
	{
		animations_map[in_key] = in_anim;
		curr_animation = in_anim;
	}

	void IAnimatable::ChangeCurrentAnimation(std::string const& in_new_anim_key)
	{
		if (curr_animation == nullptr) {
			return;
		}
		curr_animation->Stop();
		curr_animation->Reset();
		curr_animation = animations_map[in_new_anim_key];
		curr_animation->Play();
	}

	void IAnimatable::Update()
	{
		if (curr_animation.get())
		{
			curr_animation->Update();
		}
	}

}
