#include "ai/core/Engine.hpp"
#include "ai/core/Job.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

void expect(bool condition, const std::string& message){
    if(!condition){
        throw std::runtime_error(message);
    }
}

int main() {
    try {
        ai::Job job{
            "test-001",
            "Messi scores a stunning goal"
        };
        
        expect(job.id == "test-001", "Wrong job ID");
        expect(
            job.status == ai::JobStatus::Queued,
            "Initial job status should be queued"
        );
        expect(
            ai::toString(job.status) == "queued",
            "Wrong status string"
        );

        bool rejectedEmptyStory = false;

        try {
            ai::Job invalid{"test-002", "   "};
            (void)invalid;

        } catch (const std::invalid_argument&) {
            rejectedEmptyStory = true;
        }

        expect(
            rejectedEmptyStory,
            "Empty story should be rejected"
        );

        bool rejectedEmptyId = false;

        try {
            ai::Job invalid{"", "A valid story"};
            (void)invalid;
        } catch (const std::invalid_argument&) {
            rejectedEmptyId = true;
        }

        expect(
            rejectedEmptyId,
            "Empty ID should be rejected"
        );

        ai::Engine engine;

        const std::string result = engine.plan(
            "Ronaldo's incredible free kick"
        );

        expect(
            result.find("Ronaldo's incredible free kick") != std::string::npos,
            "Engine output missing story"
        );

        expect(
            result.find("Status: queued") != std::string::npos,
            "Engine output missing job status"
        );

        std::cout << "All core tests passed!\n";
        return 0;

    } catch (const std::exception& error) {
        std::cerr << "TEST FAILED: " << error.what() << '\n';
        return 1;
    }
}