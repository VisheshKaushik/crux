class SVal {
  public:
    ~SVal() {}
    const void* Data;
    unsigned Kind;
};

int foo = &var;

void bar(int *v){}

void bar(class SVal &v) {}
class A {
public:
  void foo(class SVal v) { bar(v); }
};

int main() {
  class SVal v;
  v.Data = 0;
  v.Kind = 2142;
  class A a;
  a.foo(v);
  return 0;
}
