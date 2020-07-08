#include <iostream>

using namespace std;

class TreeNode
{
private:
  int value;
  TreeNode *leftNode;
  TreeNode *rightNode;

public:
  TreeNode()
  {
    this->value = 0;
    this->leftNode = nullptr;
    this->rightNode = nullptr;
  }

  TreeNode(int value)
  {
    this->value = value;
    this->leftNode = nullptr;
    this->rightNode = nullptr;
  }

  // 插入节点
  bool insert(int value)
  {
    if (this->value < value)
    {
      if (this->leftNode == nullptr)
      {
        TreeNode *temp = new TreeNode(value);
        this->leftNode = temp;
        return true;
      }
      else
      {
        this->leftNode->insert(value);
        return true;
      }
    }
    else
    {
      if (this->rightNode == nullptr)
      {
        TreeNode *temp = new TreeNode(value);
        this->rightNode = temp;
        return true;
      }
      else
      {
        this->rightNode->insert(value);
        return true;
      }
    }

    return false;
  }

  bool traversal(int mode)
  {
    if (this == nullptr)
      return true;
    else
    {
      switch (mode)
      {
      case 0: // inorder
      {
        this->rightNode->traversal(0);
        cout << this->value << ' ';
        this->leftNode->traversal(0);
        return true;
      }
      case 1: // preorder
      {
        cout << this->value << ' ';
        this->rightNode->traversal(1);
        this->leftNode->traversal(1);

        return true;
      }
      case 2: //postorder
      {
        this->rightNode->traversal(2);
        this->leftNode->traversal(2);
        cout << this->value << ' ';
        return true;
      }
      default:
        return false;
      }
    }
  }

  bool clear()
  {
    if (this->leftNode == nullptr && this->rightNode == nullptr) // 此节点为最底层节点
    {
      return true;
    }
    else
    {
      if (this->leftNode != nullptr && this->leftNode->clear())
        this->leftNode = nullptr;
      if (this->rightNode != nullptr && this->rightNode->clear())
        this->rightNode = nullptr;
      return true;
    }
  }

  ~TreeNode()
  {
    this->clear();
  }
};

int main()
{
  while (1)
  {
    int n = 0;
    bool flag = true; // 循环终止条件
    cin >> n;
    if (n == 0)
      break;
    else
    {
      int m = 0;
      cin >> m;
      TreeNode tree(m);
      n--;
      while (n--)
      {
        cin >> m;
        tree.insert(m);
      }
      cout << "Inorder: ";
      tree.traversal(0);
      cout << endl;
      cout << "Preorder: ";
      tree.traversal(1);
      cout << endl;
      cout << "Postorder: ";
      tree.traversal(2);
      cout << endl;
      // tree.clear();
    }
  }
  cout << "Inorder: "
       << endl
       << "Preorder: " << endl
       << "Postorder: " << endl;

  return 0;
}

/*
8 8 2 4 7 5 3 1 6
9 5 5 6 3 2 9 3 3 2
8 4 2 1 4 3 2 5 1
0
*/