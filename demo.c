#include "array.h"

using std.array;


namespace std {

	struct vector <T> {
		T* data;
		size_t size, capacity;
	};

	namespace vector {

		static int helper() { ... }

		void pop_back <T> ( struct std.vector<T>* vec ) { ... }

		void pop_back <T> ( struct std.vector<T>* vec, void (*destructor)(T*) ) { ... }
	}
}


int main ( void ) {

	struct std.vector<char*> my_vec;

	std.vector.pop_back( &my_vec,  (char** p) { free(*p); } );

	return 0;
}

