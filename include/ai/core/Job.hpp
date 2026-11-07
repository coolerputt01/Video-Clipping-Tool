#pragma once

#include <iostream>
#include <string>
#include <string_view>

namespace ai {
    enum class JobStatus {
        Queued,
        Planning,
        Sourcing,
        GeneratingAudio,
        Editing,
        Rendering,
        Completed,
        Failed
    };

    std::string_view toString(JobStatus status)  noexcept(true);

    struct Job {
        std::string id;
        std::string_view idea;
        JobStatus status = JobStatus::Queued;

        Job(std::string id, std::string_view idea);
    };
}