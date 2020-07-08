#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
private:
  char value;
  vector<TreeNode *> nodes;

public:
  TreeNode(char value)
  {
    this->value = value;
    this->nodes.clear();
  }

  char getValue()
  {
    return this->value;
  }

  // 第一位不匹配：返回 false
  // 第一位匹配：
  //            字符串长度为2，true
  //            字符串长度不为2：
  //                            如果有结束标志， true
  //                            无结束标志，继续搜索
  bool search(string target)
  {
    if (this->value != target[0]) // 第一位不匹配
      return false;
    else
    {
      if (target.length() == 2) // 字符结尾字符 + 'e'
        return true;
      else
      {
        for (int i = 0; i < this->nodes.size(); i++)
        {
          if (this->nodes[i]->getValue() == 'e' || this->nodes[i]->search(target.substr(1, target.length() - 1)))
            return true;
        }
        return false;
      }
    }
    return false;
  }

  // 在当前节点下插入 tar
  void insert(string tar)
  {
    // cout << tar << endl;
    if (tar.length() == 0) // 长度为0，代表结束
    {
      return;
    }
    for (int i = 0; i < this->nodes.size(); i++)
    {
      if (this->nodes[i]->getValue() == tar[0])
      {
        this->nodes[i]->insert(tar.substr(1, tar.length() - 1)); // 找到了对应的子节点
        return;
      }
      else
        continue;
    }
    // 没有找到对应的子节点
    TreeNode *temp = new TreeNode(tar[0]);
    this->nodes.push_back(temp);
    this->nodes[nodes.size() - 1]->insert(tar.substr(1, tar.length() - 1));
    return;
  }

  void clear()
  {
    for (int i = 0; i < this->nodes.size(); i++)
      this->nodes[i]->clear();
    this->nodes.clear();
  }

  // 测试用的
  void dfs()
  {
    if (this->nodes.size() == 0)
    {
      cout << this->value << ' ';
      return;
    }
    else
    {
      cout << this->value << ' ';
      for (int i = 0; i < this->nodes.size(); i++)
        this->nodes[i]->dfs();
    }
  }

  ~TreeNode()
  {
    this->clear();
  }
};

int main()
{
  int loop;
  cin >> loop;
  for (int i = 0; i < loop; i++)
  {
    int numbers;
    cin >> numbers;
    string phone;
    TreeNode tree('0'); // 手动构造一个字典树的头
    bool flag = false;  // 代表是否存在前缀
    for (int j = 0; j < numbers; j++)
    {
      cin >> phone;
      // cout << phone << endl;
      if (j != 0 && tree.search("0" + phone + "e") && !flag)
        flag = true;
      else if (!flag)
        tree.insert(phone + "e");
    }
    // tree.dfs();
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}