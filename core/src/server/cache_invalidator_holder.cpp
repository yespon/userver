#include <server/cache_invalidator_holder.hpp>

#include <cache/cache_invalidator.hpp>

namespace server {

CacheInvalidatorHolder::CacheInvalidatorHolder(
    components::CacheUpdateTrait& cache,
    const components::ComponentContext& context)
    : cache_invalidator_{context.FindComponent<components::CacheInvalidator>()},
      cache_(cache) {
  cache_invalidator_.RegisterCacheInvalidator(
      cache_, [cache = &cache_]() { cache->UpdateFull(); });
}

CacheInvalidatorHolder::~CacheInvalidatorHolder() {
  cache_invalidator_.UnregisterCacheInvalidator(cache_);
}

}  // namespace server
