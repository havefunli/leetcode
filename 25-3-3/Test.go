/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    if root == nil {
        return root
    }
    if root == p || root == q {
        return root
    }

    left := lowestCommonAncestor(root.Left, p, q)
    right := lowestCommonAncestor(root.Right, p, q)

    if left != nil && right != nil {
        return root
    } else if right == nil && left != nil {
        return left
    } else {
        return right
    }
}


func getMedal(i int) string {
    switch i {
    case 0:
        return "Gold Medal"
    case 1:
        return "Silver Medal"
    case 2:
        return "Bronze Medal"
    default:
        return strconv.Itoa(i + 1)
    }
}

func findRelativeRanks(score []int) []string {
    // 对数组排序
    scoreCopy := append([]int(nil), score...)
    slices.SortFunc(scoreCopy, func(i, j int) int {
        return cmp.Compare(j, i) })
    // 映射关系
    mp := make(map[int]int)
    for i, v := range scoreCopy {
        mp[v] = i
    }

    ans := []string{}
    for _, v := range score {
        ans = append(ans, getMedal(mp[v]))
    }
    return ans
}