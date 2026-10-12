#include <iostream>

using namespace std;

#include <cstdlib>
class clsA
{
  private:
    // only accessible   inside this class, neither derived classes nor outside class.
    int _Var1;
    void _Fun1()
    {
        cout << "Function 1";
    }

  protected:
    // only accessible  inside this class and all derived classes, but not outside class
    int Var2;
    void Fun2()
    {
        cout << "Function 1";
    }

  public:
    // Accessable inside this class, all derived classes, and outside class
    int Var3;
    void Fun3()
    {
        cout << "Function 1";
    }
};

class clsB : public clsA
{
  public:
    void Func1()
    {
        cout << clsA::Var2;
    }
};

int main()

{
    system("pause>0");
    return 0;
}