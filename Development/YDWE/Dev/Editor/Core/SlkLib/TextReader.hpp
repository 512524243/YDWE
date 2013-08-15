#pragma once

#include "Buffer.hpp"
#include "Util.hpp"
#include <functional>
#include <ydwe/util/string_ref.h>

namespace slk
{
	struct TextReader
	{
		static void RemoveBom(buffer_reader& reader);
		static void EachLine(buffer_reader& reader, std::function<void(boost::string_ref&)> callback);
	};
}
