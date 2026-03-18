#pragma once

#include <string>
#include <unordered_map>

namespace i2p {
	namespace data {

		class GrayNetResolver {
		public:
			static GrayNetResolver& Instance();

			void Load(const std::string& path);
			std::string Resolve(const std::string& host);

		private:
			GrayNetResolver() = default;

			std::unordered_map<std::string, std::string> m_Zones;
		};

	} // namespace data
} // namespace i2p
