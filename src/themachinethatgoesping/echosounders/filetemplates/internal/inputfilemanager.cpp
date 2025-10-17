// SPDX-FileCopyrightText: 2022 - 2025 Peter Urban, Ghent University
//
// SPDX-License-Identifier: MPL-2.0

#include "inputfilemanager.hpp"

/* std includes */
#include <map>

#include <fmt/format.h>

namespace themachinethatgoesping {
namespace echosounders {
namespace filetemplates {
namespace internal {

InputFileManagerBase::InputFileManagerBase()
	: _file_paths(std::make_shared<std::vector<std::string>>())
	, _total_file_size(0)
{
}

size_t InputFileManagerBase::get_total_file_size() const
{
	return _total_file_size;
}

const std::shared_ptr<std::vector<std::string>>& InputFileManagerBase::get_file_paths() const
{
	return _file_paths;
}

const std::string& InputFileManagerBase::get_file_path(size_t file_nr) const
{
	return _file_paths->at(file_nr);
}

tools::classhelper::ObjectPrinter InputFileManagerBase::__printer__(
	unsigned int float_precision, bool superscript_exponents) const
{
	tools::classhelper::ObjectPrinter printer(
		"InputFileManager", float_precision, superscript_exponents);

	if (_file_paths->size() > 1)
	{
		// find number of files per file ending in the file_paths vector
		std::map<std::string, size_t> file_ending_counts;
		for (const auto& file_path : *_file_paths)
		{
			auto dot_position = file_path.find_last_of('.');
			std::string file_ending;

			if (dot_position != std::string::npos && dot_position + 1 < file_path.size())
				file_ending = file_path.substr(dot_position + 1);

			file_ending_counts[file_ending]++;
		}

		for (const auto& [file_ending, count] : file_ending_counts)
		{
			printer.register_value(fmt::format("Number of loaded .{} files: ", file_ending),
								   count);
		}
	}
	else if (!_file_paths->empty())
	{
		auto file_path = _file_paths->front();
		if (file_path.size() > 40)
			file_path = "..." + file_path.substr(file_path.size() - 40);

		printer.register_value("File path", file_path);
	}

	if (_total_file_size > 1024ull * 1024ull * 1024ull)
		printer.register_string(
			"Total file size: ",
			fmt::format("{:.2f} GB", _total_file_size / (1024.0 * 1024.0 * 1024.0)));
	else if (_total_file_size > 1024ull * 1024ull)
		printer.register_string("Total file size: ",
								fmt::format("{:.2f} MB", _total_file_size / (1024.0 * 1024.0)));
	else if (_total_file_size > 1024ull)
		printer.register_string("Total file size: ",
								fmt::format("{:.2f} KB", _total_file_size / 1024.0));
	else
		printer.register_string("Total file size: ",
								fmt::format("{} Bytes", _total_file_size));

	return printer;
}

} // namespace internal
} // namespace filetemplates
} // namespace echosounders
} // namespace themachinethatgoesping
