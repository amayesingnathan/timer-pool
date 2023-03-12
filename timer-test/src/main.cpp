#include "TimerPool.h"

using namespace tpp;

int main()
{
    TimerPool::Start<AppTimers::Test>();

    long count = 0;
    for (int i = 0; i < 1000000; i++)
    {
        for (int j = 0; j < 1000000; j++)
        {
            for (int k = 0; k < 1000000; k++)
            {
                count++;
            }
        }
    }

    TimerPool::Stop<AppTimers::Test>();
}