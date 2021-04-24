// 给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。
// 一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）

function maxSum(root) {
  function dfs(root) {
    if (root == null) return 0;
    else {
      let left = dfs(root.left);
      let right = dfs(root.right);

      let sum = root.val + left + right;
      map.set(sum, map.get(sum) + 1);
      return sum;
    }
  }

  let map = new Map();
  dfs(root);

  let max = 0;

  let key = map.keys();
  for (k of key) {
    let val = map.get(k);
    max = max < val ? val : max;
  }

  return max;
}
