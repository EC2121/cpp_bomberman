#pragma once
#include <map>
#include <string>

#define ADD_TO_RESOURCES_PATHS(key,value) resources_paths[key] = value;
namespace Resources {
	class Paths {

	public:
		static std::string GetPath(std::string in_key);
	private:
		static inline std::map<std::string, std::string> resources_paths =
		{
			{"zombie", "resources\\zombie.png"},
			{"zombie_walk", "resources\\zombie-walk.png"},
			{"wall", "resources\\grey_64x64.png"},
			{"wall_destryable", "resources\\grey_64x64_destroyable.png"},
			{"bomb", "resources\\bomb.png"},
			{"bomb_explosion", "resources\\bombsp.png"},
			{"zombie_attack", "resources\\spr_zombie_charge.png"}

		};


	};
	

}
//static std::map<std::string, std::string> resources_paths = std::map<std::string, std::string>();
