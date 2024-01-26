#include <iostream>

class smart_array {
private:
	int* arr;
	int elements;
	int cursor;

public:
	smart_array(int n) {
		elements = n - 1;
		cursor = 0;
		arr = new int[n];
	}

	~smart_array() {
		delete[] arr;
	}

	void add_element(int elem) {
		if (cursor > elements) {
			int* temp = new int[(elements * 2) + 1];
			for (auto i = 0; i <= elements; i++) {
				temp[i] = arr[i];
				std::cout << temp[i] << std::endl;
			}
			temp[cursor] = elem;
			elements = elements * 2;
			arr = temp;
			delete[] temp;
		}
		else {
			arr[cursor] = elem;
		}
		cursor++;
	}

	int get_element(int elem) {
		if (elem > cursor || elem < 0) {
			std::cout << "Неверный индекс" << std::endl;
			return 0;
		}
		else {
			return arr[elem];
		}
	}

	void operator=(smart_array& arr1) {

		for (auto i = 0; i <= arr1.elements; i++) {
			arr[i] = arr1.get_element(i);
		}
		cursor = arr1.cursor;
		elements = arr1.elements;
	}
};


int main() {
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	arr = new_array;
}