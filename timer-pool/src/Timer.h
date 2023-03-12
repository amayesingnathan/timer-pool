#pragma once

#include "Common.h"

namespace tpp {

    namespace Time = std::chrono;

    using Clock = Time::steady_clock;
    using TimePoint = Clock::time_point;
    
    class Timer
    {
        using FloatingPointMicroseconds = Time::duration<double, std::micro>;

    public:
        consteval Timer() {}

        void start() noexcept { mStart = Clock::now(); }
        Time::microseconds stop() noexcept 
        { 
            auto endTimepoint = Clock::now();
            auto highResStart = FloatingPointMicroseconds{ mStart.time_since_epoch() };
			return Time::time_point_cast<Time::microseconds>(endTimepoint).time_since_epoch() 
            - Time::time_point_cast<Time::microseconds>(mStart).time_since_epoch();
        }

    private:
        TimePoint mStart;
    };
}
