func generate(numRows int) [][]int {
    ans := make([][]int, numRows)
    for i := range ans {
        ans[i] = make([]int, i + 1)
        
        ans[i][0] = 1
        ans[i][i] = 1
        for j := 1; j < i; j += 1 {
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1]
        }
    }
    return ans
}

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func invertTree(root *TreeNode) *TreeNode {
    if root == nil {
        return root
    }

    root.Left, root.Right = root.Right, root.Left
    invertTree(root.Left)
    invertTree(root.Right)
    return root
}