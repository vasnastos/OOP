#include <iostream>
#include <memory>
#include <mutex>

// a smart pointer that retains shared ownership of an object through a pointer. 
// Several shared_ptr objects may own the same object. The object is destroyed and its memory deallocated when either of the following happens
//   the last remaining shared_ptr owning the object is destroyed;
//   the last remaining shared_ptr owning the object is assigned another pointer via operator= or reset(). 

int main()
{
    {
        std::shared_ptr <int> apointer(new int(345));
        static std::mutex io_mutex;
        std::lock_guard <std::mutex> lk(io_mutex);
        std::cout<<"Value:"<<apointer.get()<<std::endl;
        std::cout<<"Count Use:"<<apointer.use_count()<<std::endl;
        std::shared_ptr <int> apointer2(apointer);
        std::cout<<"Value:"<<apointer2.get()<<std::endl;
        std::cout<<"Count Use:"<<apointer2.use_count()<<std::endl;
        apointer.reset();
        apointer=std::make_shared<int>(56);
        std::cout<<"Value:"<<apointer.get()<<std::endl;
        std::cout<<"Count use:"<<apointer.use_count()<<std::endl;
        auto np=std::make_shared<int>(47);
    }
    return 0;
}