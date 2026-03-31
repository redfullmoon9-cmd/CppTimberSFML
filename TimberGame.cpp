// #pragma once 
// #include <iostream>

namespace userCode{ int userMain();  }
namespace bookCode{ int bookMain();  }
namespace refCode{ int refMain();  }

//enum class side2 { LEFT, RIGHT, NONE }; 

int main() {
	unsigned int choice = 0; 
	//현 작성중인 
	if (choice == 0) {
		return userCode::userMain(); 
	}
	//책의 코드 
	else if (choice == 1) {
		return bookCode::bookMain(); 
	}
	//이전 작업, 참조코드 
	else if (choice == 2) {
		return refCode::refMain(); 
	}

}