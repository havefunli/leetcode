func timeRequiredToBuy(tickets []int, k int) int {
    n := len(tickets)

    cnt := 0
    for i := 0; i < n; i += 1 {
        if i <= k {
            cnt += min(tickets[i], tickets[k])
        } else {
            cnt += min(tickets[i], tickets[k] - 1)
        }
    }
    return cnt
}

func CheckPermutation(s1 string, s2 string) bool {
    b1, b2 := []byte(s1), []byte(s2)
    slices.Sort(b1)
    slices.Sort(b2)
    return string(b1) == string(b2)
}