#! /bin/bash

echo "ThreadWaitMutex"
g++ -o ./bin/ThreadWaitMutex ThreadWaitMutex.cpp -g -std=c++11 -lpthread

echo "ThreadWaitMutex2"
g++ -o ./bin/ThreadWaitMutex2 ThreadWaitMutex2.cpp -g -std=c++11 -lpthread

echo "ThreadNormalRun"
g++ -o ./bin/ThreadNormalRun ThreadNormalRun.cpp -g -std=c++11 -lpthread

echo "ThreadNormalRun2"
g++ -o ./bin/ThreadNormalRun2 ThreadNormalRun2.cpp -g -std=c++11 -lpthread

echo "ThreadDeadLock"
g++ -o ./bin/ThreadDeadLock ThreadDeadLock.cpp -g -std=c++11 -lpthread

echo "ThreadNormalRun3"
g++ -o ./bin/ThreadNormalRun3 ThreadNormalRun3.cpp -g -std=c++11 -lpthread

echo "lock"
g++ -o ./bin/lock lock.cpp -g -std=c++11 -lpthread

echo "unique_lock_defer_lock_dead_lock"
g++ -o ./bin/unique_lock_defer_lock_dead_lock unique_lock_defer_lock_dead_lock.cpp -g -std=c++11 -lpthread

echo "unique_lock_defer_lock"
g++ -o ./bin/unique_lock_defer_lock unique_lock_defer_lock.cpp -g -std=c++11 -lpthread

echo "scoped_lock"
g++ -o ./bin/scoped_lock scoped_lock.cpp -g -std=c++17 -lpthread
