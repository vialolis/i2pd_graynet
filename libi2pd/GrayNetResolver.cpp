#include "GrayNetResolver.h"
#include <fstream>
#include <sstream>
#include <algorithm>

namespace i2p {
	namespace data {

		GrayNetResolver& GrayNetResolver::Instance() {
			static GrayNetResolver instance;
			return instance;
		}

		void GrayNetResolver::Load(const std::string& path) {
			std::ifstream file(path);
			if (!file.is_open()) return;

			std::string line;

			while (std::getline(file, line)) {
				if (line.empty() || line[0] == '#') continue;

				auto pos = line.find('=');
				if (pos == std::string::npos) continue;

				std::string host = line.substr(0, pos);
				std::string dest = line.substr(pos + 1);

				std::transform(host.begin(), host.end(), host.begin(), ::tolower);

				m_Zones[host] = dest;
			}
		}

		std::string GrayNetResolver::Resolve(const std::string& host) {
			std::string key = host;
			std::transform(key.begin(), key.end(), key.begin(), ::tolower);

			auto it = m_Zones.find(key);
			if (it != m_Zones.end())
				return it->second;

			return "";
		}

	} // namespace data
} // namespace i2p
