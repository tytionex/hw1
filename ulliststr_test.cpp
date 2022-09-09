/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
#include <cassert>

using namespace std;

//int main(int argc, char*argv[])
int main()
{

//____________________________________________
  /*
  test dat
  pushing back till 11 items are in the list 
  there are 2 nodes one filled the other with one element
  call pop_back to delete the last element
  end with one node with 10 elements
  */
  cout << "____________________" << endl;
  cout << "dat test:" << endl;
  ULListStr dat; 
  dat.push_back("a"); // 1
  dat.push_back("b"); // 2
  dat.push_back("c"); // 3
  dat.push_back("d"); // 4
  dat.push_back("e"); // 5
  dat.push_back("f"); // 6
  dat.push_back("g"); // 7
  dat.push_back("h"); // 8
  dat.push_back("i"); // 9
  dat.push_back("j"); // 10 filled node
  dat.push_back("k"); // 11 new allocaded node
  dat.pop_back();     // 10 

  assert( dat.size() == 10 );

  cout << "size:  " << dat.size() << endl;
  cout << "empty: " << dat.empty() << endl;
  cout << "front: " << dat.front() << endl;
  cout << "back:  " << dat.back() << endl;
  cout << "loc:0   " << dat.get(0) << endl;
  cout << "loc:1   " << dat.get(1) << endl;
  cout << "loc:2   " << dat.get(2) << endl;
  cout << "loc:3   " << dat.get(3) << endl;
  cout << "loc:4   " << dat.get(4) << endl;
  cout << "loc:5   " << dat.get(5) << endl;
  cout << "loc:6   " << dat.get(6) << endl;
  cout << "loc:7   " << dat.get(7) << endl;
  cout << "loc:8   " << dat.get(8) << endl;
  cout << "loc:9  " << dat.get(9) << endl;
  cout << "____________________" << endl;
  
  
//____________________________________________
  /* 
  dat1 test
  testing .push_front where the one node is full and the other is with one element
  call popfront to remove the element from the top node, end function should be one 
  node with all 10 elements
  */

  cout << "dat1 test:" << endl;
  ULListStr dat1;
  dat1.push_front("c"); // 1
  dat1.push_front("d"); // 2
  dat1.push_front("e"); // 3
  dat1.push_front("f"); // 4
  dat1.push_front("g"); // 5
  dat1.push_front("h"); // 6
  dat1.push_front("i"); // 7
  dat1.push_front("j"); // 8
  dat1.push_front("k"); // 9
  dat1.push_front("l"); // 10
  dat1.push_front("m"); // 11
  dat1.pop_front(); // 10
  cout << "size:  " << dat1.size() << endl;
  cout << "front: " << dat1.front() << endl;
  cout << "back:  " << dat1.back() << endl;
  cout << "loc:0   " << dat1.get(0) << endl;
  cout << "loc:9   " << dat1.get(9) << endl;
  cout << "____________________" << endl;

//____________________________________________
  /* 
  test to see if the proper element is still there
  two nodes created one with an elemtent at the back and 
  the second node has element at the front 
  */
  cout << "dat2 test:" << endl;
  ULListStr dat2;
  dat2.push_front("z");
  dat2.push_back("y");
  dat2.pop_back();
  cout << "size:  " << dat2.size() << endl;
  cout << "front: " << dat2.front() << endl;
  cout << "back:  " << dat2.back() << endl;
  cout << "loc:   " << dat2.get(0) << endl;
  cout << "____________________" << endl;

//____________________________________________
  /*
  testing removing from the back and the front 
  string 5 should be at the middle and still exist
  */
  cout << "dat3 test:" << endl;
  ULListStr dat3;
  dat3.push_back("1");
  dat3.push_back("2");
  dat3.push_back("3");
  dat3.push_back("4");
  dat3.push_back("5");
  dat3.push_back("6");
  dat3.push_back("7");
  dat3.push_back("8");
  dat3.push_back("9");
  dat3.push_back("10");
  dat3.pop_front();
  dat3.pop_front();
  dat3.pop_front();
  dat3.pop_front();
  dat3.pop_back();
  dat3.pop_back();
  dat3.pop_back();
  dat3.pop_back();
  dat3.pop_back();
  cout << "size:  " << dat3.size() << endl;
  cout << "front: " << dat3.front() << endl;
  cout << "back:  " << dat3.back() << endl;
  cout << "loc:0  " << dat3.get(0) << endl;
  cout << "____________________" << endl;



//____________________________________________
  /* 
  testing call front on the an empty
  should throw an exception
  */
  cout << "dat4 test:" << endl;
  ULListStr dat4;
  dat4.push_back("z");
  //dat4.pop_back();
  dat4.pop_back();
  
  cout << "size:  " << dat4.size() << endl;
  cout << "front: " << dat4.front() << endl;
  // cout << "back:  " << dat4.back() << endl;
  cout << "____________________" << endl;
  


// // testing .push_back delete node then push_back on empty node
//   cout << "____________________" << endl;
//   cout << "dat6 test:" << endl;
//   ULListStr dat6;
//   dat6.push_front("c");
//   dat6.pop_front();
//   dat6.push_front("d");

//   cout << "size:   " << dat6.back() << endl;
//   cout << "front:  " << dat6.back() << endl;
//   cout << "back.:  " << dat6.front() << endl;
//   cout << "____________________" << endl;

//   // testing push front on empty node
//   cout << "____________________" << endl;
//   cout << "dat5 test:" << endl;
//   ULListStr dat5;
//   dat5.push_front("c");
//   dat5.pop_front();
//   dat5.push_front("d");

//   cout << "size:   " << dat5.back() << endl;
//   cout << "front:  " << dat5.back() << endl;
//   cout << "back.:  " << dat5.front() << endl;
//   cout << "____________________" << endl;

  
  

  
  
  

  return 0;
}
