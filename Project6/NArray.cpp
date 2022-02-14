#include <iostream>
using namespace std;

class Array {
	const int dim;
	int* size;

	struct Address {
		int level;
		void* next;
	};
	Address* top;

public:
	Array(int dim, int* array_size) : dim(dim) {
		size = new int[dim];
		for (int i = 0; i < dim; i++) size[i] = array_size[i];
	}

	void initialize_address(Address* current) {
		if (!current) return;
		if (current->level == dim - 1) {
			current->next = new int[size[current->level]];
			return;
		}

		current->next = new Address[size[current->level]];
		for (int i = 0; i != size[current->level]; i++) {
			(static_cast<Address*>(current->next) + i)->level = current->level + 1;

			initialize_address(static_cast<Address*>(current->next) + i);
		}
	}
};

