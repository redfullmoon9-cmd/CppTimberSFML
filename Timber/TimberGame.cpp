#pragma once 
#include <iostream>

namespace userCode{ int userMain();  }
namespace bookCode{ int bookMain();  }

//enum class side2 { LEFT, RIGHT, NONE }; 


int main() {
	unsigned int choice = 0; 
	
	if (choice == 0) {
		return userCode::userMain(); 
	}
	else if (choice == 1) {
		return bookCode::bookMain(); 
	}

}