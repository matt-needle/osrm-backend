#ifndef SERVER_SERVICE_BASE_SERVICE_HPP
#define SERVER_SERVICE_BASE_SERVICE_HPP

#include "engine/status.hpp"
#include "util/coordinate.hpp"
#include "osrm/osrm.hpp"

#include <variant/variant.hpp>

#include <string>
#include <vector>

namespace osrm
{
namespace server
{
namespace service
{

class BaseService
{
  public:
    using ResultT = mapbox::util::variant<util::json::Object, std::string>;

    BaseService(OSRM &routing_machine) : routing_machine(routing_machine) {}
    virtual ~BaseService() = default;

    virtual engine::Status RunQuery(std::string &query, ResultT &result) = 0;

    virtual unsigned GetVersion() = 0;

  protected:
    OSRM &routing_machine;
};
}
}
}

#endif
