#include <vector>


class event {

	private:
		std::vector<void (*)(void*)> subscribers;

	public:
		virtual void subscribe( void (*)(void*) ) = 0;
		virtual void unsubscribe(  ) = 0;

};



int main(){
	return 0;
}
