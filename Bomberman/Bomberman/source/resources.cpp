#include "resources.h"
#include <cctype>
#include <algorithm>
std::string Resources::Paths::GetPath(std::string in_key)
{
	std::transform(in_key.begin(), in_key.end(), in_key.begin(),
		[](unsigned char c) { return std::tolower(c); });
	if (resources_paths.count(in_key))
	{
		return resources_paths[in_key];
	}
	return std::string();
}
