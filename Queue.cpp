#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class RuntimeException {
  private:
    string errorMsg;
  public:
    RuntimeException(const string& err) { errorMsg = err; }
    string getMessage() const { return errorMsg; }
};

class QueueEmpty : public RuntimeException
{
  public:
    QueueEmpty(const string& err) : RuntimeException(err) {}
};

template <typename E>
class Queue
{
  public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    void Enqueue(const E& e);
    const E Dequeue() throw(QueueEmpty);
    const E& Front() const throw(QueueEmpty);
    int size() const;
  private:
    std::vector<E> s;
    int n;
};

int main()
{
  char ch; int mch; int element;
  Queue<int> st;
  while(true)
  {
    cout<<"1. Enqueue."<<endl;
    cout<<"2. Dequeue."<<endl;
    cout<<"3. Front."<<endl;
    cout<<"4. Size." <<endl;
    cout<<"5. Exit."<<endl;
    cout<<"Enter Your Choice : ";
    cin>>mch;
    if(mch==1)
    {
      while (true) {
        cout<<"Enter Y for yes & N for No to Enqueue an element to the Queue.(Y/N) : ";
        cin>>ch;
        if(ch=='Y')
        {
          std::cout << "Enter the element : ";
          std::cin >> element;
          st.Enqueue(element);
        }
        else if(ch=='N')
        {
          std::cout << "THANK YOU!! :-)" << '\n';
          break;
        }

        else
        {
          std::cout << "Enter a Valid Input!! :-(" << '\n';
          continue;
        }
      }
    }
    else if(mch==2)
    {
      while (true) {
        cout<<"Enter Y for yes & N for No to Dequeue an element from the Queue.(Y/N) : ";
        cin>>ch;
        if(ch=='Y')
        {
          try
          {
            element = st.Dequeue();
          }
          catch(QueueEmpty& er)
          {
            std::cout << er.getMessage() << '\n';
            break;
          }
          std::cout << "Element popped : "<<element<<endl;
        }

        else if(ch=='N')
        {
          std::cout << "THANK YOU!! :-)" << '\n';
          break;
        }

        else
        {
          std::cout << "Enter a Valid Input!! :-(" << '\n';
          continue;
        }
      }
    }
    else if(mch==3)
    {
      try{
        element = st.Front();
      }
      catch(QueueEmpty& er)
      {
        std::cout << er.getMessage() << '\n';
        continue;
      }
        std::cout << "Element topped : "<<element<<endl;
    }
    else if(mch==4)
    {
      std::cout << "Size : " << st.size()<<endl;
    }

    else if (mch==5)
      break;

    else
    {
      std::cout << "Enter a Valid Input!! :-(" << '\n';
      continue;
    }
  }
  return 0;
}

template <typename E>
Queue<E>::Queue()
  : n(0) {}

template <typename E>
bool Queue<E>::isEmpty() const
{
  if(n==0)
    return true;
  return false;
}

template <typename E>
const E Queue<E>::Dequeue() throw(QueueEmpty)
{
  if (isEmpty()) {
    throw QueueEmpty("Dequeue from empty Queue");
  }
  const E temp = s[0];
  s.erase(s.begin());
  n--;
  return temp;
}

template <typename E>
void Queue<E>::Enqueue(const E& e)
{
  s.insert(s.begin(), e);
  n++;
}

template <typename E>
const E& Queue<E>::Front() const throw(QueueEmpty)
{
  if(isEmpty())
    throw QueueEmpty("Front of empty Queue");
  return s[0];
}

template <typename E>
int Queue<E>::size()const{
  return n;
}

template <typename E>
Queue<E>::~Queue()
{
  s.clear();
}
