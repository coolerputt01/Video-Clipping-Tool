#include "ai/core/Engine.hpp"
#include "ai/core/Job.hpp"
#include <sstream>

namespace ai {

    std::string Engine::plan(std::string_view idea) const {
        Job job{"preview-only",idea};
        
        std::ostringstream prompt;

        prompt << "Job ID: " << job.id << "\n";
        prompt << "Story: " << job.idea << "\n";
        prompt << "Status: " << toString(job.status) << "\n\n";

        prompt << "Production pipeline:\n";
        prompt << "[1] Research & script\n";
        prompt << "[2] Find approved football footage\n";
        prompt << "[3] Generate voiceover\n";
        prompt << "[4] Analyze & edit clips\n";
        prompt << "[5] Generate subtitles\n";
        prompt << "[6] Render final video\n";
        prompt << "[7] Generate YouTube metadata\n";

        prompt << "\nStatus: PLAN PREVIEW ONLY\n";

        return prompt.str();

    }

}