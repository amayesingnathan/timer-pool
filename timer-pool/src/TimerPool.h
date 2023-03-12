#pragma once

#include "Timer.h"
#include "AppTimers.h"
#include "EnumUtils.h"

namespace tpp {

    class TimerPool
    {
    private:
        template<AppTimers T>
        static constexpr Timer Get() { return std::get<T>(sTimerFactory); }

    public:
        template<AppTimers T>
        static void Start()
        {
            constexpr Timer timer = Get<T>();
        }
        template<AppTimers T>
        static void Stop()
        {
            constexpr Timer timer = Get<T>();
        }

    private:
        static constexpr Enum::Array<AppTimers, Timer> sTimerFactory {};
    };
    
}