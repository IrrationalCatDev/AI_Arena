#include <functional>

template <typename T>
class ScopeGuard
{
public:
    ScopeGuard(){};
    ~ScopeGuard()
    {
        m_lambda(item);
    }


    void SetDestructionFunction(std::function<void(T)> lambda)
    {
        m_lambda = lambda;
    }

    T& Get()
    {
        return item;
    }
private:
    T item;
    std::function<void(T)> m_lambda;
};
