// (c) Victor Agababov (vagababov@gmail.com) 2011
// Not reserving most of the rights.
#include "range-request-generator.h"
#include "range-generator.h"

#include <sstream>


#include "slowlog.h"


using std::string;

namespace {
const char kVersion[] = " HTTP/1.1\r\nHost: ";
}  // namespace

namespace slowhttptest {

void GenerateHeadRequestWithRange(const string& verb, 
                                  const string& path, const string& host,
                                  int start, int step, int limit,
                                  string* output) {
  CHECK_NOTNULL(output)->clear();
  std::ostringstream oss;
  oss << verb << " " << path << kVersion << host << "\r\n";
  GenerateRangeHeader(start, step, limit, output);
}

}  // namespace slowhttptest
