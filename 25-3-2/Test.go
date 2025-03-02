type RecentCounter struct {
    queue []int
}


func Constructor() RecentCounter {
    return RecentCounter{
        queue: []int{},
    }
}


func (this *RecentCounter) Ping(t int) int {
    this.queue = append(this.queue, t)
    for i, v := range this.queue {
        if v >= t - 3000 {
            this.queue = this.queue[i:]
            break
        }
    }
    return len(this.queue)
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */


 func dfs(grid [][]byte, i, j int) {
    if i < 0 || i >= len(grid) || j < 0 || j >= len(grid[0]) {
        return
    }

    if grid[i][j] != '1' {
        return
    }

    grid[i][j] = '2'
    dfs(grid, i - 1, j)
    dfs(grid, i + 1, j)
    dfs(grid, i, j - 1)
    dfs(grid, i, j + 1)
}


func numIslands(grid [][]byte) int {
    ans := 0
    for i :=0; i < len(grid); i += 1 {
        for j := 0; j < len(grid[0]); j += 1 {
            if grid[i][j] == '1' {
                ans += 1
                dfs(grid, i, j)
            }
        }
    }
    return ans
}