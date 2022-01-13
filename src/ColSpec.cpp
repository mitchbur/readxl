#include "ColSpec.h"
#include <algorithm>
#include <iterator>
#include "cpp11.hpp"

using namespace cpp11;

// expose ColSpec isDateFormat to R for testing
// this is a vectorized isDateFormat
[[cpp11::register]]
std::vector<bool> colspec_is_date_format(const std::vector<std::string>& formats) {
  std::vector<bool> is_dateformat;
  is_dateformat.reserve( formats.size() );
  std::transform( formats.cbegin(), formats.cend(),
                  std::back_inserter(is_dateformat),
                  isDateFormat );
  return is_dateformat;
}
