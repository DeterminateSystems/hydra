#include "metrics.hh"

PromMetrics::PromMetrics()
    : registry(std::make_shared<prometheus::Registry>())
    , queue_checks_started(
        prometheus::BuildCounter()
            .Name("hydraqueuerunner_queue_checks_started_total")
            .Help("Number of times State::getQueuedBuilds() was started")
            .Register(*registry)
            .Add({})
    )
    , queue_build_fetch_time(
        prometheus::BuildHistogram()
            .Name("hydraqueuerunner_queue_fetch_seconds")
            .Help("How long it takes to query the database for queued builds")
            .Register(*registry)
            .Add({}, prometheus::Histogram::BucketBoundaries{0.5, 1, 2.5, 5, 10, 15})
    )
    , queue_build_load_family(
        prometheus::BuildHistogram()
            .Name("hydraqueuerunner_queue_build_loads_seconds")
            .Help("How long it takes to load individual builds")
            .Register(*registry)
    )
    , queue_build_load_missed_exit(
        queue_build_load_family
            .Add({{"disposition", "unknown-exit"}}, prometheus::Histogram::BucketBoundaries{0.05, 0.1, 0.25, 0.5, 1, 2.5})
    )
    , queue_build_load_premature_gc(
        queue_build_load_family
            .Add({{"disposition", "premature-gc"}}, prometheus::Histogram::BucketBoundaries{0.05, 0.1, 0.25, 0.5, 1, 2.5})
    )
    , queue_build_load_cached_failure(
        queue_build_load_family
            .Add({{"disposition", "cached-failure"}}, prometheus::Histogram::BucketBoundaries{0.05, 0.1, 0.25, 0.5, 1, 2.5})
    )
    , queue_build_load_cached_success(
        queue_build_load_family
            .Add({{"disposition", "cached-success"}}, prometheus::Histogram::BucketBoundaries{0.05, 0.1, 0.25, 0.5, 1, 2.5})
    )
    , queue_build_load_added(
        queue_build_load_family
            .Add({{"disposition", "added"}}, prometheus::Histogram::BucketBoundaries{0.05, 0.1, 0.25, 0.5, 1, 2.5})
    )
    , queue_steps_created(
        prometheus::BuildCounter()
            .Name("hydraqueuerunner_queue_steps_created_total")
            .Help("Number of steps created")
            .Register(*registry)
            .Add({})
    )
    , queue_checks_early_exits(
        prometheus::BuildCounter()
            .Name("hydraqueuerunner_queue_checks_early_exits_total")
            .Help("Number of times State::getQueuedBuilds() yielded to potential bumps")
            .Register(*registry)
            .Add({})
    )
    , queue_checks_finished(
        prometheus::BuildCounter()
            .Name("hydraqueuerunner_queue_checks_finished_total")
            .Help("Number of times State::getQueuedBuilds() was completed")
            .Register(*registry)
            .Add({})
    )
    , queue_max_id(
        prometheus::BuildGauge()
            .Name("hydraqueuerunner_queue_max_build_id_info")
            .Help("Maximum build record ID in the queue")
            .Register(*registry)
            .Add({})
    )
{

}
