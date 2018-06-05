#include <string>

class StringSet{
private:
	std::string* string_array;
	int current_size;
	int max_size;
public:
	StringSet();
	//constructor that creates an array of strings of size 2 in dynamic memory, sets maximum size to 2, and current size to 0//

	StringSet(const StringSet &);
	//copy constructor that creates a deep copy of its parameter

	~StringSet() {delete[] string_array;}
	//destructor that frees dynamic memory associated with the object’s string (array) pointer

	int size() const {return current_size;}
	//returns the current size (the number of strings in the array)
	//("const" means cannot change a member variable of the class)

	int find(std::string) const;
	//if a string matching the parameter is in the array returns the index of that string, otherwise returns -1

	bool insert(std::string);
	// returns false without inserting value if a string matching the parameter is already in the array, otherwise: inserts the string parameter at the next available index; if the underlying array is full, doubles the maximum size attribute, creates an array of twice the size of the current array, copies the contents of the old array to the new array, frees memory associated with the old array, and assigns new array’s address to object’s array pointer, then inserts parameter; increments current size and returns true

	bool remove(std::string);
	// returns false if a string matching the parameter is not in the array, otherwise: replaces matching string with the last string in the array (if there is one); decrements current size and returns true

	StringSet unions(const StringSet &) const;
	// returns a StringSet object that contains the union of the calling object and the parameter (if the result is the empty set the returned StringSet object’s current size should equal zero); in case you were wondering, this method is called unions because union is a reserved word

	StringSet intersection(const StringSet &) const;
	// returns a StringSet object that contains the intersection  of the calling object and the parameter

	StringSet difference(const StringSet &) const;
	// returns a StringSet object that contains the set difference of the calling object and the parameter
};