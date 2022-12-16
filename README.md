# Chain of Responsibility
```C++
template<typename Derived>
class ChainOfResponsibility
{
protected:
  ChainOfResponsibility(ChainOfResponsibility* pChain)
  : m_pChain (pChain)
public:
  void Handle()
  {
    if (nullptr == m_pChain)
    {
      return;
    }
    auto pChain = static_cast<Derived*>(m_pChain);
    pChain->Handle();
  }
private:
  ChainOfResponsibility* m_pChain;
};

class ConcreteResponsibility_1 : public ChainOfResponsibility<ConcreteResponsibility_1>
{
public:
  using ChainOfResponsibility<ConcreteResponsibility_1>::ChainOfResponsibility;
  void Handle()
  {
  
  }
};

class ConcreteResponsibility_2 : public ChainOfResponsibility<ConcreteResponsibility_2>
{
public:
  using ChainOfResponsibility<ConcreteResponsibility_2>::ChainOfResponsibility;
  void Handle()
  {
  
  }
};

```
