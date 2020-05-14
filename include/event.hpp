#ifndef TVT_EVENT_H
#define TVT_EVENT_H

#include <vector>

namespace tvtennis {

    class event {

        private:
            std::vector<void (*)(void*)> subscribers;

        public:
            virtual void subscribe( void (*)(void*) ) = 0;
            virtual void unsubscribe(  ) = 0;

    };

}

#endif