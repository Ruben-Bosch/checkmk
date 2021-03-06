
// provides basic api to start and stop service
#include "stdafx.h"

#include <chrono>
#include <string>

#include "tools/_misc.h"
#include "tools/_raii.h"
#include "tools/_xlog.h"

#include "providers/system_time.h"

namespace cma {

namespace provider {

std::string SystemTime::makeBody() const {
    using namespace std::chrono;

    XLOG::t(XLOG_FUNC + " entering");

    const auto now = cma::tools::SecondsSinceEpoch();
    return std::to_string(now);
}

}  // namespace provider
};  // namespace cma
