#include "StringSet.h"
using namespace std;

StringSet::StringSet(){
	max_size = 2;
	current_size = 0;
	string_array = new string[2];
}

StringSet::StringSet(const StringSet &original){
	current_size = original.current_size;
	max_size = original.max_size;
	string_array = new string[max_size];
	for(int i = 0; i < current_size;i++){
		string_array[i] = original.string_array[i];
	}
}

int StringSet::find(string str) const{
	int ind = -1;
	for (int i=0; i < current_size; i++){
		if(string_array[i].compare(str) == 0){
			ind = i;
			break;
		}
	}
	return ind;
}

bool StringSet::insert(string str){
	if ( find(str) == -1){
		if(max_size == current_size){
			max_size *=2;
			string* temp = string_array;
			string_array = new string[max_size];
			for(int i = 0; i < current_size;i++){
				string_array[i] = temp[i];
			}
			delete[] temp;
		}
		string_array[current_size] = str;
		current_size++;
		return true;
	}
	else{return false;}
}

bool StringSet::remove(string str){
	int ind = find(str);
	if (ind == -1) {return false;}
	else{
		if(current_size > 1){
			string_array[ind] = string_array[current_size - 1];
		}
		current_size--;
		return true;
	}
}

StringSet StringSet::unions(const StringSet &arg) const {
	StringSet result(arg);
	for(int i = 0; i < current_size; i++){
		if(result.find(string_array[i]) == -1){
			result.insert(string_array[i]);
		}
	}
	return result;
}

StringSet StringSet::intersection(const StringSet &arg) const {
	StringSet result(*this);
	for(int i = 0; i < current_size; i++){
		if(arg.find(string_array[i]) == -1){ 
			result.remove(string_array[i]);
		}
	}
	return result;
}

StringSet StringSet::difference(const StringSet &arg) const {
	StringSet result(arg);
	for(int i = 0; i < current_size; i++){
		if(arg.find(string_array[i]) == -1){
			result.insert(string_array[i]);
		}
		else{
			result.remove(string_array[i]);
		}
	}
	return result;
}