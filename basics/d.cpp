#include <simplecpp>

int factorial(int num) {
    if(num == 0) {
        return 1;
    }
    cout<<"inside factorial\n"<<num<<"\n";
    int factorial = 1;
    int i = 1;
    repeat(num) {
        factorial *= i;
        i += 1;
    }
    return factorial;
}

main_program {
    int r;
    cout << "enter the value of r: ";
    cin >> r;
    cout<<"r: "<<r<<"\n";
    int r_factorial = factorial(r);
    cout<<"outside factorial"<<r_factorial<<"\n";
    int i = 0;
    int sum = 0;
    repeat(r + 1) {
        int i_factorial = factorial(i);
        int j = -1;
        if(i % 2 == 0) {
            j = 1;
        }
        cout<<"inside repeat"<<((1 / i_factorial) * j) <<"\n";

        sum += ((1 / i_factorial) * j);

        i += 1;
    }
    sum *= r_factorial;
    cout<< "answer is: " << sum << "\n";

}