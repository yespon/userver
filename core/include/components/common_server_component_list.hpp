#pragma once

/// @file components/common_server_component_list.hpp
/// @brief @copybrief components::CommonServerComponentList()

#include <components/component_list.hpp>

namespace components {

/// @ingroup userver_components
///
/// @brief Returns the most common list of components to start a fully
/// functional server.
///
/// The list contains:
/// * components::Server
/// * server::handlers::TestsControl
/// * server::handlers::ServerMonitor
/// * server::handlers::LogLevel
/// * server::handlers::InspectRequests
/// * server::handlers::ImplicitOptionsHttpHandler
/// * server::handlers::Jemalloc
/// * components::AuthCheckerSettings
/// * congestion_control::Component
/// * components::HttpServerSettings
ComponentList CommonServerComponentList();

}  // namespace components
