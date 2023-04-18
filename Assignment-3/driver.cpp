#include "Vector_2D.h" 
using namespace std; 

main() {
    //Given Problems
    cout << "1. (1,3)+(0,0) = " << Pair(1,3) + Pair() << endl; 

    cout << "2. 7*(9,2) = " << 7 * Pair(9,2) << endl;

    cout << "3. (1,3)*(3,8) = " << Pair(1,3) * Pair(3,8) << endl; 

    cout << "4. (((4,9)*(6,7))*(4,1)) - ((1,3)+(2,4)) = " << (Pair(4,9) * Pair(6,7)* Pair(4,1)) - (Pair(1,3) + Pair(2,4)) << endl;
     
    cout << "5. (((3,10)*(1,17))*(4,1)) + ((1,3)-(2,4)) = " << (Pair(3,10) * Pair(1,17) * Pair(4,1)) + (Pair(1,3) - Pair(2,4)) << endl; 

    //Create new vectors to compare
    Pair p1(4,5), p2(8,4), p3 = p1; 

    cout << "Same Vector = " << (p1==p3) << endl; 
    cout << "Different Vector = " << (p1==p2) << endl; 
    
    return 0;
}