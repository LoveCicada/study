echo "thread_local"
g++ -o ./bin/thread_local thread_local.cpp -std=c++2a -lpthread

g++ -o ./bin/thread_local_global thread_local_global.cpp -std=c++2a -lpthread

g++ -o ./bin/thread_local_local thread_local_local.cpp -std=c++2a -lpthread

g++ -o ./bin/thread_local_class thread_local_class.cpp -std=c++2a -lpthread

g++ -o ./bin/thread_local_class thread_local_class.cpp -std=c++2a -lpthread

g++ -o ./bin/thread_local_class2 thread_local_class2.cpp -std=c++2a -lpthread

g++ -o ./bin/thread_local_class_static thread_local_class_static.cpp -std=c++2a -lpthread