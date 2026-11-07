#include "ai/core/Job.hpp"
#include <string>
#include <string_view>
#include <stdexcept>
#include <utility>

namespace ai {
    Job::Job(std::string j_id, std::string_view j_idea) : id(std::move(j_id)), idea(std::move(j_idea)){
        if(id.find_first_not_of(" \t\n\r") == std::string::npos){
            throw std::invalid_argument("JOB ID cannot be empty");
        }

        if(idea.find_first_not_of(" \t\n\r") == std::string::npos){
            throw std::invalid_argument("Idea cannot be empty");
        }

    }

    std::string_view toString(JobStatus status) noexcept {
        switch (status) {
            case JobStatus::Queued: return "queued";
            case JobStatus::Planning: return "planning";
            case JobStatus::Sourcing: return "sourcing";
            case JobStatus::GeneratingAudio: return "generating_audio";
            case JobStatus::Editing: return "editing";
            case JobStatus::Rendering: return "rendering";
            case JobStatus::Completed: return "completed";
            case JobStatus::Failed: return "failed";
        }

        return "unknown";
    }
}