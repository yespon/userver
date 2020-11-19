#pragma once

#include <string>
#include <unordered_map>

#include <server/handlers/http_handler_base.hpp>
#include <server/http/handler_info_index.hpp>
#include <server/http/handler_method_index.hpp>
#include <server/http/http_method.hpp>

namespace engine {
class TaskProcessor;
}  // namespace engine

namespace server::http::impl {

class FixedPathIndex final {
 public:
  void AddHandler(const handlers::HttpHandlerBase& handler,
                  engine::TaskProcessor& task_processor);
  bool MatchRequest(HttpMethod method, const std::string& path,
                    MatchRequestResult& match_result) const;

 private:
  void AddHandler(std::string path, const handlers::HttpHandlerBase& handler,
                  engine::TaskProcessor& task_processor);

  std::unordered_map<std::string, HandlerMethodIndex> handler_method_index_map_;
};

}  // namespace server::http::impl