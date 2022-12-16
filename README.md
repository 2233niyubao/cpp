# Singular Template
```C++
template<typename Derived>
class SingularTemplate
{
public:
  void Handle()
  {
    static_cast<Derived*>(this)->Handle();
  }
};

class HandleArg_1 : public SingularTemplate<HandleArg_1>
{
public:
  void Handle()
  {
  
  }
};

class HandleArg_2 : public SingularTemplate<HandleArg_2>
{
public:
  void Handle()
  {
  
  }
};

```
